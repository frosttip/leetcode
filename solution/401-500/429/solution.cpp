#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
    int val;
    vector<Node*> children;

    Node() {}
    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ret;

        if(root==nullptr) {
            return ret;
        }

        queue<Node*> q;

        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            vector<int> buf;

            for(int i=0;i<size;i++) {
                Node* curr = q.front();
                q.pop();

                buf.push_back(curr->val);

                for(int l=0;l<curr->children.size();l++) {
                    q.push(curr->children[l]);
                }
            }   

            ret.push_back(buf);
        }

        return ret;
    }
private:
};

int main(int argc, char* argv[]) {
    Solution s;
    Node* root = new Node(1);
    vector<Node*> buf;
    vector<vector<int>> ret;

    for(int i=2;i<=4;i++) {
        Node* tmp = new Node(i);
        buf.push_back(tmp);
    }

    root->children = buf;

    buf.clear();

    for(int i=5;i<=6;i++) {
        Node* tmp = new Node(i);
        buf.push_back(tmp);
    }

    root->children[0]->children = buf;

    ret = s.levelOrder(root);

    cout<<"[ ";
    for(int i=0;i<ret.size();i++) {
        cout<<"[";
        for(int l=0;l<ret[i].size();l++) {
            cout<<ret[i][l]<<" ";
        }
        cout<<"]";
    }
    cout<<" ]";
    cout<<endl;

    return 0;
}