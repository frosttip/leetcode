#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        std::vector<std::vector<int>> ret;
        int left = 0;
        int right = 0;

        std::sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++) {
            if(nums[i]>target && nums[i]>=0) {
                break;
            }

            if(i>0 && nums[i] == nums[i-1]) {
                continue;
            }

            for(int j=i+1;j<nums.size();j++) {
                if(nums[i] + nums[j] > target && nums[i] + nums[j] >= 0) {
                    break;
                }

                if(j>i+1 && nums[j] == nums[j-1]) {
                    continue;
                }

                left = j+1;
                right = nums.size() - 1;

                while(left < right) {
                    if((long)nums[i] + nums[j] + nums[left] + nums[right] < target) {
                        left++;
                    }
                    else if((long)nums[i] + nums[j] + nums[left] + nums[right] > target) {
                        right--;
                    }
                    else {
                        std::vector<int> tmp;
                        tmp.push_back(nums[i]);
                        tmp.push_back(nums[j]);
                        tmp.push_back(nums[left]);
                        tmp.push_back(nums[right]);

                        ret.push_back(tmp);

                        while(left < right && nums[left]==nums[left+1]) {
                            left++;
                        }

                        while(left < right && nums[right]==nums[right-1]) {
                            right--;;
                        }

                        left++;
                        right--;
                    }
                }
            }
        }
        return ret;
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    std::vector<int> nums = {1, 0, -1, 0, -2, 2};
    std::vector<std::vector<int>> ret;

    ret = s.fourSum(nums, 0);
    std::cout<<"ret size: "<<ret.size()<<std::endl;

    std::cout<<"[";
    for(int i=0;i<ret.size();i++) {
        std::cout<<"[";
        for(int j = 0;j<ret[i].size();j++) {
            std::cout<<ret[i][j]<<" ";
        }
        std::cout<<"] ";
    }
    std::cout<<"]"<<std::endl;

    return 0;
}