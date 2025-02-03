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
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;

            if(fast == slow) {
                break;
            }
        }

        if(fast == NULL || fast->next == NULL) {
            return NULL;
        }

        slow = head;

        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }

    ListNode* createList(vector<int>& nums) {
        ListNode* head = new ListNode(nums[0]);
        ListNode* current;

        current = head;

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
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8};
    ListNode* head;
    ListNode* ret;

    head = s.createList(nums);
    s.printfList(head);

    ListNode* current = head;
    ListNode* tmp = head;
    for(int i=0;i<7;i++) {
        current = current->next;
        if(i<2) {
            tmp = tmp->next;
        }
    }
    // cout<<current->val<<endl;
    // cout<<tmp->val<<endl;
    current->next = tmp;

    ret = s.detectCycle(head);
    cout<<ret->val<<endl;

    return 0;
}