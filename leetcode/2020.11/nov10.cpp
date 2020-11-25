#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    typedef vector<int> vec;
    struct Vector {
        int _x, _y;
        Vector(int x, int y) : _x(x), _y(y) {}
        
        Vector operator-(const Vector& v) const {
            return {_x - v._x, _y - v._y};
        }
        
        int operator*(const Vector& v) const {
            return _x * v._x + _y * v._y;
        }

        bool operator<(const Vector& v) const {
            if(_x == v._x) return _y < v._y;
            return _x < v._x;
        }

        string toString() const {
            stringstream ss;
            ss << _x << ", " << _y << "\n";
            return ss.str();
        }
    };
    
    bool isOrthogonal(pair<int, int>& p1, pair<int, int>& p2, pair<int, int>& origin) {
        Vector v1(p1.first - origin.first, p1.second - origin.second);
        Vector v2(p2.first - origin.first, p2.second - origin.second);

        if(v1 * v2 == 0) return true;
        return false;
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {

        vector<pair<int, int>> points;
        points.push_back({p1[0], p1[1]});
        points.push_back({p2[0], p2[1]});
        points.push_back({p3[0], p3[1]});
        points.push_back({p4[0], p4[1]});

        sort(points.begin(), points.end());

        return isOrthogonal(points[1], points[2], points[0]) and isOrthogonal(points[1], points[2], points[3]);
    }
};

int main() {
/*
    [1,0]
    [-1,0]
    [0,1]
    [0,-1]
*/
    return 0;
}