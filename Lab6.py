import  math
def factorial(x):
    if x!=0:
        return x*factorial(x-1)
    else:
        return 1


result = lambda n, x: ((-1) ** n * x ** (2 * n + 1)) / factorial(2 * n + 1)


def sine_x(x, n):
    pi = math.pi
    x = x * (pi / 180)
    t = 0
    for i in range(n):
        t += result(i, x)
    return t


total = 0


def function(n):
    global total
    if n == 1:
        total += 1
    else:
        function(n - 1)
        total += 1 / n
