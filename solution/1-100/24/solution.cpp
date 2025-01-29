#include <iostream>
#include <vector>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(): val(0), next() {}
    ListNode(int x): val(x), next() {}
    ListNode(int x, ListNode* next): val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // ListNode* current;
        // ListNode* ready;
        // int tmp;

        // current = head;
        // while(current) {
        //     if(current->next==nullptr) {
        //         break;
        //     }

        //     ready = current->next;

        //     tmp = current->val;
        //     current->val = ready->val;
        //     ready->val = tmp;

        //     if(current->next->next) {
        //         current = current->next->next;
        //     }
        //     else {
        //         break;
        //     }
        // }

        // return head;

        ListNode* dummyHead = new ListNode(0, head);
        ListNode* current;
        ListNode* tmp1;
        ListNode* tmp2;

        current = dummyHead;
        while(current->next!=nullptr && current->next->next!=nullptr) {
            tmp1 = current->next;
            tmp2 = current->next->next->next;

            current->next = current->next->next;
            current->next->next = tmp1;
            current->next->next->next = tmp2;

            current = current->next->next;
        }

        head = dummyHead->next;
        delete(dummyHead);
        return head;
    }

    ListNode* createList(vector<int>& nums) {
        ListNode* head = new ListNode(nums[0]);
        ListNode* current = head;

        for(int i=1;i<nums.size();i++) {
            current->next = new ListNode(nums[i]);
            current = current->next;
        }

        return head;
    }

    void printfList(ListNode* head) {
        ListNode* current = head;

        while(current) {
            cout<<current->val<<" ";
            current = current->next;
        }
        cout<<endl;
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    vector<int> nums = {1, 2, 3};
    ListNode* head;
    ListNode* ret;

    head = s.createList(nums);
    s.printfList(head);

    ret = s.swapPairs(head);
    s.printfList(ret);

    return 0;
}
