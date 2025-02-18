#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

class Solution {
public:
    int minOperations(std::vector<int>&nums, int k) {
        int ret = 0;
        std::priority_queue<long, std::vector<long>, std::greater<long>> minheap(nums.begin(), nums.end());;
        long x = 0;
        long y = 0;

        while(minheap.top() < k) {
            x = minheap.top();
            minheap.pop();
            y = minheap.top();
            minheap.pop();
            minheap.push(std::min(x, y)*2 + std::max(x, y));

            ret++;
        }

        return ret;
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    std::vector<int> nums = {2, 11, 10, 1, 3};

    std::cout<< s.minOperations(nums, 10) <<std::endl;

    return 0;
}