#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        deque<int> dq;
        int n = nums.size();

        for(int i=0;i<n;i++) {
            while(!dq.empty() && dq.back() < nums[i]) {
                dq.pop_back();
            }

            dq.push_back(nums[i]);

            if(i>=k && dq.front() == nums[i-k]) {
                dq.pop_front();
            }

            if(i-k+1>=0) {
                ret.push_back(dq.front());
            }
        }

        return ret;
    }
private:
};

int main(int argc,char* argv[]) {
    Solution s;
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    vector<int> ret = s.maxSlidingWindow(nums,3);

    for(auto i : ret) {
        cout << i << " " << endl;
    }

    return 0;
}
