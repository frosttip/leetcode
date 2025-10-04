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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ret;

        if(root==NULL) {
            return ret;
        }
        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            double sum = 0;
            TreeNode* curr;

            for(int i=0;i<size;i++) {
                curr = q.front();
                q.pop();

                sum += curr->val;

                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }

            ret.push_back(sum/size);
        }

        return ret;
    }
private:
};

int main(int argc, char* argv[]) {
    Solution s;
    vector<double> ret;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    ret = s.averageOfLevels(root);

    for(auto i:ret) {
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}