#include <iostream>
#include <iomanip>  // for std::setw
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

const int N = INT_MIN;

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

int main(int argc, char* argv[]) {
    vector<int> root1Arr = {1, 3, 2, 5};                     // [1,3,2,5]
    vector<int> root2Arr = {2, 1, 3, N, 4, N, 7};            // [2,1,3,null,4,null,7]

    TreeNode* root1 = buildTree(root1Arr, N);
    TreeNode* root2 = buildTree(root2Arr, N);

    return 0;
}