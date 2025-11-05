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

class solution{
public:
    int help(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }

        int l = help(root->left);
        if(l == -1)
            return -1;
        int r = help(root->right);
        if(r == -1)
            return -1;
        
        if(abs(l-r)>1) {
            return -1;
        }

        return max(l, r)+1;
    }

    bool isBalanced(TreeNode* root) {
        return help(root)==-1? false:true;
    }
private:
};

int main(int argc, char* argv[]) {
    solution s;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout<<s.isBalanced(root)<<endl;

    return 0;
}
