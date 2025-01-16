#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<int, int> map;
        int left = 0, right = 0;
        int minlen = INT_MAX;
        int startIdx = 0;
        int count = t.size();

        for(int i=0;i<t.size();i++) {
            map[t[i]]++;
        }

        for(right = 0;right<s.size();right++) {
            if(map[s[right]]-- > 0) {
                count--;
            }

            while(count==0) {
                if(right - left + 1 < minlen) {
                    startIdx = left;
                    minlen = right - left + 1;
                }

                if(map[s[left++]]++ == 0) {
                    count++;
                }
            }
        }

        return minlen==INT_MAX? "":s.substr(startIdx, minlen);
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    string s1 = "ADOBECODEBANC";
    string t1 = "ABC";
    string s2 = "a";
    string t2 = "a";
    string s3 = "a";
    string t3 = "aa";
    string ret;

    ret = s.minWindow(s1, t1);
    for(int i=0;i<ret.size();i++) {
        cout << ret[i];
    }
    cout<<endl;

    ret = s.minWindow(s2, t2);
    for(int i=0;i<ret.size();i++) {
        cout << ret[i];
    }
    cout<<endl;

    ret = s.minWindow(s3, t3);
    for(int i=0;i<ret.size();i++) {
        cout << ret[i];
    }
    cout<<endl;

    return 0;
}

