#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

vector<pair<double, double>> node;
int cases;

double weights[101][101];

void initWeight(int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            weights[i][j] = -1;
        }
    }
}

double getEdgeWeight(int u, int v) {
    if (weights[u][v] >= 0) {
        return weights[u][v];
    }

    double dx = node[u].first - node[v].first;
    double dy = node[u].second - node[v].second;

    return (weights[u][v] = weights[v][u] = sqrt(dx * dx + dy * dy));
}


bool hasPath(double dist, int n) {

    int seen = 0;

    vector<bool> visited(n, false);
    queue<int> q;

    q.push(0);
    visited[0] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        seen++;

        for (int i = 0; i < n; ++i) {
            if (visited[i]) continue;
            double w = getEdgeWeight(i, u);
            if (w <= dist) {
                q.push(i);
                visited[i] = true;
            }
        }
    }


    return (seen == n);
}

double arctic(int n) {
    static int INF = 987654321;

    node.clear();
    node.resize(n);
    double x, y;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        node[i] = {x, y};
    }

    double low = 0;
    double high = 1414.00;

    for (int i = 0; i < 100; ++i) {
        double mid = low + (high - low) / 2;
        if (hasPath(mid, n)) {
            high = mid;
        } else {
            low = mid;
        }
    }

    return high;
}

int main() {

    cout.setf(ios::fixed);
    cout.precision(2);
    cin.tie(0);
    cin >> cases;
    char output[10000];
    int offset = 0;
    while (--cases >= 0) {
        int n;
        cin >> n;
        initWeight(n);
        //offset += sprintf(output + offset, "%.2lf\n", );
        cout << arctic(n) << endl;
    }

    //printf("%s", output);

    return 0;
}
