#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slowIndex = 0;

        for(int fastIndex = 0;fastIndex<nums.size();fastIndex++) {
            if(nums[fastIndex] != val) {
                nums[slowIndex++] = nums[fastIndex];
            }
        }

        return slowIndex;
    }
};

int main(int argc, char *argv[])
{
    std::vector<int> test1 = {3,2,2,3};
    std::vector<int> test2 = {0,1,2,2,3,0,4,2};

    Solution s;

    std::cout << s.removeElement(test1, 3) << std::endl;
    std::cout << s.removeElement(test2, 2) << std::endl;

    return 0;
}