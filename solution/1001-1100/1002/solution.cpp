#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

class Solution{
public:
    std::vector<std::string> commonChars(std::vector<std::string>& words) {
        std::vector<std::string> ret;
        int map[26] = {0};
        int compare_map[26] = {0};

        for(int i=0;i<words[0].size();i++) {
            map[words[0][i] - 'a']++;
        }

        for(int i=1;i<words.size();i++) {
            memset(compare_map, 0, sizeof(compare_map));
            for(int j=0;j<words[i].size();j++) {
                compare_map[words[i][j] - 'a']++;
            }

            for(int k = 0;k<26;k++) {
                map[k] = std::min(map[k], compare_map[k]);
            }
        }
        
        for(int i=0;i<26;i++) {
            while(map[i]--) {
                std::string s(1, i + 'a');
                ret.push_back(s);
            }
        }

        return ret;
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    std::vector<std::string> words = {"bella", "label", "roller"};
    std::vector<std::string> ret;

    ret = s.commonChars(words);

    for(int i = 0;i<ret.size();i++) {
        std::cout<<ret[i]<<" ";
    }
    std::cout<<std::endl;

    return 0;
}