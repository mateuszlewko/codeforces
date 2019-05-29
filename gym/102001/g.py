def k_po_i(k, i):
  top = 1
  for j in range(1, k + 1): top *= j

  down = 1
  for j in range(1, i + 1): down *= j
  
  for j in range(1, k - i + 1): down *= j

  # print(top, down)
  return top // down

def pow(k, n):
  res = 1
  for i in range(n): res *= k

  return res

# print(k_po_i(3, 2))
# print(k_po_i(4, 1))
# print(k_po_i(4, 2))

with open('vasya.in', 'r') as f:
  a, b, k = list(map(int, f.readline().split(' ')))
  
  sum = 0
  for i in range(k + 1): 
    sum += k_po_i(k, i) * pow(a, i) * pow(b, k - i)

  with open('vasya.out', 'w') as fo:
    fo.write(str(sum) + '\n')
    fo.flush()
    