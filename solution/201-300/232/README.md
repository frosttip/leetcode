# 232. Implement Queue using Stacks

🟢 Easy

Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:

void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.
Notes:

You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.

Example 1:
```
Input
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 1, 1, false]

Explanation
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false
```

Constraints:
- 1 <= x <= 9
- At most 100 calls will be made to push, pop, peek, and empty.
- All the calls to pop and peek are valid.

## Approach
### 
- **Parsing**: 
    題目要求，使用stack來模擬queue的function。

    首先要區分queue跟stack的規則，stack是先進後出，像是一個罐子，最先進去的東西會放在最底下，後放進去的東西會放在越上方，所以要取東西出來時，就只能先從最上方拿，拿到最後才能拿到最底下的東西。
    queue會反過來，先進先出，像是一個水管，先進去的東西會進入到水管另一頭，拿取東西時也是從另一頭開始拿，所以依序放進去的東西，取出來的時候順序也會是相同的。

    為了用stack來模擬成queue，這裡會使用兩個stack，當push的時候都將內容推到stack1之中，但是要pop()或是peek的時候，就要將stack1的內容全部轉移到stack2，再從stack2中取值，
    這樣取東西的順序才會是相同的，

    開頭先宣告好要運作的兩個stack
    ```
    std::stack<int> st1;
    std::stack<int> st2;
    ```

    push的時候就將數值都推入st1中。
    ```
    void push(int x) {
        st1.push(x);
    }
    ```

    pop的時候就要判斷，st2是否是空的，假如是空的，那就將st1的東西全部都塞進st2中。
    ```
    int pop() {
        if(st2.empty()) {
            while(st1.size()!=0) {
                st2.push(st1.top());
                st1.pop();
            }
        }
        
        int ret = st2.top();
        st2.pop();

        return ret;
    }
    ```

    peek的操作跟pop是幾乎相同的，差別只在，pop需要丟棄數值，但是peek不用，只要回傳數值就好。
    ```
    int peek() {
        if(st2.empty()) {
            while(st1.size()!=0) {
                st2.push(st1.top());
                st1.pop();
            }
        }

        int ret = st2.top();

        return ret;
    }
    ```

    檢查queue之中是否為空，就要將兩個stack是否為空的結果結合起來再回傳即可。
    ```
    bool empty() {
        return st1.empty() && st2.empty();
    }
    ```
- **空間複雜度**: 
- **時間複雜度**: 