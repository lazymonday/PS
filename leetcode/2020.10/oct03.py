class Calculator:
    def __init__(self):
        self.value = 0

    def add(self, val):
        self.value += val

class UpgradeCalculator(Calculator):
    def minus(self, val):
        self.value -= val;

class MaxLimitCalculator(Calculator):
    def add(self, val):
        self.value += val;
        self.value = min(self.value, 100);

cal = UpgradeCalculator()
cal.add(10)
cal.minus(7)

print(cal.value) # 10에서 7을 뺀 3을 출력

cal = MaxLimitCalculator()
cal.add(50) # 50 더하기
cal.add(60) # 60 더하기

print(cal.value) # 100 출력

print(all([1, 2, abs(-3)-3]))
print(chr(ord('a')) == 'a')

print(list(filter(lambda x : x >= 0, [1, -2, 3, -5, 8, -3])))

print(int(hex(234), 16))

print(list(map(lambda x : x * 3, [1, 2, 3, 4])))
a = [-8, 2, 7, 5, -3, 5, 0, 1]
print(min(a))
print(max(a))

print("%.4f" % (17/3))

import sys

sz = len(sys.argv)
total = 0
for val in range(1, sz):
    total += val
print(total)

import time
print(time.asctime(time.localtime(time.time())))

import os
print(os.getcwd())
print(os.getcwd())

import glob
print(glob.glob("*.py"))


import random

picked = set()
while len(picked) < 6:
    picked.add(random.randint(1,45))

print(picked)