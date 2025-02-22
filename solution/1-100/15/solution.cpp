#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> ret;
        int left = 0;
        int right = 0;

        std::sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++) {
            int e = nums[i];

            if(nums[i] > 0) {
                break;
            }

            if(i>0 && nums[i] == nums[i-1]) {
                continue;
            }

            left = i+1;
            right = nums.size()-1;

            while(left<right) {
                if(nums[i] + nums[left] + nums[right] > 0) {
                    right--;
                }   
                else if(nums[i] + nums[left] + nums[right] < 0) {
                    left++;
                }
                else {
                    std::vector<int> tmp;
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[left]);
                    tmp.push_back(nums[right]);
                    ret.push_back(tmp);

                    while(left<right && nums[left] == nums[left+1]) {
                        left++;
                    }

                    while(left<right && nums[right] == nums[right-1]) {
                        right--;
                    }

                    left++;
                    right--;
                }
            }
        }

        return ret;
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    std::vector<int> nums = {-1, 0, 1, 2, -1, -4};
    std::vector<std::vector<int>> ret;

    ret = s.threeSum(nums);

    for(int i=0;i<ret.size();i++) {
        for(int j=0;j<ret[i].size();j++) {
            std::cout<<ret[i][j]<<" ";
        }
        std::cout<<std::endl;
    }

    return 0;
}