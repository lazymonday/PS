#include <iostream>
#include <vector>

int n;
int m;
int village[51][51];
int chic[13][2];
int chicSize = 0;
int house[100][2];
int houseSize = 0;
int minDistance = 987654321;

using namespace std;

int calcDistance(const vector<int> &chick) {
    int *dist = new int[houseSize];
    for (int i = 0; i < houseSize; ++i) {
        dist[i] = 987654321;
    }

    for (int k = 0; k < chick.size(); ++k) {
        for (int i = 0; i < houseSize; ++i) {
            int x = abs(chic[chick[k]][0] - house[i][0]);
            int y = abs(chic[chick[k]][1] - house[i][1]);
            dist[i] = std::min(dist[i], x + y);
        }
    }

    int sum = 0;
    for (int i = 0; i < houseSize; ++i) {
        sum += dist[i];
    }

    return sum;
}


void chooseChicken(int tried, vector<int> &choose) {

    if (tried >= chicSize) {
        if (choose.size() == m) {
            minDistance = min(minDistance, calcDistance(choose));
//            for (int i = 0; i < choose.size(); ++i) {
//                cout << choose[i];
//            }
//            cout << endl;
        }
        return;
    }

    choose.push_back(tried);
    chooseChicken(tried + 1, choose);
    choose.pop_back();
    chooseChicken(tried + 1, choose);
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> village[i][j];
            if (village[i][j] == 2) {
                chic[chicSize][0] = i;  // row
                chic[chicSize][1] = j;  // col
                ++chicSize;
            } else if (village[i][j] == 1) {
                house[houseSize][0] = i;
                house[houseSize][1] = j;
                ++houseSize;
            }
        }
    }


    vector<int> choose;
    chooseChicken(0, choose);
    cout << minDistance << endl;
    return 0;
}
