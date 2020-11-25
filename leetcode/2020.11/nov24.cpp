class Solution {
public:

    bool isOp(char c) {
        if (c == '+' or c == '-' or
                c == '*' or c == '/') return true;
        return false;
    }

    int getDigit(const string& s, int& idx) {
        while (idx < s.size() and isspace(s[idx])) ++idx;

        int num = 0;
        while (idx < s.size() and isdigit(s[idx])) {
            num *= 10;
            num += s[idx] - '0';
            idx++;
        }

        return num;
    }

    int calc(char op, int op1, int op2) {
        if (op == '*') {
            return op1 * op2;
        } else if (op == '/') {
            return op1 / op2;
        } else if (op == '+') {
            return op1 + op2;
        } else if (op == '-') {
            return op1 - op2;
        }

        throw new exception();
    }

    int calculate(string s) {
        stack<int> st;
        for (int i = 0; i < s.size(); ) {
            if (isdigit(s[i])) {
                st.push(getDigit(s, i));
            } else if (isOp(s[i])) {
                if (s[i] == '*' or s[i] == '/') {
                    auto op1 = st.top();
                    st.pop();
                    st.push(calc(s[i], op1, getDigit(s, ++i)));
                } else if (s[i] == '+') {
                    st.push(getDigit(s, ++i));
                } else if (s[i] == '-') {
                    st.push(-getDigit(s, ++i));
                }
            } else {
                ++i;
            }

            // pass white spaces
        }

        int ans = 0;
        while (!st.empty())
            ans += st.top(), st.pop();

        return ans;
    }
};