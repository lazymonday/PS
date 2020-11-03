#include <bits/stdc++.h>

using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {

    int dr[] = {0, 0, 0, 1, 2, 2, 2};
    int dc[] = {0, 1, 2, 1, 0, 1, 2};

    int ans = -1e9;

    for (int i = 0; i < arr.size(); ++i)
    {
        for (int j = 0; j < arr[i].size(); ++j)
        {
            int sum = 0;
            for (int k = 0; k < 7; ++k)
            {
                int nr = i + dr[k];
                int nc = j + dc[k];

                if (nr < 0 || nr >= 6 || nc < 0 || nc >= 6) {
                    sum = -1e9;
                    break;
                }

                sum += arr[nr][nc];
            }
            ans = max(ans, sum);
        }
    }

    return ans;
}

int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);

    cout << result << "\n";

    //fout.close();

    return 0;
}
