#include <iostream>

int t[16];
int p[16];
int n;

int countMax(int startDay, int salary) {
    if (startDay >= n) {
        return salary;
    }

    return std::max(countMax(startDay + t[startDay], startDay + t[startDay] > n ? salary : salary + p[startDay]),
                    countMax(startDay + 1, salary));
}

int main() {

    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        std::cin >> t[i];
        std::cin >> p[i];
    }

    std::cout << countMax(0, 0) << std::endl;
    return 0;
}