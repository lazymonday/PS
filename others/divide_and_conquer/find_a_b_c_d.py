

max = 1000
ret = [[-1 for i in range(0, max+1)] for i in range(0, max+1)]

table = {}

def find_abcd_map():

    for a in range(0, max):
        for b in range(a+1, max):
            sum = str(pow(a, 3) + pow(b, 3))
            if sum in table:
                table[sum].append([a, b])
                print(table[sum])
            else:
                table[sum] = []
                table[sum].append([a, b])

def find_abcd(a, b):

    if a < 0 or b > max:
        return False

    for a in range(1, max):
        for b in range(1, max):
            c = a + 1
            d = b

            if ret[a][b] == 0 or ret[b][a] == 0:
                continue

            if ret[a][b] != -1 or ret[b][a] != -1:
                print(ret[a][b])
                continue

            a_b = pow(a, 3) + pow(b, 3)
            while a_b > pow(c, 3):
                if a == d:
                    d = d - 1
                elif a == c:
                    c = c + 1

                c_d = pow(c, 3) + pow(d, 3)
                if a_b > c_d:
                    c = c+1
                    if c > max:
                        c = max-1
                        break
                    continue
                elif a_b < c_d:
                    d = d-1
                    if d < 0:
                        d = 0
                        break
                    continue
                else:
                    print([a,b,c,d])
                    ret[a][b] = [c, d]
                    ret[b][a] = [c, d]
                    ret[c][d] = [a, b]
                    ret[d][c] = [a, b]
                    break

            ret[a][b] = 0
            ret[b][a] = 0
            ret[c][d] = 0
            ret[d][c] = 0


#find_abcd(0, 0)
find_abcd_map()


