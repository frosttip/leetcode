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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        /*
        int lenA = 0;
        int lenB = 0;
        int gap = 0;
        ListNode* current;
        ListNode* currentA;
        ListNode* currentB;

        current = headA;
        while(current) {
            lenA++;
            current = current->next;
        }

        current = headB;
        while(current) {
            lenB++;
            current = current->next;
        }

        gap = abs(lenA-lenB);

        currentA = headA;
        currentB = headB;
        if(lenA>lenB) {
            while(gap--) {
                currentA = currentA->next;
            }
        }
        else {
            while(gap--) {
                currentB = currentB->next;
            }
        }

        while(currentA && currentB) {
            if(currentA == currentB) {
                return currentA;
            }
            currentA = currentA->next;
            currentB = currentB->next;
        }

        return NULL;
        */

       ListNode* tmpA;
       ListNode* tmpB;

       if(headA==NULL || headB==NULL) {
        return NULL;
       }

       tmpA = headA;
       tmpB = headB;

       while(tmpA || tmpB) {
        if(tmpA == tmpB) {
            return tmpA;
        }

        if(tmpA == NULL) {
            tmpA = headB;
        }
        else {
            tmpA = tmpA->next;
        }

        if(tmpB == NULL) {
            tmpB = headA;
        }
        else {
            tmpB = tmpB->next;
        }
       }

       return NULL;
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
    vector<int> nums1 = {4, 1};
    vector<int> nums2 = {5, 6, 1};
    vector<int> nums3 = {8, 4, 5};
    ListNode* common;
    ListNode* listA;
    ListNode* listB;
    ListNode* current;
    ListNode* ret;

    common = s.createList(nums3);
    listA = s.createList(nums1);
    listB = s.createList(nums2);

    current = listA;
    while(current->next) {
        current = current->next;
    }
    current->next = common;

    current = listB;
    while(current->next) {
        current = current->next;
    }
    current->next = common;

    s.printfList(listA);
    s.printfList(listB);
    ret = s.getIntersectionNode(listA, listB);
    cout<< ret->val <<endl;

    return 0;
}

