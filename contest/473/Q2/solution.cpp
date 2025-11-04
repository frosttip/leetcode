#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class solution{
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long ret=0;

        for(int i=0;i<nums.size();i++) {
            nums[i] = nums[i]*nums[i];
        }

        sort(nums.begin(), nums.end());

        int n = nums.size()/2;

        for(int i=0;i<nums.size();i++) {
            if(i<n) {
                ret -= nums[i];
            }
            else {
                ret += nums[i];
            }
        }

        return ret;
    }
private:
};

int main(int argc, char* argv[]) {
    solution s;
    vector<int> nums1 = {1,2,3};
    vector<int> nums2 = {1,-1,2,-2,3,-3};

    cout<<s.maxAlternatingSum(nums1)<<endl;
    cout<<s.maxAlternatingSum(nums2)<<endl;

    return 0;
}
