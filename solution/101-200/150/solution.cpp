#include <iostream>
#include <vector>
#include <stack>
#include <string>

class Solution{
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<int> st;

        for(int i=0;i<tokens.size();i++) {
            if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/") {
                int tmp = 0;
                tmp = std::stoi(tokens[i]);
                st.push(tmp);
            }
            else {
                int last = 0;
                int first = 0;
                int result = 0;

                last = st.top();
                st.pop();
                first = st.top();
                st.pop();

                if(tokens[i][0] == '+') {
                    result = first + last;
                }
                else if(tokens[i][0] == '-') {
                    result = first - last;
                }
                else if(tokens[i][0] == '*') {
                    result = first * last;
                }
                else if(tokens[i][0] == '/') {
                    result = first / last;
                }

                st.push(result);
            }
        }

        return st.top();
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    std::vector<std::string> s1 = {"2","1","+","3","*"};
    std::vector<std::string> s2 = {"4","13","5","/","+"};
    std::vector<std::string> s3 = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};

    std::cout<<s.evalRPN(s1)<<std::endl;
    std::cout<<s.evalRPN(s2)<<std::endl;
    std::cout<<s.evalRPN(s3)<<std::endl;

    return 0;
}
