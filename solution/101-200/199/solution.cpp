#include <iostream>
#include <queue>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

using namespace std;

class Solution{
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;

        if(root==NULL) {
            return ret;
        }

        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()) {
            TreeNode* curr;
            int size = q.size();

            for(int i=0;i<size;i++) {
                curr = q.front();
                q.pop();

                if(i==(size-1)) {
                    ret.push_back(curr->val);
                }

                if(curr->left)
                    q.push(curr->left);

                if(curr->right)
                    q.push(curr->right);
            }
        }

        return ret;
    }
private:
};

int main(int argc, char* argv[]) {
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->left->left = new TreeNode(5);
    vector<int> ret;

    ret = s.rightSideView(root);

    for(auto i:ret) {
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}

