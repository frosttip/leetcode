#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n, vector<int>(n));
        int left = 0, right = n-1, up = 0, down = n-1;
        int cnt = 1;
        int dir = 0;

        while(left<=right && up<=down) {
            if(dir==0) {
                for(int i=left;i<=right;i++) {
                    ret[up][i] = cnt++;
                }
                up++;
                dir = 1;
            }    
            else if(dir==1) {
                for(int i=up;i<=down;i++) {
                    ret[i][right] = cnt++;
                }
                right--;
                dir = 2;
            }
            else if(dir==2) {
                for(int i=right;i>=left;i--) {
                    ret[down][i] = cnt++;
                }
                down--;
                dir = 3;
            }
            else if(dir==3) {
                for(int i=down;i>=up;i--) {
                    ret[i][left] = cnt++;
                }
                left++;
                dir = 0;
            }
        }

        return ret;
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    vector<vector<int>> ret;

    ret = s.generateMatrix(3);

    for(int i=0;i<ret.size();i++) {
        for(int j=0;j<ret[0].size();j++) {
            cout<< ret[i][j] << " ";
        }
        cout<< endl;
    }
    cout<<endl;

    ret = s.generateMatrix(4);

    for(int i=0;i<ret.size();i++) {
        for(int j=0;j<ret[0].size();j++) {
            cout<< ret[i][j] << " ";
        }
        cout<< endl;
    }
    cout<<endl;

    return 0;
}
