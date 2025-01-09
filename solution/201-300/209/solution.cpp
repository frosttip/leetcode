#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ret = INT_MAX;
        int sum = 0;
        int sublen = 0;
        int i = 0, j = 0;

        for(j=0;j<nums.size();j++) {
            sum += nums[j];

            while(sum >= target) {
                sublen = j - i + 1;
                ret = ret<sublen? ret:sublen;
                sum -= nums[i++];
            }
        }

        return ret==INT_MAX? 0:ret;
    }
};

int main(int argc, char *argv[]) {
    vector<int> test1 = {2,3,1,2,4,3};
    vector<int> test2 = {1,4,4};
    vector<int> test3 = {1,1,1,1,1,1,1,1};

    Solution s;

    cout << s.minSubArrayLen(7, test1) <<endl;
    cout << s.minSubArrayLen(4, test2) <<endl;
    cout << s.minSubArrayLen(11, test3) <<endl;

    return 0;
}