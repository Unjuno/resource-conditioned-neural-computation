#!/usr/bin/env python3
"""Export a NEW B experiment ELF into a 256-KiB FPGA M10K image.

Rejects A's 1-MiB linker stack and any B image overlapping the reserved
32-KiB physical stack. Does not certify the RAM implementation or timing.
"""
from __future__ import annotations
import argparse
import hashlib
import json
from pathlib import Path
import struct

BASE=0x00100000
RAM_SIZE=256*1024
CODE_END=BASE+224*1024
STACK_TOP=BASE+RAM_SIZE-16
ENTRY=BASE+128
class InvalidBImage(ValueError):pass

def sha(b:bytes)->str:return hashlib.sha256(b).hexdigest()

def read_symbols(elf:bytes,header:tuple)->dict[str,int]:
    shoff,shentsize,shnum=header
    if shentsize<40 or shoff+shentsize*shnum>len(elf):raise InvalidBImage('section headers invalid')
    secs=[struct.unpack_from('<IIIIIIIIII',elf,shoff+i*shentsize) for i in range(shnum)]
    syms={}
    for sec in secs:
        if sec[1]!=2:continue
        off,sz,link,ent=sec[4],sec[5],sec[6],sec[9]
        if ent<16 or off+sz>len(elf) or link>=len(secs):raise InvalidBImage('symbol table invalid')
        s=secs[link];strings=elf[s[4]:s[4]+s[5]]
        for at in range(off,off+sz,ent):
            n,val,*_=struct.unpack_from('<IIIBBH',elf,at)
            if n<len(strings):
                stop=strings.find(b'\0',n)
                if stop>=0:syms[strings[n:stop].decode(errors='replace')]=val
    return syms

def build(elf:bytes,binary:bytes)->dict:
    if len(elf)<52 or elf[:6]!=b'\x7fELF\x01\x01':raise InvalidBImage('not little-endian ELF32')
    header=struct.unpack_from('<16sHHIIIIIHHHHHH',elf)
    _,etyp,machine,version,entry,phoff,shoff,flags,ehsize,phentsize,phnum,shentsize,shnum,shstrndx=header
    if etyp!=2 or machine!=243 or version!=1 or entry!=ENTRY or phentsize<32:
        raise InvalidBImage('wrong executable architecture/entry')
    if phoff+phnum*phentsize>len(elf):raise InvalidBImage('program header bounds')
    loads=[]
    for i in range(phnum):
        h=struct.unpack_from('<IIIIIIII',elf,phoff+i*phentsize)
        if h[0]==1:loads.append(h)
    if len(loads)!=1:raise InvalidBImage('expected one PT_LOAD for board RAM')
    _,off,va,pa,fs,ms,flags,align=loads[0]
    if va!=BASE or pa!=BASE or fs!=len(binary) or ms<fs or not fs or off+fs>len(elf):
        raise InvalidBImage('invalid load base/size')
    if elf[off:off+fs]!=binary:raise InvalidBImage('BIN differs from ELF PT_LOAD')
    if BASE+ms>CODE_END:raise InvalidBImage('B binary/stack region overlap')
    syms=read_symbols(elf,(shoff,shentsize,shnum))
    if syms.get('__stack_top')!=STACK_TOP:raise InvalidBImage('wrong stack; old A ELF is forbidden')
    if syms.get('__image_end')!=((BASE+ms+15)&~15):raise InvalidBImage('image-end symbol mismatch')
    image=bytearray(RAM_SIZE)
    image[:len(binary)]=binary
    hexwords=''.join(f'{int.from_bytes(image[i:i+4],"little"):08x}\n'
                    for i in range(0,RAM_SIZE,4))
    return {'schema':'rtnn-de0cv-b-firmware-ram-v1',
            'status':'IMAGE_GENERATED_NOT_SYNTHESIZED',
            'elf_sha256':sha(elf),'bin_sha256':sha(binary),
            'image_sha256':sha(image),
            'hex_sha256':sha(hexwords.encode()),
            'base_addr':BASE,'entry':entry,'stack_top':STACK_TOP,
            'load_bytes':fs,'memory_bytes':ms,'ram_bytes':RAM_SIZE,
            'code_limit_bytes':224*1024,'_hex':hexwords,
            'nonclaims':['No FPGA build or validation performed.',
                         'No timing bound is provided. Old Simple System cycle table MUST NOT be imported.']}

def main():
    p=argparse.ArgumentParser()
    p.add_argument('--elf',type=Path,required=True)
    p.add_argument('--bin',type=Path,required=True)
    p.add_argument('--out-dir',type=Path,required=True)
    a=p.parse_args()
    try:r=build(a.elf.read_bytes(),a.bin.read_bytes())
    except (InvalidBImage,ValueError) as e:p.exit(2,f'B_IMAGE_REJECTED: {e}\n')
    a.out_dir.mkdir(parents=True,exist_ok=True)
    (a.out_dir/'rtnn_ram_words.hex').write_text(r.pop('_hex'))
    (a.out_dir/'fpga_b_image_manifest.json').write_text(json.dumps(r,indent=2)+'\n')
    print(r['status'],r['bin_sha256'])
if __name__=='__main__':main()
