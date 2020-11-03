#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int n, m;
    scanf("%d", &n);
    vector<int> numbers(n, 0);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &numbers[i]);
    }

    sort(numbers.begin(), numbers.end());

    scanf("%d", &m);
    vector<int> queries(m, 0);
    for (int i = 0; i < m; ++i) {
        scanf("%d", &queries[i]);
    }

    for (int j = 0; j < m; ++j) {
        printf("%d\n", binary_search(numbers.begin(), numbers.end(), queries[j]) ? 1 : 0);
    }

    return 0;
}
