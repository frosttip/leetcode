#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node(): val(0), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int x): val(x), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int x, Node* left, Node* right, Node* next): val(x), left(left), right(right), next(next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if(root==nullptr) {
            return root;
        }

        queue<Node*> q;
        
        q.push(root);

        while(!q.empty()) {
            Node* curr;
            Node* next;
            int size = q.size();

            for(int i=0;i<size;i++) {
                curr = q.front();
                q.pop();

                if(i!=(size-1)) {
                    next = q.front();
                    curr->next = next;
                }
                else {
                    curr->next = nullptr;
                }

                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
        }

        return root;
    }
private:
};

int main(int argc, char* argv[]) {
    Solution s;
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Node* ret = s.connect(root);

    return 0;
}