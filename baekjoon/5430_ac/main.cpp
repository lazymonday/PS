#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

pair<int, int> query(string cmd, string &numStr) {

    int begin = 1;
    int end = numStr.rfind(']') - 1;
    numStr[0] = ',';
    numStr[numStr.size() - 1] = ',';

    for (int i = 0; i < cmd.size(); ++i) {
        if (cmd[i] == 'R') {
            int temp = -begin;
            begin = -end;
            end = temp;
        } else if (cmd[i] == 'D') {
            bool reversed = begin < 0;
            bool underflow;
            if (reversed) {
                underflow = abs(begin) < abs(end);
            } else {
                underflow = end < begin;
            }

            if (underflow) {
                return {0, 0};
            }

            while (numStr[abs(begin + 1)] != ',') begin++;
            begin += 2;
        }
    }

    return {begin, end};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int cases;
    cin >> cases;

    while (--cases >= 0) {

        string cmd;
        cin >> cmd;
        int m;
        cin >> m;
        string numString;
        cin >> numString;
        auto index = query(cmd, numString);

        if (index.first == 0 && index.second == 0) {
            cout << "error\n";
        } else {
            bool reversed = index.first < 0;
            cout << "[";
            if (reversed) {
                int head = -index.second;
                int tail = -index.first;

                int cur = 0;
                auto pos = numString.rfind(',', tail);
                while (pos != string::npos && tail >= head) {
                    if (cur++ != 0) {
                        cout << ",";
                    }
                    cout << numString.substr(pos + 1, tail - pos);
                    tail = pos;
                    --tail;
                    if (tail <= 0) break;
                    pos = numString.rfind(',', tail);
                }

            } else {
                cout << numString.substr(index.first, index.second - index.first + 1);
            }
            cout << "]\n";
        }

    }
    return 0;
}
