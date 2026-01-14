#include <iostream>
#include <iomanip>  // for std::setw
#include <vector>
#include <queue>

using namespace std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* _left, TreeNode* _right) : val(x), left(_left), right(_right) {}
 };

 const int N = INT_MIN;

//Build tree like leetcode, recommand.
TreeNode* buildTreeLC(const vector<int>& arr, int nullVal = INT_MIN) {
    if (arr.empty() || arr[0] == nullVal) return nullptr;

    TreeNode* root = new TreeNode(arr[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < (int)arr.size()) {
        TreeNode* node = q.front();
        q.pop();

        // left
        if (i < (int)arr.size() && arr[i] != nullVal) {
            node->left = new TreeNode(arr[i]);
            q.push(node->left);
        }
        i++;

        // right
        if (i < (int)arr.size() && arr[i] != nullVal) {
            node->right = new TreeNode(arr[i]);
            q.push(node->right);
        }
        i++;
    }
    return root;
}

TreeNode* findNode(TreeNode* root, int target) {
    if(root==nullptr) return root;
    if(root->val == target) return root;
    TreeNode* l = findNode(root->left, target);
    if(nullptr != l) return  l;
    return findNode(root->right, target);
}

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // if(root==nullptr) {
        //     return root;
        // }

        // if(root->val > p->val && root->val > q->val) {
        //     TreeNode* l = lowestCommonAncestor(root->left, p, q);
        //     if(l != nullptr) {
        //         return l;
        //     }
        // }
        // else if(root->val < p->val && root->val < q->val) {
        //     TreeNode* r = lowestCommonAncestor(root->right, p, q);
        //     if(r != nullptr) {
        //         return r;
        //     }
        // }

        // return root;

        TreeNode* ret;

        while(1) {
            if(root->val > p->val && root->val > q->val) {
                root = root->left;
            }
            else if(root->val < p->val && root->val < q->val) {
                root = root->right;
            }
            else {
                ret = root;
                break;
            }
        }

        return root;
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    vector<int> root_val = {6,2,8,0,4,7,9,N,N,3,5};
    TreeNode* root = buildTreeLC(root_val, N);
    TreeNode* p = findNode(root, 2);
    TreeNode* q = findNode(root, 8);

    TreeNode* ret = s.lowestCommonAncestor(root, p, q);

    cout<<ret->val<<endl;

    return 0;
}