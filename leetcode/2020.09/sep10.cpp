class Solution {
public:
    string getHint(string secret, string guess) {

        string ret;
        int bulls = 0;
        int cnt1[11] = {0, };
        int cnt2[11] = {0, };
        for (int i = 0; i < guess.size(); ++i) {
            cnt1[secret[i] - '0']++;
            cnt2[guess[i] - '0']++;
            if (guess[i] == secret[i]) {
                bulls++;
            }
        }

        int cows = 0;
        for (int i = 0; i < 11; ++i) {
            cows += min(cnt1[i], cnt2[i]);
        }

        cows -= bulls;

        ostringstream o(ret);
        o << bulls << "A" << cows << "B";

        return o.str();
    }
};