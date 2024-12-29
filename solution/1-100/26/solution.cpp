#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 0;
        int fast = 0;

        for(fast = 1;fast<nums.size();fast++) {
            if(nums[fast]!=nums[slow]) {
                slow++;
                nums[slow] = nums[fast];
            }
        }

        return slow+1;
    }
};

int main(int argc, char *argv[]) {
    std::vector<int> test1 = {1,1,2};
    std::vector<int> test2 = {1,2,2,3,3,4};

    Solution s;

    std::cout << s.removeDuplicates(test1) << std::endl; 

    for(int i = 0;i<test1.size();i++) {
        printf("%d ", test1[i]);
    }

    std::cout << s.removeDuplicates(test2) << std::endl; 

    for(int i = 0;i<test2.size();i++) {
        printf("%d ", test2[i]);
    }

    return 0;
}