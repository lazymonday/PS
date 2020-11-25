#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n == 0) return 0;
        
        double a = log(n);
        double b = log(3) - numeric_limits<double>::epsilon();
        double ret = fmod((a/b), 1.0);
        cout << std::fixed << std::setprecision(20) << ret << "\n";
        
        return ret <= numeric_limits<double>::epsilon() * 2;
    }
};

int main() {

    Solution s;
    cout << std::boolalpha << s.isPowerOfThree(81);
    return 0;
}