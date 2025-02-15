#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int fourSumCount(std::vector<int>& nums1, std::vector<int>& nums2, std::vector<int>& nums3, std::vector<int>& nums4) {
        std::unordered_map<int, int> map;
        int ret = 0;

        for(int a:nums1) {
            for(int b:nums2) {
                map[a+b]++;
            }
        }

        for(int c:nums3) {
            for(int d:nums4) {
                if(map.find(0-(c+d)) != map.end()) {
                    ret += map[0-(c+d)];
                }
            }
        }

        return ret;
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    std::vector<int> nums1 = {1, 2};
    std::vector<int> nums2 = {-2, -1};
    std::vector<int> nums3 = {-1, 2};
    std::vector<int> nums4 = {0, 2};

    std::cout<<s.fourSumCount(nums1, nums2, nums3, nums4)<<std::endl;

    return 0;
}