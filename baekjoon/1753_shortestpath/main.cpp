#include <iostream>
#include <queue>
#include <vector>
#include <stdio.h>

using namespace std;

int V, E, S;
const int INF = 987654321;

vector<vector<pair<int, int>>> edges;   // edge, weight

vector<int> spfa(int s) {

    vector<bool> inQueue(V, false);
    vector<int> dist(V + 1, INF);
    deque<int> q;

    q.push_front(s);
    dist[s] = 0;
    inQueue[s] = true;

    while (!q.empty()) {
        int here = q.front();
        q.pop_front();
        inQueue[here] = false;

        for (int i = 0; i < edges[here].size(); ++i) {
            int there = edges[here][i].first;
            int cost = edges[here][i].second;

            if (dist[there] > dist[here] + cost) {
                dist[there] = dist[here] + cost;
                if (!inQueue[there]) {
                    q.push_back(there);
                    inQueue[there] = true;

                    if (dist[q.back()] < dist[q.front()]) {
                        q.push_front(q.back());
                        q.pop_back();
                    }
                }
            }
        }
    }

    return dist;
}

vector<int> dijkstra(int s) {
    vector<int> dist(V + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, s});
    dist[s] = 0;

    while (!pq.empty()) {
        int cost = pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if (dist[here] < cost) {
            continue;
        }

        for (int i = 0; i < edges[here].size(); ++i) {
            int there = edges[here][i].first;
            int c = edges[here][i].second;

            if (dist[there] > dist[here] + c) {
                dist[there] = dist[here] + c;
                pq.push({dist[there], there});
            }
        }
    }

    return dist;
}

int main() {

    cin >> V >> E >> S;

    edges.resize(E + 1);
    int u, v, w;
    for (int i = 0; i < E; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        edges[u].push_back({v, w});
    }

    auto ret = spfa(S);
    for (int j = 1; j < ret.size(); ++j) {
        if (ret[j] == INF) {
            printf("INF\n");
        } else {
            printf("%d\n", ret[j]);
        }
    }

    return 0;
}
