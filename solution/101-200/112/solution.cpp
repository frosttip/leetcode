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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) {
            return false;
        }
        
        bool l = false;
        bool r = false;

        if(root->left==nullptr && root->right==nullptr) {
            return (targetSum-root->val == 0);
        }

        if(root->left) 
            l = hasPathSum(root->left, targetSum-root->val);
        if(root->right)
            r = hasPathSum(root->right, targetSum-root->val);

        return l|r;
    }
private:
};

int main(int argc, char* argv[]) {
    Solution s;
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);

    cout<<s.hasPathSum(root, 20)<<endl;

    return 0;
}
