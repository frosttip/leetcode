#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int _val): val(_val), left(nullptr), right(nullptr) {}
    TreeNode(int _val, TreeNode* _left, TreeNode* _right): val(_val), left(_left), right(_right) {}
};

class Solution{
public: 
    TreeNode* help(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int posStart, int posEnd) {
        if(inStart>inEnd || posStart>posEnd) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(postorder[posEnd]);
        int inStart_l = 0, inEnd_l = 0, inStart_r = 0, inEnd_r = 0;
        for(int i=inStart;i<=inEnd;i++) {
            if(inorder[i]==postorder[posEnd]) {
                inEnd_l = i-1;
                inStart_r = i+1;
                break;
            }
        }

        root->left = help(inorder, postorder, inStart, inEnd_l, posStart, posStart+(inEnd_l-inStart));
        root->right = help(inorder, postorder, inStart_r, inEnd, posStart+(inEnd_l-inStart+1), posEnd-1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return help(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
    }
private:
};

int main(int argc, char* argv[]) {
    Solution s;
    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};
    TreeNode* root = nullptr;

    root = s.buildTree(inorder, postorder);

    return 0;
}