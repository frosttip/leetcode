#include <iostream>
#include <vector>

using namespace std;

class Solution {
public: 
    int intervalSum(vector<int>& nums, int begin, int end) {
        vector<int> buf(nums.size(), 0);

        for(int i=1;i<nums.size();i++) {
            buf[i] = buf[i-1] + nums[i];
        }

        if(begin == 0)
            return buf[end];
        else
            return buf[end] - buf[begin-1];

    }
};

int main(int argc, char* argv[]) {
    Solution s;
    vector<int> test = {5, 1, 2, 3, 4, 5, 10, 13};

    cout << s.intervalSum(test, 3, 5) << endl;
    cout << s.intervalSum(test, 0, 5) << endl;

    return 0;
}