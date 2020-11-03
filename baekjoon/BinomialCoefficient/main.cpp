#include <iostream>

using namespace std;
int n, r;
int divisor = 10007;

int cache[1001][1001];

int choice(int tried, int choose) {

    if (cache[tried][choose] != -1) {
        return cache[tried][choose];
    }

    if (tried >= n) {
        if (choose == r) {
            return 1;
        }

        return 0;
    }

    int sum = (choice(tried + 1, choose + 1)) % divisor;
    sum += (choice(tried + 1, choose)) % divisor;

    cache[tried][choose] = sum % divisor;
    return cache[tried][choose];
}


int main() {

    cin >> n >> r;
    for (int i = 0; i < n + 1; ++i) {
        for (int j = 0; j < n + 1; ++j) {
            cache[i][j] = -1;
        }
    }

    cout << choice(0, 0) << endl;
    return 0;
}
