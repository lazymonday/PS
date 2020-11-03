#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 32000;
int n, m;
vector<int> adj[MAX+1];
int in[MAX+1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    int x, y;
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        adj[x].push_back(y);
        in[y]++;
    }

    priority_queue<int> pq;     // min heap

    for (int j = 1; j <= n; ++j) {
        if(!in[j]) pq.push(-j);
    }

    vector<int> orders;
    while(!pq.empty()) {
        auto u = -pq.top();
        orders.push_back(u);
        pq.pop();
        for (int i = 0; i < adj[u].size(); ++i) {
            auto v = adj[u][i];
            if(--in[v] == 0) {
                pq.push(-v);
            }
        }
    }

    for (int k = 0; k < orders.size(); ++k) {
        cout << orders[k] << " ";
    }

    return 0;
}
