#include <iostream>

int main() {

    const int max = 1000001;
    int cases;
    std::cin >> cases;

    int room[max] = {0};

    for(int i = 0; i < cases; ++i) {
        std::cin >> room[i];
    }

    int capA, capB;
    std::cin >> capA;
    std::cin >> capB;

    int sum = 0;
    if(capA < capB) {
        room[i
    }
    for(int i = 0; i < cases; ++i) {
        sum++;
        if(room[i] - capA > 0) {
            if(capB > 0) {
                sum += (int)((float)(room[i] - capA) / capB);
                if((room[i] - capA) % capB != 0) {
                    sum++;
                }
            } else {
                sum--;
                sum += (int)((float)room[i] / capA);
                if(room[i] % capA != 0) {
                    ++sum;
                }
            }
        }
    }

    std::cout << sum << std::endl;

    return 0;
}