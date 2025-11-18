#include <iostream>
#include <iomanip>  // for std::setw
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int _val): val(_val), left(nullptr), right(nullptr) {}
    TreeNode(int _val, TreeNode* _left, TreeNode* _right): val(_val), left(_left), right(_right) {}
};

// 以「側躺」方式印出二元樹：右子樹在上，左子樹在下
void printTree(TreeNode* root, int depth = 0) {
    if (!root) return;

    // 先印右子樹，讓右邊的節點出現在上面
    printTree(root->right, depth + 1);

    // 印出目前節點，前面補一些空白表示深度
    cout << string(depth * 4, ' ') << root->val << "\n";

    // 再印左子樹
    printTree(root->left, depth + 1);
}