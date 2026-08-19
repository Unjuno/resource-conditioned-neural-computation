import argparse,json,struct,subprocess
from pathlib import Path

MEMSZ=8*1024*1024; WS=0x100000; INP=0x102000; OUT=0x103000; STACK=0x700000

def sx(v,b):m=1<<(b-1);return (v^m)-m
def u32(x):return x&0xffffffff
def s32(x):x&=0xffffffff;return x-0x100000000 if x&0x80000000 else x

def load_elf(path):
 raw=Path(path).read_bytes();assert raw[:4]==b'\x7fELF' and raw[4]==1 and raw[5]==1
 mem=bytearray(MEMSZ);ph=struct.unpack_from('<I',raw,28)[0];psz=struct.unpack_from('<H',raw,42)[0];pn=struct.unpack_from('<H',raw,44)[0]
 for i in range(pn):
  typ,off,va,_,fs,_,_,_=struct.unpack_from('<IIIIIIII',raw,ph+i*psz)
  if typ==1:mem[va:va+fs]=raw[off:off+fs]
 syms={}
 for ln in subprocess.check_output(['nm','-n',str(path)],text=True).splitlines():
  p=ln.split()
  if len(p)>=3:
   try:syms[p[2]]=int(p[0],16)
   except ValueError:pass
 return mem,syms

def emulate(base,syms,pixels,cls):
 mem=bytearray(base);mem[INP:INP+64]=bytes(pixels);r=[0]*32;r[1]=0;r[2]=STACK;r[10]=WS;r[11]=INP;r[12]=cls;r[13]=OUT;pc=syms['rtnn_fixed_certify_class']
 c={'inst':0,'branch':0,'jump':0,'load':0,'store':0,'mul':0,'mul_high':0}
 rd=lambda a:mem[a]|mem[a+1]<<8|mem[a+2]<<16|mem[a+3]<<24
 def wr(a,v):v&=0xffffffff;mem[a]=v&255;mem[a+1]=v>>8&255;mem[a+2]=v>>16&255;mem[a+3]=v>>24&255
 while pc:
  ins=rd(pc);op=ins&127;d=ins>>7&31;f3=ins>>12&7;s1=ins>>15&31;s2=ins>>20&31;f7=ins>>25;a=r[s1];b=r[s2];np=u32(pc+4);val=None;c['inst']+=1
  if op==0x37:val=ins&0xfffff000
  elif op==0x17:val=u32(pc+(ins&0xfffff000))
  elif op==0x6f:
   im=((ins>>31)&1)<<20|((ins>>12)&255)<<12|((ins>>20)&1)<<11|((ins>>21)&1023)<<1;val=np;np=u32(pc+sx(im,21));c['jump']+=1
  elif op==0x67:val=np;np=u32((a+sx(ins>>20,12))&~1);c['jump']+=1
  elif op==0x63:
   im=((ins>>31)&1)<<12|((ins>>7)&1)<<11|((ins>>25)&63)<<5|((ins>>8)&15)<<1;im=sx(im,13)
   take={0:a==b,1:a!=b,4:s32(a)<s32(b),5:s32(a)>=s32(b),6:u32(a)<u32(b),7:u32(a)>=u32(b)}[f3]
   if take:np=u32(pc+im)
   c['branch']+=1
  elif op==0x03:
   ad=u32(a+sx(ins>>20,12));val=rd(ad) if f3==2 else mem[ad];c['load']+=1
  elif op==0x23:
   im=sx((ins>>25)<<5|((ins>>7)&31),12);ad=u32(a+im)
   if f3==2:wr(ad,b)
   elif f3==0:mem[ad]=b&255
   else:raise RuntimeError(('store',f3,hex(pc)))
   c['store']+=1
  elif op==0x13:
   im=sx(ins>>20,12)
   if f3==0:val=u32(a+im)
   elif f3==2:val=int(s32(a)<im)
   elif f3==3:val=int(u32(a)<u32(im))
   elif f3==4:val=u32(a^im)
   elif f3==6:val=u32(a|im)
   elif f3==7:val=u32(a&im)
   elif f3==1:val=u32(a<<((ins>>20)&31))
   elif f3==5:val=u32(s32(a)>>((ins>>20)&31)) if (ins>>30)&1 else u32(a>>((ins>>20)&31))
   else:raise RuntimeError(('opimm',f3,hex(pc)))
  elif op==0x33:
   if f7==1:
    if f3==0:val=u32(s32(a)*s32(b));c['mul']+=1
    elif f3==1:val=u32((s32(a)*s32(b))>>32);c['mul_high']+=1
    elif f3==2:val=u32((s32(a)*u32(b))>>32);c['mul_high']+=1
    elif f3==3:val=u32((u32(a)*u32(b))>>32);c['mul_high']+=1
    else:raise RuntimeError(('mul',f3,hex(pc)))
   else:
    sh=b&31
    if f3==0:val=u32(a-b) if f7==0x20 else u32(a+b)
    elif f3==1:val=u32(a<<sh)
    elif f3==2:val=int(s32(a)<s32(b))
    elif f3==3:val=int(u32(a)<u32(b))
    elif f3==4:val=u32(a^b)
    elif f3==5:val=u32(s32(a)>>sh) if f7==0x20 else u32(a>>sh)
    elif f3==6:val=u32(a|b)
    elif f3==7:val=u32(a&b)
    else:raise RuntimeError(('op',f3,hex(pc)))
  else:raise RuntimeError(('opcode',hex(op),hex(pc)))
  if val is not None and d:r[d]=u32(val)
  r[0]=0;pc=np
 # Conditional RTNN-IBEX-DIT-v1 envelope. See note for assumptions.
 c['cycle_envelope']=c['inst']+c['branch']+c['jump']+2*c['load']+c['store']+c['mul_high']+4
 c['logits']=[s32(rd(OUT+4*i)) for i in range(10)]
 return c

def samples():
 from sklearn.datasets import load_digits
 from sklearn.model_selection import train_test_split
 d=load_digits();X=d.images.astype('uint8');Y=d.target;idx=list(range(len(X)));_,tmp=train_test_split(idx,test_size=.4,random_state=123,stratify=Y);_,te=train_test_split(tmp,test_size=.5,random_state=456,stratify=Y[tmp]);return [X[te[i]].reshape(-1).tolist() for i in [0,17,123,359]]

def main():
 ap=argparse.ArgumentParser();ap.add_argument('elf');ap.add_argument('--out',default='results/realtime_nn_rv32_cycle_envelope.json');a=ap.parse_args();base,syms=load_elf(a.elf);ss=samples();rows=[]
 for cls in range(7):
  rr=[emulate(base,syms,p,cls) for p in ss];keys=['inst','branch','jump','load','store','mul','mul_high','cycle_envelope'];same=all(all(x[k]==rr[0][k] for k in keys) for x in rr);rows.append({'class':cls,'counts':{k:rr[0][k] for k in keys},'four_input_counts_identical':same})
 out={'model':'RTNN-IBEX-DIT-v1 conditional processor model','classes':rows};Path(a.out).write_text(json.dumps(out,indent=2));print(json.dumps(out,indent=2))
if __name__=='__main__':main()
