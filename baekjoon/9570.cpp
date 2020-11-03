#include <bits/stdc++.h>

using namespace std;

const int MAX = 100;
const int INF = 1e9;
typedef long long ll;

int n, k;
int adj_cnt;
vector<string> adj[33];
vector<string> origin[105];
int sub[33];

int calc_sub(int start) {
    auto& ret = sub[start];
    if(ret != -1) {
        return ret;
    }
    ret = 1;
    for (int i = start; i < adj_cnt; ++i) ret *= adj[i].size();
    return ret;
}

int calc_kth(vector<string>& ad) {
    int ret = 1;
    for (int i = 0; i < ad.size(); ++i)
    {
        int dist = lower_bound(adj[i].begin(), adj[i].end(), ad[i]) - adj[i].begin();
        auto x = calc_sub(i + 1) * dist;
        ret += x;
    }

    return ret;
}

int count_less(int pp) {
    int ret = 0;
    for (int i = 0; i < n; ++i)
    {
        if (pp >= calc_kth(origin[i])) ++ret;
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s >> s >> s >> s;
        int pos = 0;
        while (true) {
            cin >> s;
            if (s == "cow.") break;
            adj[pos].push_back(s);
            origin[i].push_back(s);
            ++pos;
        }
        adj_cnt = pos;
    }

    for (int i = 0; i < adj_cnt; ++i) {
        sort(adj[i].begin(), adj[i].end());
        adj[i].resize(unique(adj[i].begin(), adj[i].end()) - adj[i].begin());
    }

    memset(sub, -1, sizeof sub);
    int pos = k;
    while (k > pos - count_less(pos)) pos++;

    pos--;

    vector<string> ans;
    for (int i = adj_cnt - 1; i >= 0; --i)
    {
        ans.push_back(adj[i][pos % adj[i].size()]);
        pos /= adj[i].size();
    }

    while (!ans.empty()) {
        cout << ans.back() << " ";
        ans.pop_back();
    }

    return 0;
}
