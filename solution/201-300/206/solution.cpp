
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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev;
        ListNode* current;
        ListNode* ready;

        prev = nullptr;
        current = head;

        while(current) {
            ready = current->next;
            current->next = prev;
            prev = current;
            current = ready;
        }

        return prev;
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
    vector<int> nums = {1, 2, 3, 4, 5};
    ListNode* head;

    head = s.createList(nums);
    cout<<"Create finish"<<endl;
    s.printfList(head);

    head = s.reverseList(head);
    s.printfList(head);

    return 0;
}