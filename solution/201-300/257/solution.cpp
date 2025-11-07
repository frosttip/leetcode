#include <iostream>
#include <vector>
#include <string>

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
    void help(TreeNode* root, vector<string>& ret, string s) {
        if(root->left == nullptr && root->right == nullptr) {
            s += to_string(root->val);
            ret.push_back(s);
            return;
        }

        if(root->left)
            help(root->left, ret, s+to_string(root->val)+"->");
        if(root->right)    
            help(root->right, ret, s+to_string(root->val)+"->");
        
        return;
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        string s;

        help(root, ret, s);

        return ret;
    }
private:
};

int main(int argc, char* argv[]) {
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    vector<string> ret;

    ret = s.binaryTreePaths(root);

    for(auto s:ret) {
        cout<<s<<endl;
    }

    return 0;
}
