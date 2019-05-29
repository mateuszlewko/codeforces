from random import randint

n = 100 
k = 21
print(n, k)

M = 20

for _ in range(n):
  x = randint(0, M)
  y = randint(x + 1, M)

  print(x, y)
