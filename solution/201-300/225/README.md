# 225. Implement Stack using Queues

🟢 Easy 

Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).

Implement the MyStack class:

void push(int x) Pushes element x to the top of the stack.
int pop() Removes the element on the top of the stack and returns it.
int top() Returns the element on the top of the stack.
boolean empty() Returns true if the stack is empty, false otherwise.
Notes:

You must use only standard operations of a queue, which means that only push to back, peek/pop from front, size and is empty operations are valid.
Depending on your language, the queue may not be supported natively. You may simulate a queue using a list or deque (double-ended queue) as long as you use only a queue's standard operations.

Example 1:
```
Input
["MyStack", "push", "push", "top", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 2, 2, false]

Explanation
MyStack myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // return 2
myStack.pop(); // return 2
myStack.empty(); // return False
```

Constraints:
- 1 <= x <= 9
- At most 100 calls will be made to push, pop, top, and empty.
- All the calls to pop and top are valid.

## Approach
### 
- **Parsing**: 
    題目要求使用queue來模擬stack的功能。

    這題是232的相反，只是思路需要扭轉一下，
    queue的結構是先進先出，但是stack是先進後出，所以做法可以在push的時候下功夫，只要每push一個數值進來，先記錄push前queue中有幾個數值，當新值放入到queue之後，只要使用front將數值取出，
    再接著塞回去queue中，重複push前的size次數，queue中的數值順序就會跟stack一樣了。

    首先宣告一個用來存放數值的queue。
    ```
    std::queue<int> que;
    ```

    接著模擬push，就像前面提到的，先記錄queue的size，接著才把新值push進queue中，再來將數值取出後再填入，重複size次，整個queue的內容順序就會跟stack一模一樣。
    ```
    void push(int x) {
        int size = que.size();
        int tmp = 0;

        que.push(x);

        while(size--) {
            tmp = que.front();
            que.pop();
            que.push(tmp);
        }
    }
    ```

    接著的pop，top還有empty，其實都不需要多做事情，單純照用queue的function即可。
    ```
    int pop() {
        int ret = que.front();
        que.pop();

        return ret;
    }

    int top() {
        int ret = que.front();

        return ret;
    }

    bool empty() {
        return que.empty();
    }
    ```
- **空間複雜度**: 
- **時間複雜度**: 