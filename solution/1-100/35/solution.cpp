#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;

        while(left<=right) {
            mid = (left + right)/2;

            if(nums[mid] == target) {
                return mid;
            }
            else if(nums[mid] > target) {
                right = --mid;
            }
            else {
                left = ++mid;
            }
        }

        return left;
    }
};

int main(int argc, char *argv[]) {
    std::vector<int> test1 = {1,3,5,6};

    Solution s;

    cout << s.searchInsert(test1, 5) << endl;
    cout << s.searchInsert(test1, 2) << endl;
    cout << s.searchInsert(test1, 7) << endl;

    return 0;
}