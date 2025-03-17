#include <iostream>
#include <algorithm>

class Solution {
public:
    std::string reverseWords(std::string s) {
        int left = 0;
        int right = 0;

        reverse(s.begin(), s.end());
        for(int i=0;i<s.size();) {
            while(s[i] == ' ' && i<s.size()) {
                i++;
            }

            if(i >= s.size()) {
                break;
            }

            while (s[i] != ' ' && i<s.size())
            {
                s[right++] = s[i++];
            }

            reverse(s.begin()+left, s.begin()+right);

            s[right++] = ' ';
            
            left = right;
            i++;
        }

        s.resize(right-1);

        return s;
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    std::string tmp = "  hello world  ";
    std::string ret;

    ret = s.reverseWords(tmp);

    std::cout<<ret<<std::endl;

    return 0;
}