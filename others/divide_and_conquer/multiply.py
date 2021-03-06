def normalize(num):
    num.append(0)

    for i in range(len(num)-1):
        if num[i] < 0:
            borrow = abs(num[i] + 9) / 10
            num[i + 1] -= borrow
            num[i] += borrow * 10
        else:
            num[i + 1] += int(num[i] / 10)
            num[i] = num[i] % 10

    while len(num) > 0 and num[-1] == 0:
        num.pop()


def multiply(a, b):
    c = [0 for i in range(len(a)+len(b)+1)]
    for i in range(len(a)):
        for j in range(len(b)):
            c[i + j] += a[i] * b[j]

    normalize(c)
    return c


def reverse_num(num):
    for i in reversed(range(len(num))):
        print(num[i], end='')
    print('\n')


a = [4, 3, 2, 1]
b = [8, 7, 6, 5]

c = multiply(a, b)
reverse_num(c)
