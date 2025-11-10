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
    int findBottomLeftValue(TreeNode* root) {
        if(root==nullptr) {
            return 0;
        }

        queue<TreeNode*> q;
        int layer = 0;
        int ret_layer = 0;
        int ret = 0;

        q.push(root);

        while(!q.empty()) {
            TreeNode* curr;
            int size = q.size();
            layer++;

            for(int i=0;i<size;i++) {
                curr = q.front();
                q.pop();

                if(layer > ret_layer) {
                    ret_layer = layer;
                    ret = curr->val;
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
    root->left->left = new TreeNode(4);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->right->left->left = new TreeNode(7);

    cout<<s.findBottomLeftValue(root)<<endl;

    return 0;
}
