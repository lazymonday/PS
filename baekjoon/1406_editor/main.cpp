#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 6e5;
const int INF = 2e9;
typedef long long ll;

string s;
struct unit {
    char s;
    unit *next;
    unit *prev;
};

unit *head;

unit *insert(unit *cur, char c) {  // left insert
    unit *p = new unit{c, cur->next, cur};
    if (cur->next) cur->next->prev = p;
    cur->next = p;
    return p;
}

unit *remove(unit *cur) {
    if (cur == head) {
        return cur;
    }

    unit *ret = cur->prev;
    cur->prev->next = cur->next;
    if (cur->next) cur->next->prev = cur->prev;
    delete cur;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    head = new unit{'\0', 0, 0};
    unit *cur = head;
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        insert(cur, s[i]);
        cur = cur->next;
    }

    int n;
    cin >> n;
    string cmd;
    while (n--) {
        cin >> cmd;
        if (cmd == "P") {
            char c;
            cin >> c;
            cur = insert(cur, c);
        } else if (cmd == "B") {
            cur = remove(cur);
        } else if (cmd == "L") {
            if (cur->prev) {
                cur = cur->prev;
            }
        } else if (cmd == "D") {
            if (cur->next) {
                cur = cur->next;
            }
        }
    }

    cur = head->next;
    while (cur != 0) {
        cout << cur->s;
        cur = cur->next;
    }

    return 0;
}
