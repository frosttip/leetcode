#include <iostream>
#include <queue>
#include <vector>

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
};

class Solution{
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> ret;

        if(root==NULL) {
            return ret;
        }

        std::queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            std::vector<int> tmp;
            TreeNode* curr;

            for(int i=0;i<size;i++) {
                curr = q.front();
                q.pop();

                tmp.push_back(curr->val);

                if(curr->left) {
                    q.push(curr->left);
                }

                 if(curr->right) {
                    q.push(curr->right);
                }
            }

            ret.push_back(tmp);
        }

        return ret;
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    TreeNode root = TreeNode(3);
    root.left = new TreeNode(9);
    root.right = new TreeNode(20);
    root.right->left = new TreeNode(15);
    root.right->right = new TreeNode(7);

    std::vector<std::vector<int>> ret;

    ret = s.levelOrder(&root);

    std::cout<<"[";
    for(int i=0;i<ret.size();i++) {
        std::cout<<"[";
        for(int l=0;l<ret[i].size();l++) {
            std::cout<<ret[i][l]<<" ";
        }
        std::cout<<"]"<<",";
    }
    std::cout<<"]"<<std::endl;

    return 0;
}
