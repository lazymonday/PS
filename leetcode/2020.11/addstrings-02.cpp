class Solution {
public:
    string addStrings(string num1, string num2) {
        stringstream ss;
        auto fi = num1.rbegin();
        auto si = num2.rbegin();
        int carry = 0;

        while (fi != num1.rend() or si != num2.rend() or carry) {
            int first = (fi == num1.rend() ? 0 : *fi++ - '0');
            int second = (si == num2.rend() ? 0 : *si++ - '0');
            int curr = first + second + carry;
            ss << curr % 10;
            carry = curr / 10;
        }

        string ret = ss.str();
        reverse(ret.begin(), ret.end());
        return ret;
    }
};