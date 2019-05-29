def pow(x, n):
  res = 1
  for _ in range(n): res *= x
  return res 

with open('lesson.in') as f:
  line = f.readline().split(' ')
  n, m = list(map(int, line))

  res = pow(2, n) + pow(2, m) - 2

  with open('lesson.out', 'w') as f:
    f.write(str(res) + '\n')