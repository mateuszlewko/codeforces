data = input()
from itertools import permutations

letters = set()

for c in data:
    if (c >= 'a' and c <= 'z') or (c >= 'A' and c <= 'Z'):
        letters.add(c)

def check(x): 
    # print('testing', x)

    if x.count('=') != 1: return False
    if '**' in x: return False 
    if '++' in x: return False
    if '-+' in x: return False
    if '-*' in x: return False
    if '*+' in x: return False
    if '+*' in x: return False
    if '=+' in x: return False
    if '(+' in x: return False
    if '0b00' in x: return False 
    if '0b01' in x: return False
    if '()' in x: return False
            
    if x.startswith('+'): return False 

    lopen = 0
    for c in x:
        if c == '=':
            if lopen != 0: return False
            break
        elif c == '(': lopen += 1
        elif c == ')': lopen -= 1

    x = x.replace('=', '==')

    # print('final:', x)
    try:
        return eval(x)
    except:
        return False

if len(letters) > 8:
    print(0)
    exit(0)

res = set() 
for p in permutations(sorted('=+-*01()')):
    mapping = {}
    for c, l in zip(letters, p[:len(letters)]):
        mapping[c] = l

    s = ""
    prev_num = False
    for c in data:
        c = mapping.get(c, c)
        if c in ('0', '1') and not prev_num:
            prev_num = True
            s += '0b' + c
        elif c in ('0', '1'):
            s += c 
        else:
            prev_num = False 
            s += c


    if check(s) == True:
        res.add(s)

# print(list(map(lambda x : x.replace('0b', ''), res)))
# print(res)
print(len(res))