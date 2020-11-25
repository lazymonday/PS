class Solution {
public:
    int mirrorReflection(int p, int q) {
        int g = gcd(p, q);

        // xq = yp
        // x = np / q (x is the smallest if n = q')
        //   = p / g
        // y = q' (q = q'g)
        int x = (p / g) % 2;
        int y = (q / g) % 2;

        if (x == 1 && y == 1) return 1;
        return x == 1 ? 0 : 2;
    }

    int gcd(int p, int q) {
        if (q > p) swap(p, q);
        if (q == 0) return p;
        return gcd(p % q, q);
    }
};