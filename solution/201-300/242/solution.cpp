#include <iostream>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        int map[26] = {0};

        for(int i=0;i<s.size();i++) {
            map[s[i] - 'a']++;
        }

        for(int i=0;i<t.size();i++) {
            map[t[i] - 'a']--;
        }

        for(int i=0;i<26;i++) {
            if(map[i] != 0) {
                return false;
            }
        }

        return true;
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    std::string s_string = "anagram";
    std::string t_string = "nagaram";

    std::cout<< s.isAnagram(s_string, t_string) << std::endl;

    return 0;
}