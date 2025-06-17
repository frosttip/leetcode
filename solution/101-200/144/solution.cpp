#include <iostream>
#include <vector>
#include <stack>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *right, TreeNode *left): val(x), left(left), right(right) {}
};

class Solution{
public:
    std::vector<int> preorderTraversal(TreeNode *root) {
        std::vector<int> ret;

        preorder(root, ret);

        return ret;
    }

    std::vector<int> preorder_iterative(TreeNode* root) {
        std::vector<int> ret;
        std::stack<TreeNode*> st;
        TreeNode* curr = root;

        if(root == NULL) {
            return ret;
        }

        st.push(curr);

        while(!st.empty()) {
            curr = st.top();
            st.pop();
            ret.push_back(curr->val);

            if(curr->right != NULL)
                st.push(curr->right);
            if(curr->left != NULL)
                st.push(curr->left);
        }

        return ret;
    }
private:
    void preorder(TreeNode *root, std::vector<int> &buf) {
        if(root == NULL) {
            return;
        }

        buf.push_back(root->val);
        preorder(root->left, buf);
        preorder(root->right, buf);
    }
};

int main(int argc, char* argv[]) {
    Solution s;

    // TreeNode root = TreeNode(1);
    // root.right = new TreeNode(2);
    // root.right->left = new TreeNode(3);

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

    //ret = s.preorderTraversal(&root);
    ret = s.preorder_iterative(&root);

    for(int i=0;i<ret.size();i++) {
        std::cout<<ret[i]<<" ";
    }
    std::cout<<std::endl;

    return 0;
}