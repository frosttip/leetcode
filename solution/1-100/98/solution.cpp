#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int _val): val(_val), left(nullptr), right(nullptr) {}
    TreeNode(int _val, TreeNode* _left, TreeNode* _right): val(_val), left(_left), right(_right) {}
};

const int N = INT_MIN;

class Solution {
public:
    bool help(TreeNode* root, long min, long max) {
        if(root==nullptr) {
            return true;
        }

        if(!(root->val < max && root->val > min)) {
            return false;
        }

        bool l = help(root->left, min, root->val);
        bool r = help(root->right, root->val, max);

        return l&r;
    }

    bool isValidBST(TreeNode* root) {
        return help(root, LONG_MIN, LONG_MAX);
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
    vector<int> root1_v = {2,1,3};
    vector<int> root2_v = {5,1,4, N, N,3,6};

    TreeNode* root1 = s.buildTree(root1_v, N);
    TreeNode* root2 = s.buildTree(root2_v, N);

    cout<<s.isValidBST(root1)<<endl;
    cout<<s.isValidBST(root2)<<endl;

    return 0;
}
