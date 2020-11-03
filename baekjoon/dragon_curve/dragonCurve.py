import sys

dp = [0 for _ in range(250 + 1)]


def tiling2():
    for i in range(3, 251):
        dp[i] = dp[i - 1] + dp[i - 2] * 2


dp[0] = 1
dp[1] = 1
dp[2] = 3

tiling2()

try:
    while True:
        n = int(input())
        print(dp[n])
except EOFError:
    exit()
