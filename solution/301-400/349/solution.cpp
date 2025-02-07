#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public: 
    vector<int> intersection(vector<int>& num1, vector<int>& num2) {
        vector<int> ret;
        unordered_set<int> tmp(num1.begin(), num1.end());

        for(auto num:num2) {
            if(tmp.find(num) != tmp.end()) {
                ret.push_back(num);
                tmp.erase(num);
            }
        }

        return ret;
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    vector<int> num1 = {1, 2, 2, 1};
    vector<int> num2 = {2, 2};
    vector<int> ret;

    ret = s.intersection(num1, num2);

    for(auto ans:ret) {
        cout<<ans<<" ";
    }
    cout<<endl;

    return 0;
}