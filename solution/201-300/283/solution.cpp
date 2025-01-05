#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0;
        int fast = 0;

        for(fast = 0;fast<nums.size();fast++) {
            if(nums[fast] != 0) {
                nums[slow++] = nums[fast];
            }
        }

        for(;slow<nums.size();slow++) {
            nums[slow] = 0;
        }
    }
};

int main(int argc, char *argv[]) {
    vector<int> test1 = {0,1,0,3,12};
    vector<int> test2 = {0};

    Solution s;

    s.moveZeroes(test1);
    for(int i=0;i<test1.size();i++) {
        cout << test1[i] << " ";
    }
    cout<<endl;

    s.moveZeroes(test2);
    for(int i=0;i<test2.size();i++) {
        cout << test2[i] << " ";
    }
    cout<<endl;

    return 0;
}