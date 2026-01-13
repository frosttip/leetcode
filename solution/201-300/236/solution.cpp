#include <iostream>
#include <iomanip>  // for std::setw
#include <vector>
#include <queue>

using namespace std;

const int N = INT_MIN;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int _val): val(_val), left(nullptr), right(nullptr) {}
    TreeNode(int _val, TreeNode* _left, TreeNode* _right): val(_val), left(_left), right(_right) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr || root==p || root==q) {
            return root;
        }

        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);

        if(l!=nullptr && r!=nullptr) {
            return root;
        }

        if(l==nullptr && r!=nullptr) {
            return r;
        }
        else if(l!=nullptr && r==nullptr) {
            return l;
        }

        return nullptr;
    }
};

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
    if (!root) return nullptr;
    if (root->val == target) return root;
    if (auto l = findNode(root->left, target)) return l;
    return findNode(root->right, target);
}

int main(int argc, char* argv[]) {
    Solution s;
    vector<int> root_val = {3,5,1,6,2,0,8,N,N,7,4};
    TreeNode* root = buildTreeLC(root_val, N);
    TreeNode* p = findNode(root, 5);
    TreeNode* q = findNode(root, 1);
    TreeNode* ret = s.lowestCommonAncestor(root, p, q);

    cout<<ret->val<<endl;

    return 0;
}