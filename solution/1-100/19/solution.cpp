#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode* next): val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode(0, head);
        ListNode* fast;
        ListNode* slow;

        slow = dummyHead;
        fast = dummyHead->next;
        while(n--) {
            fast = fast->next;
        }

        while(fast) {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* tmp = slow->next;
        slow->next = slow->next->next;
        head = dummyHead->next;
        delete(dummyHead);
        delete(tmp);

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
    vector<int> nums = {1, 2};
    Solution s;
    ListNode* head;
    ListNode* ret;

    head = s.createList(nums);
    s.printfList(head);
    ret = s.removeNthFromEnd(head, 1);
    s.printfList(ret);

    return 0;
}