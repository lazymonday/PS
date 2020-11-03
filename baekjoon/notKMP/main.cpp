#include <iostream>
#include <vector>
#include <string>

//using namespace std;
//
//int g[51][26];
//int n, q;
//
//int checkQuery(int s, const string &query, vector<bool> &marked) {
//    if (s >= query.size()) {
//        return 1;
//    }
//
//    int u = query[s];
//    int ret = 0;
//
//    if(marked[u]) {
//        return 0;
//    }
//
//    for (int i = 0; i < n; ++i) {
//        if (g[i][u] == 0 || marked[i]) {
//            continue;
//        }
//
//        marked[i] = true;
//        if (checkQuery(s + 1, query, marked)) {
//            return 1;
//        }
//
//        marked[i] = false;
//    }
//
//    return ret;
//}
//
//
//int main() {
//    cin.tie(0);
//    cin >> n >> q;
//    string line;
//    getline(cin, line);
//
//    memset(g, 0, sizeof g);
//    for (int i = 0; i < n; ++i) {
//        getline(cin, line);
//        for (int k = 0; k < line.size(); ++k) {
//            if (isupper(line[k])) {
//                g[i][line[k] - 'A'] = 1;
//            }
//        }
//    }
//
//    string query;
//    string result;
//    for (int i = 0; i < q; ++i) {
//        cin >> query;
//        // one query
//        bool pass = true;
//        if (query.size() > n) {
//            result += "NO\n";
//            continue;
//        }
//
//        for (int j = 0; j < query.size(); ++j) {
//            query[j] -= 'A';
//        }
//
//        vector<bool> marked(n, false);
//        result += checkQuery(0, query, marked) == 1 ? "YES\n" : "NO\n";
//    }
//
//    cout << result;
//
//    return 0;
//}
//

using namespace std;

const int N = 55;

bool g[N][N];
int match[N], matched[N];
bool mark[N];
int len;
string s;

bool dfs(int v) {
    if (mark[v]){
        return false;
    }

    mark[v] = true;
    for (int u = 0; u < len; ++u) {
        if (!g[v][s[u]]) continue;
        if (match[u] == -1 || dfs(match[u])) {
            matched[v] = u;
            match[u] = v;
            return true;
        }
    }

    return false;
}

string line;

int main() {
    ios_base::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    assert(1 <= n && n <= 50);
    getline(cin, line);
    assert(line.empty());
    for (int i = 0; i < n; ++i) {
        getline(cin, line);
        for (int j = 0; j < line.size(); ++j) {
            char c = line[j];
            if (c >= 'A' && c <= 'Z')
                g[i][c - 'A'] = 1;
        }
    }
    while (q--) {
        cin >> s;
        len = s.size();
        assert(len > 0);
        for (int j = 0; j < len; ++j) {
            assert(s[j] >= 'A' && s[j] <= 'Z');
            s[j] -= 'A';
        }
        if (len > n)
            cout << "NO\n";
        else {
            memset(matched, -1, sizeof matched);
            memset(match, -1, sizeof match);
            while (1) {
                memset(mark, false, sizeof mark);
                bool found = 0;
                for (int i = 0; i < n; ++i) {
                    if (matched[i] == -1 && !mark[i])
                        found |= dfs(i);
                }

                if (!found)
                    break;
            }
            int cnt = 0;
            for (int i = 0; i < n; ++i)
                cnt += matched[i] != -1;
            cout << (cnt == len ? "YES\n" : "NO\n");
        }
    }
    return 0;
}
