#include <bits/stdc++.h>

using namespace std;

int n;
double adj[20][20];
int r[20][20];
int INF = 1e9;


void print_mat() {
    cout << "==============================================\n";
    cout.setf(ios::right);
    cout << fixed << setprecision(5);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << setw(8) << adj[i][j] << " ";
        }
        cout << "\n";
    }
}

void print_mat2() {
    cout << "==============================================\n";
    cout.setf(ios::right);
    cout << fixed;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << setw(3) << (r[i][j] == INF ? 0 : r[i][j]) << " ";
        }
        cout << "\n";
    }
}

int main() {

    n = 5;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {adj[i][j] = 1.0; r[i][j] = 0; continue;}
            adj[i][j] = 0.0;
            r[i][j] = INF;
        }
    }

    adj[0][2] = 2.0;
    adj[2][0] = 1.0 / 2.0;
    adj[1][4] = 3.0;
    adj[4][1] = 1.0 / 3.0;
    adj[2][3] = 0.5;
    adj[3][2] = 1.0 / 0.5;
    adj[4][3] = 5.0;
    adj[3][4] = 1.0 / 5.0;

    r[0][2] = r[2][0] = 1;
    r[1][4] = r[1][4] = 1;
    r[2][3] = r[3][2] = 1;
    r[4][3] = r[3][4] = 1;

    print_mat2();

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                r[i][j] = min(r[i][j], r[i][k] + r[k][j]);
                // if (adj[i][k] > 0.0 && adj[k][j] > 0.0) {
                //     adj[i][j] = adj[i][k] * adj[j][k];
                // }
            }
        }
    }

    print_mat2();

    return 0;
}