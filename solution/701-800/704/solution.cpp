#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ret = -1;
        int start = 0;
        int end = nums.size()-1;
        int mid = 0;

        while(start <= end) {
            mid = (start + end)/2;

            if(nums[mid] == target) {
                ret = mid;
                break;
            }
            else if(nums[mid] > target) {
                end = --mid;
            }
            else {
                start = ++mid;
            }
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution s;

    std::vector<int> test_input = {-1,0,3,5,9,12};
    std::vector<int> test_input2 = {-1,0,3,5,9,12};

    std::cout << s.search(test_input, 9) << std::endl;
    std::cout << s.search(test_input2, 2) << std::endl;

    return 0;
}