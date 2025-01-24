#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode* next): val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* current;

        dummyHead->next = head;
        current = dummyHead;
        while(current->next) {
            if(current->next->val == val) {
                ListNode* tmp = current->next;
                current->next = current->next->next;
                delete(tmp);
                tmp = nullptr;
            }
            else {
                current = current->next;
            }
        }

        head = dummyHead->next;
        delete(dummyHead);
        dummyHead = nullptr;

        return head;
    }
};

ListNode* createList(vector<int>& buf) {
    ListNode* head= new ListNode(buf[0]);
    ListNode* current;

    current = head;
    for(int i=1;i<buf.size();i++) {
        current->next = new ListNode(buf[i]);
        current = current->next;
    }

    return head;
}

void printList(ListNode* head) {
    ListNode* tmp;

    tmp = head;

    while(tmp) {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout<<endl;
}

int main(int argc, char* argv[]) {
    Solution s;
    ListNode* head;
    vector<int> buf = {1,2,6,3,4,5,6};
    ListNode* ret;

    head = createList(buf);
    printList(head);

    ret = s.removeElements(head, 1);
    printList(ret);

    return 0;
}