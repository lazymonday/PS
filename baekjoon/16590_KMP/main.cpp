#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

int n, q;

const int MAX_LEN = 1000001;

int adj[26][50];
int matchedA[55];
int matchedB[55];

char input[MAX_LEN];

bool dfs(char *str, int u, vector<bool> &visited) {
    if (visited[u]) {
        return false;
    }

    visited[u] = true;
    for (int v = 0; v < n; ++v) {
        if (adj[str[u] - 'A'][v] == 0) continue;
        if (matchedB[v] == -1 || dfs(str, matchedB[v], visited)) {
            matchedB[v] = u;
            matchedA[u] = v;
            return true;
        }
    }

    return false;
}

bool query(char *str) {

    int flow = 0;
    int queryCount = strlen(str);
    if (queryCount > n) {
        return false;
    }

    memset(matchedB, -1, sizeof matchedB);
    memset(matchedA, -1, sizeof matchedB);

    for (int i = 0; i < queryCount; ++i) {
        vector<bool> visited(queryCount, false);
        if (dfs(str, i, visited)) {
            ++flow;
        }
    }

    return flow == queryCount;
}


int main() {

    scanf("%d%d", &n, &q);
    fgets(input, sizeof(input), stdin);
    for (int i = 0; i < n; ++i) {
        fgets(input, sizeof(input), stdin);
        char *p = input;
        while (*p != '\0') {
            if ('A' <= *p && *p <= 'Z') {
                adj[*p - 'A'][i] = 1;
            }
            ++p;
        }
    }

    while (q--) {
        scanf("%s", input);
        printf("%s\n", query(input) ? "YES" : "NO");
    }

    return 0;
}

