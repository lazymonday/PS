#include <iostream>
#include <algorithm>

using namespace std;
const int MAX = 1001;
int box[MAX];
int dp[MAX];
int n;

int main() {

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> box[i];
    }

    int answer = 0;
    for (int j = 0; j < n; ++j) {
        int here = 0;
        for (int i = 0; i < j; ++i) {
            if (box[j] > box[i]) {
                here = max(here, dp[i]);
            }
        }

        dp[j] = here + 1;
        answer = max(answer, dp[j]);
    }

    cout << answer << "\n";

    return 0;
}
