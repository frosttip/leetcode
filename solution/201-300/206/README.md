# 206. Reverse Linked List

 🟢 Easy

Given the head of a singly linked list, reverse the list, and return the reversed list.

Example 1:

![alt text](image.png)
```
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
```

Example 2:

![alt text](image-1.png)
```
Input: head = [1,2]
Output: [2,1]
```

Example 3:
```
Input: head = []
Output: []
```

Constraints:
- The number of nodes in the list is the range [0, 5000].
- -5000 <= Node.val <= 5000

## Approach
### 
- **Parsing**: 
    這題要求要反轉link list，
    首先，建立三個pointer，反轉的基礎就是要有辦法將當前的節點的next，指向前一個節點，並且在指完之後，還有辦法移動到下一個節點，
    上面的描述已經寫出需要幾個pointer來完成了，前一個節點，當前節點，下一個節點。
    ```
    ListNode* prev;
    ListNode* current;
    ListNode* ready;
    ```
    在一開始，current指向head，而prev就可以指向nullptr，因為反轉後，head就會是尾巴，而他的前一個節點就會是nullptr，
    ```
    prev = nullptr;
    current = head;
    ```
    通過while來運作pointer，當current指向nullptr的時候就跳出，
    ```
    while(current) {
    ```
    以下模擬第一次跑的時候的狀況，用範例一做示範，
    prev指向nullptr，current指向head(1)，ready指向2，
    本來current的next指向2，這時候將他轉向prev指向nullptr，
    接著將prev移動到current的位置，所以這時候，prev->val = 1，current->val = 1，兩個pointer都在同個節點上。
    最後將current移動到ready的位置，變成current->val = 2，
    最終會呈現，
    prev            current             ready
    nullptr            1         ==>      2

    prev            current             ready
    nullptr   <==      1                   2      

                prev & current          ready
    nullptr   <==      1                   2 

                     prev           current & ready
    nullptr   <==      1                   2  
    開頭的第一個節點方向已經被反轉了。
    ```
    ready = current->next;
    current->next = prev;
    prev = current;
    current = ready;
    ```
    接著模擬最後結束的流程，
    prev還停留在4，current跟next停留在5，
    prev          current & ready
    4                    5          ==>     nullptr

    prev              current                ready
    4                    5          ==>     nullptr

    prev              current                 ready
    4        <==         5                   nullptr      

                  prev & current              ready
    4        <==         5                   nullptr 

                        prev              current & ready
    4        <==         5                   nullptr  
    到這裡反轉已經完成，最後只需要回傳prev的指標就好了。  
- **空間複雜度**: O(1)
- **時間複雜度**: O(N)