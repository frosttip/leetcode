#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

class Solution{
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> mp;

        for(int i=0;i<nums.size();i++) {
            mp[nums[i]]++;
        }

        std::priority_queue<std::pair<int, int>> pq;

        for(auto x:mp) {
            pq.push(std::make_pair(x.second, x.first));
        }

        std::vector<int> ret;

        for(int i=k;i>0;i--) {
            ret.push_back(pq.top().second);
            pq.pop();
        }

        return ret;
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    std::vector<int> n1 = {1,1,1,2,2,3};
    std::vector<int> n2 = {1};
    std::vector<int> n3 = {1,1,1,2,2,3,3,3,3,3};

    std::vector<int> ret = s.topKFrequent(n3, 2);

    for(int i=0;i<ret.size();i++) {
        std::cout<<ret[i]<<" ";
    }
    std::cout<<std::endl;

    return 0;
}