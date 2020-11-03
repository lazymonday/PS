#include <vector>
#include <algorithm>
#include <stdio.h>
#include <queue>

using namespace std;
static const int maxSize = 10001;
static const int INF = 987654321;
int n, m;
typedef pair<int, pair<int, int>> line;
vector<int> dist(maxSize, INF);
vector<int> visited(maxSize, false);
vector<int> parent(maxSize, -1);
vector<pair<int, int>> edges[100001];
vector<pair<int, int>> q;

void visit(int u) {
    visited[u] = true;

    for (int i = 0; i < edges[u].size(); ++i) {
        int v = edges[u][i].first;
        int cost = edges[u][i].second;

        if (visited[v]) {
            continue;
        }

        if (dist[v] > cost) {
            dist[v] = cost;
            parent[v] = u;

            bool findAndChange = false;
            for (auto &item : q) {
                if (item.first == cost && item.second == v) {
                    item.first = cost;
                    item.second = u;
                    findAndChange = true;
                    break;
                }
            }

            if (!findAndChange) {
                q.emplace_back(cost, v);
            }
        }
    }
}

void lazyVisit(int u, vector<bool>& visited, priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> &pq) {
    if(visited[u]) {
        return;
    }

    visited[u] = true;
    for (auto iter = edges[u].begin(); iter != edges[u].end(); ++iter) {
        if(visited[iter->first]) {
            continue;
        }

        pq.push({iter->second, {u, iter->first}});
    }
}

int lazyPrim() {

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;  // only crossing edge
    vector<bool> visited(1001, false);
    vector<pair<int, int>> mst;

    pq.push({0, {1, 1}});

    int totalCost = 0;
    while (!pq.empty()) {
        auto edge = pq.top();
        pq.pop();
        int cost = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        if (visited[u] && visited[v]) {
            continue;
        }

        mst.emplace_back(u, v);
        totalCost += cost;
        lazyVisit(u, visited, pq);
        lazyVisit(v, visited, pq);
    }

    return totalCost;
}

int eagerPrim() {
    int totalCost = 0;
    dist[1] = 0;
    parent[1] = 1;
    visit(1);
    while (!q.empty()) {
        // find min index
        int u = 0;
        for (int i = 0; i < q.size(); ++i) {
            if (q[u].first > q[i].first) {
                u = i;
            }
        }

        visit(q[u].second);
        q.erase(q.begin() + u);
    }

    for (int j = 1; j <= n; ++j) {
        //printf("%d -> %d\n", j, parent[j]);
        totalCost += dist[j];
    }

    return totalCost;
}

int main() {

    scanf("%d\n%d", &n, &m);

    int s, t, cost;
    for (int i = 1; i <= m; ++i) {
        scanf("%d %d %d", &s, &t, &cost);
        edges[s].emplace_back(t, cost);
        edges[t].emplace_back(s, cost);
    }

    int total = eagerPrim();
    printf("%d\n", total);
    return 0;
}
