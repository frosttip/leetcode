#include <iostream>
#include <queue>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():  val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val): val(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode* left, TreeNode* right): val(val), left(left), right(right) {}
};

class Solution{
public:
    int maxDepth(TreeNode* root) {
        if(root==nullptr) {
           return 0;
        }

        queue<TreeNode*> q;
        int ret=0;

        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            TreeNode* curr;

            ret++;

            for(int i=0;i<size;i++) {
                curr = q.front();
                q.pop();

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

int main(int argc,char* argv[]) {
    Solution s;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout<<s.maxDepth(root)<<endl;

    return 0;
}
