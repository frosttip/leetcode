#include <iostream>

using namespace std;

class MyLinkedList {
public:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(): val(0), next(nullptr) {}
        ListNode(int x): val(x), next(nullptr) {}
        ListNode(int x, ListNode* next): val(x), next(next) {}
    };

    MyLinkedList() {
        dummyHead = new ListNode();
        listCnt = 0;
    }
    
    int get(int index) {
        if( index < 0 || index > (listCnt-1) ) {
            return -1;
        }

        ListNode* current = dummyHead;
        while(index--) {
            current = current->next;
        }

        return current->next->val;
    }
    
    void addAtHead(int val) {
        ListNode* tmp = new ListNode(val);

        tmp->next = dummyHead->next;
        dummyHead->next = tmp;
        listCnt++;
    }
    
    void addAtTail(int val) {
        ListNode* current = dummyHead;

        while(current->next) {
            current = current->next;
        }

        current->next = new ListNode(val);
        listCnt++;
    }
    
    void addAtIndex(int index, int val) {
        if( index < 0 || index > listCnt ) {
            return;
        }

        ListNode* current = dummyHead;

        while(index--) {
            current = current->next;
        }

        ListNode* tmp = new ListNode(val);
        tmp->next = current->next;
        current->next = tmp;
        listCnt++;
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index > (listCnt - 1)) {
            return;
        }

        ListNode* current = dummyHead;

        while(index--) {
            current = current->next;
        }

        ListNode* tmp = current->next;
        current->next = current->next->next;
        delete(tmp);
        tmp = nullptr;
        listCnt--;
    }

    void printfList() {
        ListNode* current = dummyHead;

        while(current->next) {
            cout << current->next->val << " ";
            current = current->next;
        }
        cout << endl;
    }
private:
    ListNode* dummyHead;
    int listCnt;
};

int main(int argc, char* argv[]) {
    MyLinkedList list;

    list.addAtHead(1);
    list.addAtHead(2);
    cout<<list.get(1)<<endl;
    list.addAtTail(3);
    list.deleteAtIndex(3);
    
    list.printfList();

    list.deleteAtIndex(1);

    cout<<list.get(1)<<endl;

    list.printfList();

    return 0;
}