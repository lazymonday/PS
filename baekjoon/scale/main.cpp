#include <iostream>

int main() {

    int nums[8];
    int dt[7] = {0};
    int prev = -1;
    bool mixed = false;
    for (int i = 0; i < 8; ++i) {
        std::cin >> nums[i];
        if (prev != -1) {
            dt[i - 1] = nums[i] - prev;
            if (i - 2 >= 0) {
                if(dt[i-1] != dt[i-2]) {
                    mixed = true;
                }
            }
        }

        prev = nums[i];
    }

    if(mixed) {
        std::cout << "mixed" << std::endl;
    } else {
        std::cout << (dt[0] == 1 ? "ascending" : "descending") << std::endl;
    }


    return 0;
}