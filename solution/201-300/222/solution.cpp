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

class solution{
public:
    int countNode(TreeNode* root) {
        if(root==nullptr) {
            return 0;
        }

        queue<TreeNode*> q;
        int ret = 0;

        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            TreeNode* curr;

            for(int i=0;i<size;i++) {
                curr = q.front();
                q.pop();

                ret++;

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
    solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    cout<<s.countNode(root)<<endl;

    return 0;
}