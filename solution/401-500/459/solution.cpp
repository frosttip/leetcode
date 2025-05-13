#include <iostream>

class Solution{
public:
    bool repeatedSubstringPattern(std::string s) {
        // int slen = s.size();

        // for(int i=1;i<=(s.size()/2);i++) {
        //     std::string tmp = s.substr(0, i);
        //     if(slen%tmp.size() == 0) {
        //         int times = slen/(tmp.size());
        //         std::string tmp2 = "";
        //         for(int l=0;l<times;l++) {
        //             tmp2 += tmp;
        //         }

        //         if(tmp2 == s) {
        //             return true;
        //         }
        //     }
        // }

        // return false;

        std::string tmp = s+s;
        tmp.erase(tmp.begin());
        tmp.erase(tmp.end()-1);

        if(tmp.find(s) != std::string::npos) {
            return true;
        }
        return false;
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    std::string tmp = "abcabcabcabc";

    std::cout<<s.repeatedSubstringPattern(tmp)<<std::endl;

    return 0;
}