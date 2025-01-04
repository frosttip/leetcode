#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        int mid = 0;
        int ran_l = -1, ran_r = -1;

        if(nums.size() < 1) {
            return {-1, -1};
        }

        while(left <= right) {
            mid = (left + right)/2;

            if(nums[mid] == target) {
                ran_l = mid;
                right = --mid;
            }
            else if(nums[mid] < target) {
                left = ++mid;
            }
            else{
                right = --mid;
            }
        }

        left = 0;
        right = nums.size()-1;

        while(left <= right) {
            mid = (left + right)/2;

            if(nums[mid] == target) {
                ran_r = mid;
                left = ++mid;
            }
            else if(nums[mid] < target) {
                left = ++mid;
            }
            else{
                right = --mid;
            }
        }

        return {ran_l, ran_r};
    }
};

int main(int argc, char *argv[]) {
    std::vector<int> test1 = {5,7,7,8,8,10};
    std::vector<int> test2 = {};
    std::vector<int> ret;

    Solution s;

    ret = s.searchRange(test1, 8);
    
    std::cout << "[";
    for (int num:ret) {
        std::cout << num << " ";
    }
    std::cout << "]";
    std::cout << std::endl;

    ret = s.searchRange(test1, 6);
    
    std::cout << "[";
    for (int num:ret) {
        std::cout << num << " ";
    }
    std::cout << "]";
    std::cout << std::endl;

    ret = s.searchRange(test2, 0);
    
    std::cout << "[";
    for (int num:ret) {
        std::cout << num << " ";
    }
    std::cout << "]";
    std::cout << std::endl;

    return 0;
}