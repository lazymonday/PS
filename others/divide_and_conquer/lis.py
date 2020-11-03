


# lis(i) = 1 + lis(next) where i < next < n and a[i] < a[next]

cache = [-1 for i in range(100)]
choices = [-1 for i in range(100)]

def lis(seq, start):

    if cache[start] != -1:
        return cache[start]

    ret = 1

    for i in range(start, len(seq)):
        if seq[start] < seq[i]:
            candidate = lis(seq, i) + 1
            if candidate > ret:
                ret = candidate
                choices[start] = i

    cache[start] = ret
    return ret



sequences = [50, 3, 10, 7, 40, 80]
length = 0

start_index = 0
for i in range(len(sequences)):
    candidate = lis(sequences, i)
    if candidate > length:
        length = candidate
        start_index = i

i = start_index

while i != -1:
    print(sequences[i], end=' ')
    i = choices[i]
print("\n")

print("length : " + str(length))