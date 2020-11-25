class Solution {
public:
    void decode(string& s, int &i, stringstream& ss) {
        int repCnt = 0;
        bool firstFound = false;
        stringstream part;
        for ( ; i < s.size(); ++i) {
            if (isdigit(s[i])) {
                if (!firstFound) {
                    repCnt *= 10;
                    repCnt += s[i] - '0';
                } else {
                    decode(s, i, part);
                }
            } else if (isalpha(s[i])) {
                part << s[i];
            } else if (s[i] == '[') {
                firstFound = true;
            } else if (s[i] == ']') {
                auto str = part.str();
                while (repCnt--) ss << str;
                break;
            }
        }
    }

    string decodeString(string s) {
        int n = s.size();
        stringstream ss;
        for (int i = 0; i < n; ++i) {
            if (isdigit(s[i])) {
                decode(s, i, ss);
            } else if (isalpha(s[i])) {
                ss << s[i];
            }
        }
        return ss.str();
    }
};