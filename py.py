#SOME TYPES OPERATIONS
'''
char chr() ord()
byte bytes.fromhex() .hex()
base64 base64.b64encode()
bytes bytes_to_long() long_to_bytes()
'''

#REQUESTS

#PWNTOOLS
'''
xor(a,b)
'''
#test
'''
s = requests.Session()

s.get('https://httpbin.org/cookies/set/sessioncookie/123456789')
r = s.get('https://httpbin.org/cookies')

print(r.text)
# '{"cookies": {"sessioncookie": "123456789"}}'
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

