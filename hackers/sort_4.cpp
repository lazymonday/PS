#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the activityNotifications function below.
int activityNotifications(vector<int> expenditure, int d) {
    int cnt[210] = {0, };
    for (int i = 0; i < d; ++i)
        cnt[expenditure[i]]++;

    bool isEven = (d % 2 == 0);

    int ret = 0;
    int pv1 = d / 2;
    int pv2 = d / 2 + 1;
    for (int i = d; i < expenditure.size(); ++i) {
        float median = 0;
        int psum = 0;
        float m1 = -1, m2 = -1;

        for (int k = 0; k <= 200; ++k) {
            if (cnt[k] == 0) continue;

            if (isEven) {
                if (m1 < 0 && psum + cnt[k] >= pv1) {
                    m1 = k;
                }

                if (m2 < 0 && psum + cnt[k] >= pv2) {
                    m2 = k;
                }

                if (m1 > 0 && m2 > 0) {
                    median = (m1 + m2) / 2.0f;
                    break;
                }
            } else {
                if (psum + cnt[k] > pv1) {
                    median = k;
                    break;
                }
            }

            psum += cnt[k];
        }

        //printf("Median : %.4f, Curr : %d\n", median, expenditure[i]);

        if (median * 2.0 <= expenditure[i]) ret++;
        cnt[expenditure[i]]++;
        cnt[expenditure[i - d]]--;
    }

    return ret;
}

int main()
{
    string nd_temp;
    getline(cin, nd_temp);

    vector<string> nd = split_string(nd_temp);

    int n = stoi(nd[0]);

    int d = stoi(nd[1]);

    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector<string> expenditure_temp = split_string(expenditure_temp_temp);

    vector<int> expenditure(n);

    for (int i = 0; i < n; i++) {
        int expenditure_item = stoi(expenditure_temp[i]);

        expenditure[i] = expenditure_item;
    }

    int result = activityNotifications(expenditure, d);

    cout << result << "\n";
    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
