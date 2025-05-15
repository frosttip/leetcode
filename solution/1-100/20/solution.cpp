#include <iostream>
#include <stack>

class Solution{
public:
    bool isValid(std::string s) {
        std::stack<char> st;

        for(int i=0;i<s.size();i++) {
            if(s[i] == '(') {
                st.push(')');
            }
            else if(s[i] == '[') {
                st.push(']');
            }
            else if(s[i] == '{') {
                st.push('}');
            }
            else if(st.empty() || st.top() != s[i]) {
                return false;
            }
            else {
                st.pop();
            }
        }

        return st.empty();
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    std::string tmp = "()[]{}";
    std::string tmp2 = "(]";
    std::string tmp3 = "([])";
    std::string tmp4 = "])";
    std::string tmp5 = "(";

    std::cout<<s.isValid(tmp)<<std::endl;
    std::cout<<s.isValid(tmp2)<<std::endl;
    std::cout<<s.isValid(tmp3)<<std::endl;
    std::cout<<s.isValid(tmp4)<<std::endl;
    std::cout<<s.isValid(tmp5)<<std::endl;

    return 0;
}