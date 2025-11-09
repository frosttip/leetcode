#include <iostream>

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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }

        int ret = 0;

        if(root->left!=nullptr && root->left->left==nullptr && root->left->right==nullptr) {
            ret += root->left->val;
        }

        ret += sumOfLeftLeaves(root->left);
        ret += sumOfLeftLeaves(root->right);

        return ret;
    }
private:
};

int main(int argc, char* argv[]) {
    Solution s;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout<<s.sumOfLeftLeaves(root)<<endl;

    return 0;
}
