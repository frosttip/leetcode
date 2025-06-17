#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
};

class Solution
{
public:
    std::vector<int> postorderTraversal(TreeNode *root) {
        std::vector<int> ret;

        postorder(root, ret);

        return ret;
    }

    std::vector<int> postorder_iterative(TreeNode* root) {
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

            if(curr->left != NULL)
                st.push(curr->left); 
            if(curr->right != NULL)
                st.push(curr->right); 
        }
        std::reverse(ret.begin(), ret.end());

        return ret;
    }
private:
    void postorder(TreeNode *root, std::vector<int> &buf) {
        if(root == NULL) {
            return;
        }

        postorder(root->left, buf);
        postorder(root->right, buf);
        buf.push_back(root->val);
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

    //ret = s.postorderTraversal(&root);
    ret = s.postorder_iterative(&root);

    for(int i=0;i<ret.size();i++) {
        std::cout<<ret[i]<< " ";
    }
    std::cout<<std::endl;

    return 0;
}

