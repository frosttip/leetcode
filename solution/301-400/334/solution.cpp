#include <iostream>
#include <vector>

class Solution{
public:
    bool increaseingTriplet(std::vector<int>& nums) {
        if(nums.size() < 3) {
            return false;
        }

        int low = INT_MAX;
        int mid = INT_MAX;

        for(int i=0;i<nums.size();i++) {
            if(nums[i]>mid) {
                return true;
            }
            else if(nums[i] > low && nums[i] < mid) {
                mid = nums[i];
            }
            else if(nums[i] < low) {
                low = nums[i];
            }
        }

        return false;
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    std::vector<int> tmp1 = {1, 2, 3, 4, 5};
    std::vector<int> tmp2 = {2, 1, 5, 0, 4, 6};
    std::vector<int> tmp3 = {5, 4, 3, 2, 1};

    std::cout<< s.increaseingTriplet(tmp1) << std::endl;
    std::cout<< s.increaseingTriplet(tmp2) << std::endl;
    std::cout<< s.increaseingTriplet(tmp3) << std::endl;

    return 0;
}
