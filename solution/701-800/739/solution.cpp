#include <iostream>
#include <stack>
#include <vector>

class Solution{
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        std::stack<int> st;
        std::vector<int> ret(temperatures.size(), 0);

        for(int i=0;i<temperatures.size();i++) {
            while(!st.empty() && temperatures[st.top()] < temperatures[i]) {
                ret[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }

        return ret;
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    std::vector<int> temp = {73,74,75,71,69,72,76,73};
    std::vector<int> ret;

    ret = s.dailyTemperatures(temp);

    for(auto x:ret) {
        std::cout<<x<<" ";
    }
    std::cout<<std::endl;

    return 0;
}