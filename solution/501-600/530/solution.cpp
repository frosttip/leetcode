#include <iostream>
#include <vector>
#include <stack>
#include <iomanip>  // for std::setw

using namespace std;

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
    int getMinimumDifference(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* curr = root;
        TreeNode* prev = nullptr;
        int min_val = INT_MAX;

        while(curr!=nullptr || !st.empty()) {
            if(curr!=nullptr) {
                st.push(curr);
                curr=curr->left;
            }
            else {
                curr = st.top();
                st.pop();

                if(prev != nullptr) {
                    min_val = min(min_val, curr->val-prev->val);
                }

                prev = curr;
                curr = curr->right;
            }
        }

        return min_val;
    }
private:
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

void printTree(TreeNode* root, int depth = 0) {
    if (!root) return;

    // 先印右子樹，讓右邊的節點出現在上面
    printTree(root->right, depth + 1);

    // 印出目前節點，前面補一些空白表示深度
    cout << string(depth * 4, ' ') << root->val << "\n";

    // 再印左子樹
    printTree(root->left, depth + 1);
}

int main(int argc, char* argv[]) {
    Solution s;
    vector<int> root_v = {1,0,48,N,N,12,49};
    TreeNode* root = buildTree(root_v);

    cout<<s.getMinimumDifference(root)<<endl;

    return 0;
}