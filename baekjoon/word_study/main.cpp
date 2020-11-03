#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    string input;

    cin >> input;

    vector<int> countTable(26, 0);
    for (int i = 0; i < input.size(); ++i) {
        ++countTable[tolower(input[i]) - 'a'];
    }

    vector<pair<int, int>> tbl;
    for (int j = 0; j < countTable.size(); ++j) {
        tbl.push_back({countTable[j], j});
    }

    sort(tbl.begin(), tbl.end(), greater<>());

    if(tbl[0].first == tbl[1].first) {
        cout << "?" << endl;
    } else {
        cout << (char)(tbl[0].second + 'A') << endl;
    }

    return 0;
}
