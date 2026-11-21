import json, struct, sys, unittest
from pathlib import Path
sys.path.insert(0,str(Path(__file__).parent))
import external_host as h

class ProtocolTests(unittest.TestCase):
    def test_request_crc_and_payload_bytes(self):
        px=bytes(range(17))*3+bytes([0,1,2,3,4,5,6,7,8,9,10,11,12])
        self.assertEqual(len(px),64)
        req=h.make_request(7,123,'adaptive',px)
        self.assertEqual(len(req),100)
        self.assertEqual(req[:4],b'RTNQ')
        self.assertEqual(req[32:96],px)
        self.assertEqual(struct.unpack_from('<I',req,28)[0],h.crc32(req[:28]))
        self.assertEqual(struct.unpack_from('<I',req,96)[0],h.crc32(px))
    def test_bad_pixels_and_mode_fail_closed(self):
        with self.assertRaises(ValueError): h.make_request(1,1,'fixed2',bytes([17])*64)
        with self.assertRaises(ValueError): h.make_request(1,1,'label',bytes(64))
        with self.assertRaises(ValueError): h.make_request(1,3824,'fixed2',bytes(64))
    def test_response_crc_counter_and_identity(self):
        b=bytearray(60); b[:5]=b'RTNR\x03'; b[5:8]=bytes([0,1,0])
        struct.pack_into('<IHHI',b,8,1,4,65535,123)
        b[20:24]=bytes([2,2,3,255]); struct.pack_into('<QQ',b,24,100,120)
        struct.pack_into('<IIII',b,40,h.MODEL_ID,h.BUILD_ID,h.BINDING_ID,1)
        struct.pack_into('<I',b,56,h.crc32(b[:56]))
        d=h.decode_response(bytes(b)); self.assertEqual(d['cycles_end']-d['cycles_start'],20)
        b[55]^=1
        with self.assertRaisesRegex(ValueError,'CRC'): h.decode_response(bytes(b))
    def test_response_short_and_wrong_version_reject(self):
        with self.assertRaisesRegex(ValueError,'framing'): h.decode_response(bytes(59))
        b=bytearray(60); b[:5]=b'RTNR\x02'
        with self.assertRaisesRegex(ValueError,'framing'): h.decode_response(bytes(b))
    def test_verified_response_rejects_wrap_and_wrong_identity(self):
        b=bytearray(60); b[:5]=b'RTNR\x03'; b[5:8]=bytes([0,3,1])
        struct.pack_into('<IHHI',b,8,7,12,65535,456)
        b[20:24]=bytes([6,2,4,255]); struct.pack_into('<QQ',b,24,200,250)
        struct.pack_into('<IIII',b,40,h.MODEL_ID,h.BUILD_ID,h.BINDING_ID,1)
        struct.pack_into('<I',b,56,h.crc32(b[:56]))
        r=h.decode_response(bytes(b)); case={'mode':'adaptive','seq':'7','input_id':'12','payload_crc32':'456','sof_sha256':'a'*64}
        exp={'prediction':'4','admitted_exit':'6','executed_exit':'2','stop_reason':'entropy'}
        binding={'sof_sha256':'a'*64,'build_id':'45585631'}
        self.assertEqual(h.verify_response(r,case,exp,binding),50)
        b[32:40]=(150).to_bytes(8,'little'); struct.pack_into('<I',b,56,h.crc32(b[:56]))
        with self.assertRaisesRegex(ValueError,'counter'): h.verify_response(h.decode_response(bytes(b)),case,exp,binding)
        binding['build_id']='43334531'
        with self.assertRaisesRegex(ValueError,'binding'): h.verify_response(r,case,exp,binding)

if __name__=='__main__': unittest.main(verbosity=2)
