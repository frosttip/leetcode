#include <iostream>

using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int s_slow = 0;
        int s_fast = 0;
        int t_slow = 0;
        int t_fast = 0;

        for(s_fast = 0;s_fast<s.size();s_fast++) {
            if(s[s_fast] != '#') {
                s[s_slow++] = s[s_fast];
            }
            else {
                if(s_slow>0) {
                    s_slow--;
                }
            }
        }

        for(int i = s_slow;i<s.size();i++) {
            s[i] = ' ';
        }

        for(t_fast = 0;t_fast<t.size();t_fast++) {
            if(t[t_fast] != '#') {
                t[t_slow++] = t[t_fast];
            }
            else {
                if(t_slow>0) {
                    t_slow--;
                }
            }
        }

        for(int i = t_slow;i<t.size();i++) {
            t[i] = ' ';
        }

        if(s_slow > t_slow) {
            return s.substr(0, s_slow) == t.substr(0, s_slow);
        }
        else {
            return s.substr(0, t_slow) == t.substr(0, t_slow);
        }
    }
};

int main(int argc, char *argv[]) {
    Solution s;

    cout << s.backspaceCompare("ab#c", "ad#c") << endl;
    cout << s.backspaceCompare("ab##", "c#d#") << endl;
    cout << s.backspaceCompare("a#c", "b") << endl;
    cout << s.backspaceCompare("gtc#uz#", "gtc#uz##") << endl;

    return 0;
}
