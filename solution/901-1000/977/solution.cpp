#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0; 
        int right = nums.size()-1;
        int cnt = nums.size()-1;
        vector<int> ret(nums.size(), 0);

        for(int i=0;i<nums.size();i++) {
            if(abs(nums[left]) > abs(nums[right])) {
                ret[cnt--] = nums[left]*nums[left];
                left++;
            }
            else {
                ret[cnt--] = nums[right]*nums[right];
                right--;
            }
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    vector<int> test1 = {-4,-1,0,3,10};
    vector<int> test2 = {-7,-3,2,3,11};
    Solution s;

    vector<int> ret = s.sortedSquares(test1);
    for(int i=0;i<ret.size();i++) {
        printf("%d ", ret[i]);
    }
    printf("\n");

    vector<int> ret2 = s.sortedSquares(test2);
    for(int i=0;i<ret2.size();i++) {
        printf("%d ", ret2[i]);
    }
    printf("\n");

    return 0;
}