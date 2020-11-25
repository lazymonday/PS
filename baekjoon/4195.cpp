#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e5+5;

int root[MAX];
int cnt[MAX];

int find(int p) {
    if(root[p] == 0) return p;
    return root[p] = find(root[p]);
}

bool uni(int p, int q) {
    p = find(p);
    q = find(q);

    if(p == q) return false;

    root[p] = q;
    cnt[q] += cnt[p];
    return true;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int cases;
    cin >> cases;
    while(cases--) {
        int n;
        cin >> n;

        unordered_map<string, int> id;
        memset(root, 0, sizeof root);
        for(int i = 0; i <= 2*n; ++i) cnt[i] = 1;
        int serial = 0;

        for(int i = 0; i < n; ++i) {
           string fa, fb;
           cin >> fa >> fb;

           if(!id.count(fa)) id[fa] = ++serial;
           if(!id.count(fb)) id[fb] = ++serial;

           uni(id[fa], id[fb]);
           cout << cnt[find(id[fa])] << "\n";
        } 
    }
    
 
    return 0;
}