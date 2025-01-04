#include <iostream>

using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        long left = 0;
        long right = num;
        long mid = 0;

        while(left <= right) {
            mid = (left + right)/2;

            if(mid*mid == num) {
                return true;
            }
            else if(mid*mid < num) {
                left = ++mid;
            }
            else {
                right = --mid;
            }
        }

        return false;
    }
};

int main(int argc, char *argv[]) {
    Solution s;

    cout << s.isPerfectSquare(16) << endl;
    cout << s.isPerfectSquare(14) << endl;

    return 0;
}