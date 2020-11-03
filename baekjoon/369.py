
def MultipleOf3and5(num:int) -> int:
    total = 0
    for i in range(num):
        if i % 3 == 0 or i % 5 == 0:
            total += i

    return total


print(MultipleOf3and5(1000))

def getTotalPage(m, n):
    return ((m-1) // n) + 1

print(getTotalPage(0, 10))
print(getTotalPage(15, 10))
print(getTotalPage(25, 10))
print(getTotalPage(30, 10))