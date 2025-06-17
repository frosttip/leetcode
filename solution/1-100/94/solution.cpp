#include <iostream>
#include <vector>
#include <stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
};

class Solution{
public:
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> ret;

        inorder(root, ret);

        return ret;
    }

    std::vector<int> inorderTraversal_Iterative(TreeNode* root) {
        std::vector<int> ret;
        TreeNode* curr = root;
        std::stack<TreeNode*> st;

        while(curr != NULL || !st.empty()) {
            while(curr != NULL) {
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top();
            st.pop();
            ret.push_back(curr->val);
            curr = curr->right;
        }

        return ret;
    }
private:
    void inorder(TreeNode* root, std::vector<int>& buf) {
        if(root == NULL) {
            return;
        }

        inorder(root->left, buf);
        buf.push_back(root->val);
        inorder(root->right, buf);
    }
};

int main(int argc, char* argv[]) {
    Solution s;

    TreeNode root = TreeNode(1);
    root.left = new TreeNode(2);
    root.left->left = new TreeNode(4);
    root.left->right = new TreeNode(5);
    root.left->right->left = new TreeNode(6);
    root.left->right->right = new TreeNode(7);
    root.right = new TreeNode(3);
    root.right->right = new TreeNode(8);
    root.right->right->left = new TreeNode(9);

    std::vector<int> ret;

    //ret = s.inorderTraversal(&root);
    ret = s.inorderTraversal_Iterative(&root);

    for(int i=0;i<ret.size();i++) {
        std::cout<<ret[i]<<" ";
    }
    std::cout<<std::endl;

    return 0;
}