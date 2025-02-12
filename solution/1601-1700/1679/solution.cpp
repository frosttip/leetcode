#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxOperations(std::vector<int>& nums, int k) {
        int ret = 0;
        int left = 0, right = nums.size()-1;

        std::sort(nums.begin(), nums.end());

        while(left < right) {
            int sum = nums[left] + nums[right];
            if(sum == k) {
                ret++;
                left++;
                right--;
            }
            else if(sum > k) {
                right--;
            }
            else {
                left++;
            }
        }

        return ret;
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    std::vector<int> nums = {3, 1, 3, 4, 3};

    std::cout<<s.maxOperations(nums, 6)<<std::endl;
}