#include <iostream>
#include <unordered_set>

class Solution {
public:
    bool isHappy(int n) {
        int sum = 0;
        std::unordered_set<int> map;

        while(1) {
            sum = 0;
            while(n) {
                sum += (n%10) * (n%10);
                n /=10;
            }

            if(sum == 1) {
                break;
            }

            if(map.find(sum) != map.end()) {
                return false;
            }
            else {
                map.insert(sum);
            }
            n = sum;
        }

        return true;
    }
};

int main(int argc, char* argv[]) {
    Solution s;

    std::cout<< s.isHappy(2) << std::endl;

    return 0;
}