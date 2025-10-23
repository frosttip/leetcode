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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;

        q.push(root->left);
        q.push(root->right);

        while(!q.empty()) {
            TreeNode* l;
            TreeNode* r;

            l=q.front();
            q.pop();
            r=q.front();
            q.pop();

            if(l==nullptr && r==nullptr) {
                continue;
            }

            if(l==nullptr || r==nullptr || (l->val != r->val)) {
                return false;
            }

            q.push(l->left);
            q.push(r->right);
            q.push(l->right);
            q.push(r->left);
        }

        return true;
    }
private:
};

int main(int argc, char* argv[]) {
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    cout<<s.isSymmetric(root)<<endl;

    return 0;
}