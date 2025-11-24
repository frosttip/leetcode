#include<iostream>
#include<vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int _val): val(_val), left(nullptr), right(nullptr) {}
    TreeNode(int _val, TreeNode* _left, TreeNode* _right): val(_val), left(_left), right(_right) {}
};

const int N = INT_MIN;

class Solution{
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == nullptr && root2 == nullptr) {
            return nullptr;
        }
        else if(root1 != nullptr && root2 == nullptr) {
            return root1;
        }
        else if(root1 == nullptr && root2 != nullptr) {
            return root2;
        }

        root1->val += root2->val;

        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);

        return root1;
    }

    TreeNode* buildTreeHelper(const vector<int>& arr, int i, int nullVal) {
        // 超出範圍或是這個位置是 null，就回傳空指標
        if (i >= (int)arr.size() || arr[i] == nullVal) {
            return nullptr;
        }

        TreeNode* node = new TreeNode(arr[i]);
        node->left  = buildTreeHelper(arr, 2 * i + 1, nullVal);
        node->right = buildTreeHelper(arr, 2 * i + 2, nullVal);

        return node;
    }

    TreeNode* buildTree(const vector<int>& arr, int nullVal = INT_MIN) {
        return buildTreeHelper(arr, 0, nullVal);
    }

    void printTree(TreeNode* root, int depth = 0) {
        if (!root) return;

        // 先印右子樹，讓右邊的節點出現在上面
        printTree(root->right, depth + 1);

        // 印出目前節點，前面補一些空白表示深度
        cout << string(depth * 4, ' ') << root->val << "\n";

        // 再印左子樹
        printTree(root->left, depth + 1);
    }
private:
};

int main(int argc, char* argv[]) {
    Solution s;
    vector<int> root1Arr = {1, 3, 2, 5};                     // [1,3,2,5]
    vector<int> root2Arr = {2, 1, 3, N, 4, N, 7};            // [2,1,3,null,4,null,7]

    TreeNode* root1 = s.buildTree(root1Arr, N);
    TreeNode* root2 = s.buildTree(root2Arr, N);
    
    TreeNode* ret = s.mergeTrees(root1,root2);

    s.printTree(ret);

    return 0;
}