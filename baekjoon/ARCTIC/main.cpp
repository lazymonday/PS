#include <iostream>
#include <vector>
#include <math.h>
#include <stdio.h>

using namespace std;

vector<pair<double, double>> node;

int cases;

double getEdgeWeightSquared(int u, int v);

double arctic(int n) {

    static double INF = 987654321;

    node.clear();
    node.resize(n);
    double x, y;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        node[i] = {x, y};
    }

    vector<bool> visited(n, false);
    vector<double> weight(n, INF);
    vector<int> parent(n, -1);

    weight[0] = 0;
    parent[0] = 0;

    double maxWeight = 0;

    for (int j = 0; j < n; ++j) {
        int u = -1;
        // find min weight node not visited yet
        for (int v = 0; v < n; ++v) {
            if (!visited[v] && (u == -1 || weight[u] > weight[v])) {
                u = v;
            }
        }

        // min u;
        visited[u] = true;
        maxWeight = max(weight[u], maxWeight);

        for (int i = 0; i < n; ++i) {
            if (i == u) continue;
            double w = getEdgeWeightSquared(u, i);
            if (!visited[i] && w < weight[i]) {
                weight[i] = w;
                parent[i] = u;
            }
        }
    }

    return maxWeight;
}

double weights[100][100];

double getEdgeWeightSquared(int u, int v) {
    if (weights[u][v] > 0) {
        return weights[u][v];
    }

    double dx = node[u].first - node[v].first;
    double dy = node[u].second - node[v].second;

    return (weights[u][v] = weights[v][u] = sqrt(dx * dx + dy * dy));
}

int main() {

    cin.tie(0);

    cin >> cases;
    char output[10000];
    int offset = 0;
    while (--cases >= 0) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                weights[i][j] = -1;
            }
        }

        double ret = arctic(n);
        offset += sprintf(output + offset, "%.2lf\n", ret);
    }

    printf("%s", output);

    return 0;
}
