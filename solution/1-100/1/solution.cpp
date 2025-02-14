#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> map;
        std::vector<int> ret;

        for(int i=0;i<nums.size();i++) {
            int buf = target - nums[i];
            if(map.find(buf) != map.end()) {
                ret.push_back(map[buf]);
                ret.push_back(i);
                break;
            }
            else {
                map[nums[i]] = i;
            }
        }

        return ret;
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    std::vector<int> nums = {2, 7, 11, 15};
    std::vector<int> ret;

    ret = s.twoSum(nums, 9);

    for(auto tmp:ret) {
        std::cout<<tmp<< " ";
    }
    std::cout<<std::endl;

    return 0;
}