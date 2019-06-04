def tp_size(t):
  if t[0] in ("bool", "char"): return 1
  if t[0] == "__int128": return 16
  if t[0] == "long" and t[1] == "long": return 8
  if t[0] == "int": return 4
  if t[0] == "float": return 4
  if t[0] == "double": return 8
  if t[0] == "long" and t[1] == "double": return 16
  

def arr_size(s):
  if '[' not in s: return 1
  pos = 0

  for i in range(len(s)): 
    if s[i] == '[': 
      pos = i
      break
  
  return int(s[pos + 1: -2])

# print(arr_size('annama_asas_as[12102];'))
# print(arr_size('annama_asas_as[3];'))
# print(tp_size(["long", "double"]))
# print(tp_size(["long", "long"]))
# print(tp_size(["__int128"]))

def solve(tc):
  ns = input()
  # print('ns', ns)

  n = int(ns)
  total_b = 0

  for i in range(n):
    line = input().split(' ')
    last = line[-1]
    tp = line[:-1]

    sz = tp_size(tp)
    ar = arr_size(last)

    total_b += sz * ar

  res = (total_b + 1023) // 1024
  print('Case #' + str(tc) + ': ' + str(res))

t = int(input())
for i in range(t):
  solve(i + 1)