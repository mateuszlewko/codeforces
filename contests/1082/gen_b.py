from random import randrange

n = randrange(2, 1000)

print(n)
for _ in range(n):
    print('S' if randrange(0, 2) == 1 else 'G', end='')
print()