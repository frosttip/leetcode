#include <iostream>
#include <stack>
#include <algorithm>

class Solution{
public:
    std::string removeDuplicates(std::string s) {
        std::stack<char> st;
        std::string ret;

        for(int i=0;i<s.size();i++) {
            if(!st.empty() && st.top() == s[i]) {
                st.pop();
            }
            else {
                st.push(s[i]);
            }
        }

        while(st.size()) {
            ret += st.top();
            st.pop();
        }

        std::reverse(ret.begin(), ret.end());

        return ret;
    }
};

int main() {
    Solution s;
    std::string s1 = "abbaca";
    std::string s2 = "azxxzy";

    std::cout<<s.removeDuplicates(s1)<<std::endl;
    std::cout<<s.removeDuplicates(s2)<<std::endl;

    return 0;
}