#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int m;
const int START = 401;
const int V = 402;
const int INFINITE = 987654321;

vector<pair<int, int>> adj[V]; // edge and cost

int vertex(int idx) {
    return idx + 200;
}

vector<int> dijkstra(int start) {

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> dist(V, INFINITE);
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty()) {
        int cost = pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if (dist[here] > cost) {
            continue;
        }

        for (int i = 0; i < adj[here].size(); ++i) {
            int w = adj[here][i].second;
            int to = adj[here][i].first;

            if (cost + w < dist[to]) {
                dist[to] = cost + w;
                pq.push({cost + w, to});
            }
        }
    }

    return dist;
}

int make_graph(vector<pair<int, int>> &items) {

    for (int i = 0; i < V; ++i) {
        adj[i].clear();
    }

    for (int j = 0; j < V; ++j) {
        for (int i = 0; i < items.size(); ++i) {
            int dt = items[i].first - items[i].second;
            adj[START].emplace_back(vertex(dt), items[i].first);
        }
    }

    for (int i = -200; i < 200; ++i) {
        for (int j = 0; j < items.size(); ++j) {
            int delta = items[j].first - items[j].second;
            if (abs(i + delta) > 200) {
                continue;
            }

            adj[vertex(i)].emplace_back(vertex(i + delta), items[j].first);
        }
    }
}

int another_nthlon(vector<pair<int, int>> &items) {

    const int MAX = 200;
    vector<int> costs(MAX * 2, INFINITE);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, 200});  // sum, diff

    while (!pq.empty()) {
        int sum = pq.top().first;
        int diff = pq.top().second;
        pq.pop();

        for (int i = 0; i < m; ++i) {
            int vindex = diff + items[i].first - items[i].second;
            int newSum = sum + items[i].first;

            if (vindex < 0 || vindex > MAX * 2) {
                continue;
            }

            if (costs[vindex] > newSum) {
                costs[vindex] = newSum;
                pq.push({newSum, vindex});
            }
        }
    }

    return costs[MAX] != INFINITE ? costs[MAX] : INFINITE;
}


int main() {

    int cases;
    cin >> cases;

    while (--cases >= 0) {
        cin >> m;
        vector<pair<int, int>> items(m);
        for (int i = 0; i < m; ++i) {
            cin >> items[i].first >> items[i].second;
        }

//        make_graph(items);
//        auto retDist = dijkstra(START);
//        int ret = retDist[vertex(0)];
        int ret = another_nthlon(items);
        if (ret == INFINITE) {
            cout << "IMPOSSIBLE" << endl;
        } else {
            cout << ret << endl;
        }
    }

    return 0;
}
