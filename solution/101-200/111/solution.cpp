#include <iostream>
#include <queue>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int _val): val(_val), left(nullptr), right(nullptr) {}
    TreeNode(int _val, TreeNode* _left, TreeNode* _right): val(0), left(_left), right(_right) {}
};

class Solution{
public:
    int minDepth(TreeNode* root) {
        if(root==nullptr) {
            return 0;
        }

        queue<TreeNode*> q;
        int min = 0;

        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            TreeNode* curr;
            
            min++;

            for(int i=0;i<size;i++) {
                curr = q.front();
                q.pop();

                if(curr->left==nullptr && curr->right==nullptr) {
                    return min;
                }

                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
        }

        return min;
    }
private:
};

int main(int argc, char* argv[]) {
    Solution s;
    // TreeNode* root = new TreeNode(3);
    // root->left = new TreeNode(9);
    // root->right = new TreeNode(20);
    // root->right->left = new TreeNode(15);
    // root->right->right =new TreeNode(7);

    TreeNode* root = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(5);
    root->right->right->right->right = new TreeNode(6);

    cout<<s.minDepth(root)<<endl;

    return 0;
}
