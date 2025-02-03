a, b = 0, 1
N = int(input()) + 1

for i in range(0, N-1):
    c = b
    b = a + c
    a = c
    
print(a)