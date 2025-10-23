#include <iostream>
#include <queue>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int _val): val(_val), left(nullptr), right(nullptr) {}
    TreeNode(int _val, TreeNode* _left, TreeNode* _right): val(_val), left(_left), right(_right) {}
};

class Solution{
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==nullptr) {
            return root;
        }

        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            TreeNode* curr;

            for(int i=0;i<size;i++) {
                curr = q.front();
                q.pop();

                TreeNode* tmp;
                tmp = curr->left;
                curr->left = curr->right;
                curr->right = tmp;

                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
        }

        return root;
    }
private:
};

int main(int argc, char* argv[]) {
    Solution s;
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    s.invertTree(root);

    return 0;
}
