#include <iostream>
#include <vector>
#include <queue>
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

const int N = INT_MIN;

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            TreeNode* curr;

            for(int i=0;i<size;i++) {
                curr = q.front();
                q.pop();

                if(curr->val == val) {
                    return curr;
                }

                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
        }

        return nullptr;
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
    vector<int> rootVal = {4,2,7,1,3};
    TreeNode* root = s.buildTree(rootVal, N);

    s.printTree(root);

    TreeNode* ret = s.searchBST(root, 2);

    s.printTree(ret);

    return 0;
}