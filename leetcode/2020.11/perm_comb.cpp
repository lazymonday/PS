#include <bits/stdc++.h>

using namespace std;

void unique_permutation(vector<int>& a, int n, vector<bool>& taken, vector<int>& selected) {
    if (selected.size() == n) {
        for (auto x : selected) cout << x << " ";
        cout << "\n";
        return;
    }

    for (int i = 0; i < a.size(); ++i) {
        if(i > 0 and a[i] == a[i-1] and !taken[i-1]) continue;
        if (taken[i]) continue;
        taken[i] = true;
        selected.push_back(a[i]);
        unique_permutation(a, n, taken, selected);
        selected.pop_back();
        taken[i] = false;
    }
}



void permutation(vector<int>& a, int n, vector<bool>& taken, vector<int>& selected) {
    if (selected.size() == n) {
        for (auto x : selected) cout << x << " ";
        cout << "\n";
        return;
    }

    for (int i = 0; i < a.size(); ++i) {
        if (taken[i]) continue;
        taken[i] = true;
        selected.push_back(a[i]);
        permutation(a, n, taken, selected);
        selected.pop_back();
        taken[i] = false;
    }
}

void comb(vector<int>& a, int n, vector<bool>& taken, vector<int>& selected, int last) {
    if (selected.size() == n) {
        for (auto x : selected) cout << x << " ";
        cout << "\n";
        return;
    }

    for (int i = last + 1; i < a.size(); ++i) {
        if (taken[i]) continue;
        taken[i] = true;
        selected.push_back(a[i]);
        comb(a, n, taken, selected, i);
        selected.pop_back();
        taken[i] = false;
    }
}

void nextPerm(int start, vector<int>& a) {
    if (start == a.size() - 1) {
        for (auto x : a) cout << x << " ";
        cout << "\n";
        return;
    }

    for (int i = start; i < a.size(); ++i) {
        if (i == start || a[i] != a[start]) {
            swap(a[i], a[start]);
            nextPerm(start + 1, a);
        }
    }
}


int main() {
    vector<int> nums({1, 1, 3});
    vector<bool> taken(nums.size(), false);
    vector<int> selected;

    // permutation(nums, 3, taken, selected);
    // comb(nums, 2, taken, selected, -1);
    // nextPerm(0, nums);
    unique_permutation(nums, 3, taken, selected);
    return 0;
}