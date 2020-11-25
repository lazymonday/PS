class Solution {
public:
    string addStrings(string num1, string num2) {
        string ret;
        int fi = num1.size() - 1, si = num2.size() - 1;
        int carry = 0;

        while (fi >= 0 or si >= 0 or carry) {
            int first = 0;
            if (fi >= 0) {
                first = num1[fi] - '0';
            }

            int second = 0;
            if (si >= 0) {
                second = num2[si] - '0';
            }

            int curr = first + second + carry;
            if (curr >= 10) {
                carry = 1;
                curr -= 10;
            } else carry = 0;

            ret.append(to_string(curr));
            fi--, si--;
        }

        reverse(ret.begin(), ret.end());
        return ret;
    }
};