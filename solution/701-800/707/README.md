# 707. Design Linked List

 🟠 Medium

esign your implementation of the linked list. You can choose to use a singly or doubly linked list.
A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node.
If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.

Implement the MyLinkedList class:

- MyLinkedList() Initializes the MyLinkedList object.
- int get(int index) Get the value of the indexth node in the linked list. If the index is invalid, return -1.
- void addAtHead(int val) Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
- void addAtTail(int val) Append a node of value val as the last element of the linked list.
- void addAtIndex(int index, int val) Add a node of value val before the indexth node in the linked list. If index equals the length of the linked list, the node will be appended to the end of the linked list. If index is greater than the length, the node will not be inserted.
- void deleteAtIndex(int index) Delete the indexth node in the linked list, if the index is valid.

Example 1:
```
Input
["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", "deleteAtIndex", "get"]
[[], [1], [3], [1, 2], [1], [1], [1]]
Output
[null, null, null, null, 2, null, 3]

Explanation
MyLinkedList myLinkedList = new MyLinkedList();
myLinkedList.addAtHead(1);
myLinkedList.addAtTail(3);
myLinkedList.addAtIndex(1, 2);    // linked list becomes 1->2->3
myLinkedList.get(1);              // return 2
myLinkedList.deleteAtIndex(1);    // now the linked list is 1->3
myLinkedList.get(1);              // return 3
```

Constraints:
- 0 <= index, val <= 1000
- Please do not use the built-in LinkedList library.
- At most 2000 calls will be made to get, addAtHead, addAtTail, addAtIndex and deleteAtIndex.

## Approach
### 
- **Parsing**: 
    這題要求完成幾個基本的linklist操作function，基本上所有功能都涵蓋到了，
    1. 取得特定位置數值。
    2. 新增數值在頭。
    3. 新增數值在尾巴。
    4. 新增數值在指定位置。
    5. 刪除指定位置。
    以下開始進行解析，
    首先建立linklist結構，
    ```
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(): val(0), next(nullptr) {}
        ListNode(int x): val(x), next(nullptr) {}
        ListNode(int x, ListNode* next): val(x), next(next) {}
    };
    ```
    接著建立private變數，dummyHead是用來建立整個list的假頭，方便後續操作，listCnt用來計算現在整個list總共有幾個節點了，這個計算並不包含dummyHead。
    ```
    private:
        ListNode* dummyHead;
        int listCnt;
    ```
    接著是建立這個class時，需要初始化的東西，這裡將dummyHead建立起來，並且初始化listCnt為0。
    ```
    MyLinkedList() {
        dummyHead = new ListNode();
        listCnt = 0;
    }
    ```
    get function用來取得特定位置的數值，首先要判斷index是否合理，不能超過list當前範圍，然後建立一個pointer current來指向dummyHead，
    這裡先想像一下，
    假如list已經有兩個數值了，[1, 2]，第一個節點內容是1，第二個節點內容是2，所以listCnt會是2，
    假如輸入的index為2，首先list只有兩個，所以index只能指向0或是1，2大於目前的listCnt-1 = 2-1，所以不合理，返回。
    假如輸入的index為1，因為current一開始指向的是dummyHead，當通過while的條件，index = 1只會運行一次，所以指針目前指向dummyHead的下一個，也就是index 0的位置，
    所以將0的下一個節點的數字返回即可。
    假如輸入的index為0，current指向的是dummyHead，這時候while會返上跳出，而current指向的還是dummyHead，這時候下一個節點就是1的位置，也是我們要的答案。
    ```
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
    ```
    新增頭跟尾數值都沒什麼難度，頭只要新增節點在dummyhead後面就可以了，尾巴只要不斷移動指針，直到current的next指向null，就代表到尾巴了，只要記得超做完之後要把listCnt加一。
    ```
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
    ```
    新增節點其實跟前面差不多，通過遞減index，找到位置後再操作就好了，只是要注意，index不只不能小於0，但也不能大於lisCnt，
    前面的判斷都是不能大於listCnt-1，這裡不同的原因是因為，index也可以指定到list尾巴，所以最多可以比list當前的節點大一的位置。
    ```
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
    ```
    最後是刪除節點，同樣通過操作current指針，遞減index後，移動current的next指針就可以完成刪減動作。
    ```
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
    ```
- **空間複雜度**: 
- **時間複雜度**: 