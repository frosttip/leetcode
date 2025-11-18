#include <iostream>
#include <vector>

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

class Solution{
public:
    TreeNode* help(vector<int>& nums, int start, int end) {
        if(start > end) {
            return nullptr;
        }

        int max = INT_MIN;
        int max_idx = 0;

        for(int i=start;i<=end;i++) {
            if(nums[i] > max) {
                max = nums[i];
                max_idx = i;
            }
        }

        TreeNode* root = new TreeNode(max);

        root->left = help(nums, start, max_idx-1);
        root->right = help(nums, max_idx+1, end);

        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return help(nums, 0, nums.size()-1);
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
    TreeNode* root = nullptr;
    vector<int> nums = {3,2,1,6,0,5};

    root = s.constructMaximumBinaryTree(nums);
    s.printTree(root);

    return 0;
}