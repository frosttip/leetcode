#include <iostream>

class Solution {
public:
    void reverseTmp(std::string& s, int start, int end) {
        for(int i=start, j=end;i<j;i++, j--) {
            std::swap(s[i], s[j]);
        }
    }

    std::string reverseStr(std::string s, int k) {
        for(int i=0;i<s.size();i+=(2*k)) {
            if((i+k)<s.size()) {
                reverseTmp(s, i, i+k-1);
            }
            else {
                reverseTmp(s, i, s.size()-1);
            }
        }

        return s;
    }
};

int main (int argc, char* argv[]) {
    Solution s;
    std::string Str = "abcdefg";

    std::cout<< s.reverseStr(Str, 2) <<std::endl;

    return 0;
}