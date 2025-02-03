# 142. Linked List Cycle II

🟠 Medium

Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.

Example 1:

![alt text](image.png)
```
Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.
```

Example 2:

![alt text](image-1.png)
```
Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.
```

Example 3:

![alt text](image-2.png)
```
Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.
```

Constraints:
- The number of the nodes in the list is in the range [0, 104].
- -105 <= Node.val <= 105
- pos is -1 or a valid index in the linked-list.

## Approach
### 快慢針
- **Parsing**: 
    這題要運用到兩格概念一個是快慢針，快慢針可以用來判斷linked list是否是個迴圈，另一個概念是數學推導。
    以下是假設的迴圈list，從1開始，然後到數字8之後接續到數字3，理所當然這就會是個迴圈。
    
    ```
    1 - 2 - 3 - 4 - 5
            |       |
            8 - 7 - 6
    ```

    首先，先通過快慢針來找出這個list是否存在迴圈，宣告兩個指針，fast與slow，快針每次移動都會移動兩格，慢針每次移動只會移動一格，
    ```
    ListNode* fast = head;
    ListNode* slow = head;
    ```
    這裡通過while迴圈來判斷是否繼續移動快針，因為快針要一次移動兩格，所以while的跳出條件就需要判斷快針當前是否為空，或是快針的next是否為空，假如快針的next為空，就不可以繼續移動，這樣就會跑到未知位址，觸發hardfault。
    假如在移動過程中，發現快針與慢針相等，代表這個list中存在迴圈。
    ```
    while(fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;

        if(fast == slow) {
            break;
        }
    }
    ```
    以下進行模擬，可以看到，在快針第二次抵達7的時候，慢針也抵達7了，快慢針就是如此判斷迴圈。

    val  |  slow   |   fast
    -----|-------|-------
    val  |   1   |   1
    val  |   2   |   3
    val  |   3   |   5
    val  |   4   |   7
    val  |   5   |   3
    val  |   6   |   5
    val  |   7   |   7

    離開while之後，還需要判斷到底是因為list沒有迴圈而離開還是因為找到迴圈才離開，所以這裡要判斷fast跟fast->next是否等於NULL，假如符合，那代表沒有迴圈，返回NULL。
    ```
    if(fast == NULL || fast->next == NULL) {
        return NULL;
    }
    ```

    接著如何找出迴圈的入口，這裡通過以下過程推算，
    從起點到迴圈入口的距離我們稱為'L'。
    從迴圈入口到快慢針重合的點我們稱為'X'。
    迴圈的總長度我們稱為'C'。
    走過迴圈的倍數我們稱為'K'。
    通過數學式來模擬快慢針走過的路徑如下，
    2 * (慢針走的距離) = 快針走的距離
    2 * ( L + X ) = L + X + KC
    L + X = KC
    L = KC - X
    濃縮到最後，公式就會變成L = KC - X，K是快針可能因為走兩倍的距離所以會繞迴圈多次，以我們前面的例子為例，快針進入迴圈後會再走完一圈才會遇到慢針，所以這裡的K會是1，
    但是，就算K是更大的數值，也不影響，因為那都是在同個圈圈內走過的重複路徑，所以可以不看K值，最終公式會是
    L = C - X

    以下面這個list為例，L = 2，X = 4，C = 6。
    ```
    1 - 2 - 3 - 4 - 5
            |       |
            8 - 7 - 6
    ```
    所以按造公式，2(L) = 6(C) - 4(X)
    當快慢針兩點已經重合之後，我們只要將慢針挪迴起點，然後讓快針與慢針兩個都在當前位置，一步一步前進，就會在迴圈的起點重合，也就是3，
    以下就是實作，最後回傳重合的點就好。
    ```
    slow = head;

    while(slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    ```
- **空間複雜度**: O(1)
- **時間複雜度**: O(N)