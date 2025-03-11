#include <iostream>
#include <vector>

class Solution {
public:
    void reverseString(std::vector<char>& s) {
        for(int i=0, j=s.size()-1;i<j;i++, j--) {
            std::swap(s[i], s[j]);
        }
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    std::vector<char> words = {'h', 'e', 'l', 'l', 'o'};

    s.reverseString(words);

    std::cout<<"Reverse result: ";
    for(auto w:words) {
        std::cout<<w;
    }
    std::cout<<std::endl;

    return 0;
}