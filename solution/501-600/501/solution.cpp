#include <iostream>
#include <vector>
#include <iomanip>  // for std::setw
#include <unordered_map>
#include <stack>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int _val): val(_val), left(nullptr), right(nullptr) {}
    TreeNode(int _val, TreeNode* _left, TreeNode* _right): val(_val), left(_left), right(_right) {}
};

class Solution{
public:
    void help(TreeNode* root, unordered_map<int, int>& mp, int& maxCnt, vector<int>& ret) {
        if(root==nullptr) {
            return;
        }

        help(root->left, mp, maxCnt, ret);
        
        mp[root->val]++;

        int cnt = mp[root->val];

        if(cnt > maxCnt) {
            maxCnt = cnt;
            ret.clear();
            ret.push_back(root->val);
        }
        else if(cnt==maxCnt) {
            ret.push_back(root->val);
        }

        help(root->right, mp, maxCnt, ret);

        return;
    }

    vector<int> findMode(TreeNode* root) {
        vector<int> ret;
        unordered_map<int, int> mp;
        int maxCnt = 0;
        
        help(root, mp, maxCnt, ret);

        return ret;
    }

    vector<int> findMode2(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* curr = root;
        int maxCnt = 0;
        int cnt = 0;
        TreeNode* prev = nullptr;
        vector<int> ret;

        while(!st.empty() || curr!=nullptr) {
            if(curr!=nullptr) {
                st.push(curr);
                curr = curr->left;    
            }
            else {
                curr = st.top();
                st.pop();
                
                if(prev == nullptr) {
                    prev = curr;
                    cnt=1;
                }
                else {
                    if(curr->val == prev->val) {
                        cnt++;
                    }
                    else {
                        cnt=1;
                    }
                }

                if(cnt>maxCnt) {
                    maxCnt = cnt;
                    ret.clear();
                    ret.push_back(curr->val);
                }
                else if(cnt==maxCnt) {
                    ret.push_back(curr->val);
                }

                prev = curr;

                curr = curr->right;
            }
        }

        return ret;
    }
private:
};

const int N = INT_MIN;

TreeNode* buildTreeLC(const vector<int>& arr, int nullVal = INT_MIN) {
    if (arr.empty() || arr[0] == nullVal) return nullptr;

    TreeNode* root = new TreeNode(arr[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < (int)arr.size()) {
        TreeNode* node = q.front();
        q.pop();

        // left
        if (i < (int)arr.size() && arr[i] != nullVal) {
            node->left = new TreeNode(arr[i]);
            q.push(node->left);
        }
        i++;

        // right
        if (i < (int)arr.size() && arr[i] != nullVal) {
            node->right = new TreeNode(arr[i]);
            q.push(node->right);
        }
        i++;
    }
    return root;
}

TreeNode* buildTreeHelper(const vector<int>& arr, int i, int nullVal) {
    // 超出範圍或是這個位置是 null，就回傳空指標
    if (i >= (int)arr.size() || arr[i] == nullVal) {
        return nullptr;
    }

    TreeNode* node = new TreeNode(arr[i]);
    node->left  = buildTreeHelper(arr, 2 * i + 1, nullVal);
    node->right = buildTreeHelper(arr, 2 * i + 2, nullVal);
    return node;
}

TreeNode* buildTree(const vector<int>& arr, int nullVal = INT_MIN) {
    return buildTreeHelper(arr, 0, nullVal);
}

void printTree(TreeNode* root, int depth = 0) {
    if (!root) return;

    // 先印右子樹，讓右邊的節點出現在上面
    printTree(root->right, depth + 1);

    // 印出目前節點，前面補一些空白表示深度
    cout << string(depth * 4, ' ') << root->val << "\n";

    // 再印左子樹
    printTree(root->left, depth + 1);
}

int main(int argc, char* argv[]) {
    Solution s;
    vector<int> root_val = {1,N,2,2};
    TreeNode* root = buildTreeLC(root_val, N);

    vector<int> ret;

    ret = s.findMode2(root);

    for(int x:ret) {
        cout<<x<<" ";
    }
    cout<<endl;

    return 0;
}