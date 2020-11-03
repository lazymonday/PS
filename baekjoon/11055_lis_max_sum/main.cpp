#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1001;
int n;
int dp[MAX];
int nums[MAX];


int lis() {

    int answer = 0;
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                sum = max(sum, dp[j]);
            }
        }

        dp[i] = sum + nums[i];
        answer = max(answer, dp[i]);
    }

    return answer;
}


int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cout << lis() << "\n";

    return 0;
}
