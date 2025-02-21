#include <iostream>
#include <vector>

class Solution {
public: 
    std::vector<int> assignElements(std::vector<int>& groups, std::vector<int>& elements) {
        std::vector<int> map(1e5+1, -1);
        std::vector<int> ret(groups.size(), -1);

        for(int i=0;i<elements.size();i++) {
            int e = elements[i];

            if(map[e] != -1) {
                continue;
            }

            while(e <= 1e5) {
                if(map[e] == -1) {
                    map[e] = i;
                }

                e += elements[i];
            }
        }

        for(int i=0;i<groups.size();i++) {
            ret[i] = map[groups[i]];
        }

        return ret;
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    std::vector<int> groups = {8, 4, 3, 2, 4};
    std::vector<int> elements = {4, 2};
    std::vector<int> ret;

    ret = s.assignElements(groups, elements);

    for(int a:ret) {
        std::cout<<a<<" ";
    }
    std::cout<<std::endl;

    return 0;
}