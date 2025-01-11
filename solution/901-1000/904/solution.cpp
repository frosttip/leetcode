#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ret = 0;
        unordered_map<int, int> map;
        int left = 0, right = 0;

        for(right = 0;right<fruits.size();right++) {
            map[fruits[right]]++;

            while(map.size()>2) {
                map[fruits[left]]--;
                if(map[fruits[left]]==0) {
                    map.erase(fruits[left]);
                }
                left++;
            }

            ret = max(ret, right - left + 1);
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> test1 = {1,2,1};
    vector<int> test2 = {0,1,2,2};
    vector<int> test3 = {1,2,3,2,2};
    vector<int> test4 = {1,2,3,2,2,1,1,1,1,4,4};

    cout << s.totalFruit(test1) << endl;
    cout << s.totalFruit(test2) << endl;
    cout << s.totalFruit(test3) << endl;
    cout << s.totalFruit(test4) << endl;

    return 0;
}