#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        long left = 0;
        long right = x;
        long mid = 0;
        long ret = 0;

        while(left <= right) {
            mid = (left + right)/2;

            if(mid*mid == x) {
                return (int)mid;
            }
            else if(mid*mid > x) {
                right = --mid;
            }
            else {
                ret = mid;
                left = ++mid;
            }

        }

        return (int)ret;
    }
};

int main(int argc, char *argv[]) {

    Solution s;

    cout << s.mySqrt(4) << endl;
    cout << s.mySqrt(8) << endl;
    cout << s.mySqrt(6) << endl;

    return 0;
}