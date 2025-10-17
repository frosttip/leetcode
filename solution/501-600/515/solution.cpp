#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

class Solution{
public:
    vector<int> LargeestValue(TreeNode* root) {
        vector<int> ret;

        if(root==nullptr) {
            return ret;
        }

        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            TreeNode* curr;
            int min = INT_MIN;

            for(int i=0;i<size;i++) {
                curr = q.front();
                q.pop();

                if(curr->val > min) {
                    min = curr->val;
                }

                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right); 
            }

            ret.push_back(min);
        }

        return ret;
    }
private:
};

int main(int argc, char* argv[]) {
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);
    
    vector<int> ret;

    ret = s.LargeestValue(root);

    for(auto i:ret) {
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}