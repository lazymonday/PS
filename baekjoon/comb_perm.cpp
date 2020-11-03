#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6;
const int INF = 1e9;
typedef long long ll;

vector<int> arr;

void perm(vector<int>& arr, int r, vector<int>& chosen, vector<int>& taken) {

    if (chosen.size() == r) {

        for (auto v : chosen) {
            cout << v << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < arr.size(); ++i)
    {
        if (taken[i] || (i != 0 && arr[i-1] == arr[i] && !taken[i-1])) continue;
        taken[i] = true;
        chosen.push_back(arr[i]);
        perm(arr, r, chosen, taken);
        chosen.pop_back();
        taken[i] = false;
    }
}

void comb(vector<int>& arr, int r, vector<int>& chosen, vector<int>& taken, int lastPicked) {

    if (chosen.size() == r) {

        for (auto v : chosen) {
            cout << v << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = lastPicked; i < arr.size(); ++i)
    {
        if (taken[i]) continue;
        taken[i] = true;
        chosen.push_back(arr[i]);
        comb(arr, r, chosen, taken, i + 1);
        chosen.pop_back();
        taken[i] = false;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);

    vector<int> chosen;
    vector<int> taken(arr.size());
    perm(arr, 2, chosen, taken);

    return 0;
}
