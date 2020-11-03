#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1e6;
const int INF = 2e9;
typedef long long ll;

int conv(char p) {
    switch (p) {
    case 'I':
        return 1;
    case 'V':
        return 5;
    case 'X':
        return 10;
    case 'L':
        return 50;
    case 'C':
        return 100;
    case 'D':
        return 500;
    case 'M':
        return 1000;
    }

    return -1;
}

int toInt(string s) {
    int last = -1;
    int ret = 0;
    for (int i = s.size() - 1; i >= 0; --i)
    {
        int num = conv(s[i]);
        if (last != -1 && last > num) {
            ret -= num;
        } else {
            ret += num;
        }
        last = num;
    }

    return ret;
}

string fromInt(int k, int base) {
    static string one = "IXCM";
    static string five = "VLD";

    if (k == 0) {
        return "";
    } else if (k == 1) {
        return one.substr(base, 1);
    } else if (k < 4) {
        return one[base] + fromInt(k - 1, base);
    }   else if (k == 4) {
        return five[base] + one.substr(base, 1);
    } else if (k == 5) {
        return five.substr(base, 1);
    } else if (k < 9) {
        return one.substr(base, 1) + fromInt(k - 1, base);
    } else if (k == 9) {
        return one[base + 1] + one.substr(base, 1);
    }

    return "";
}

string toRome(int k) {

    string ret;
    int base = 10;
    int dividened = 0;
    while (k) {
        int r = k % base;
        k /= base;

        ret += fromInt(r, dividened++);
    }

    reverse(ret.begin(), ret.end());
    return ret;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string a, b;
    cin >> a >> b;

    int ret = toInt(a) + toInt(b);
    cout << ret << "\n" << toRome(ret) << "\n";

    return 0;
}
