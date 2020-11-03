#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> partialStringTable(string h) {

    int n = h.size();
    int begin = 1;
    int matched = 0;
    vector<int> pi(n, 0);

    while (begin + matched < n) {
        if (h[begin + matched] == h[matched]) {
            matched++;
            pi[begin + matched - 1] = matched;
        } else {
            if (matched == 0) {
                ++begin;
            } else {
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }

    return pi;
}

int main() {

    string input;
    cin >> input;

    int maxVal = -987654321;
    for(int i = 0; i < input.size(); ++i) {
        auto pi = partialStringTable(input.substr(i));
        for (auto itr = pi.begin(); itr != pi.end(); ++itr) {
            maxVal = max(*itr, maxVal);
        }
    }


    cout << maxVal << endl;

    return 0;
}
