# 20. Valid Parentheses

🟢 Easy

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.

Example 1:
```
Input: s = "()"

Output: true
```

Example 2:
```
Input: s = "()[]{}"

Output: true
```

Example 3:
```
Input: s = "(]"

Output: false
```

Example 4:
```
Input: s = "([])"

Output: true
```

Constraints:
- 1 <= s.length <= 104
- s consists of parentheses only '()[]{}'.

## Approach
### Stack
- **Parsing**: 
    題目給出一個string，內涵各種括號，要求確認這些括號的組合是否符合兩兩相對，數學式上的配對。

    這題的解法可以使用stack，因為一個左括號必定要搭配一個右括號，另外還要考慮到括號在數學式上必須要有順序，不能交錯配對，所以不能單純計算左括號幾個配上幾個右括號，
    stack的特性，先進後出，假如把{[(三個括號塞進去stack中，那出來的順序就會是先(，第二個是[，最後才會是{，只要提取出來後搭配不起來，那就可以直接返回false，
    或是換個思路，當碰到左括號，那就把對應的右括號塞進stack，然後使用top取字元時，只要不符合就可以回傳false，
    另外還需要考慮coner case，假如只填入其中一邊的括號，只填左括號，不填右括號，最後判斷需要stack中是否為空，
    假如只填右括號，這樣比對過程中會發現stack中都是空的這種情況也必須回false。

    一開始先建立一個用來儲存括號的stack，
    ```
    std::stack<char> st;
    ``` 

    通過for迴圈掃過整個string。
    ```
    for(int i=0;i<s.size();i++) {
    ```

    掃過整個string的過程中，遇到左括號，就將相對應的右括號填入stack中，
    ```
    if(s[i] == '(') {
        st.push(')');
    }
    else if(s[i] == '[') {
        st.push(']');
    }
    else if(s[i] == '{') {
        st.push('}');
    }
    ```

    當遇到右括號，這時候要判斷兩種狀況，首先是stack是否為空，那就代表目前碰到的右括號是孤單的，沒有對應的左括號，
    第二種狀況是取出來的括號並不相等，代表配對失敗，這兩種情況都要回傳false。
    ```
    else if(st.empty() || st.top() != s[i]) {
        return false;
    }
    ```

    最後的狀況是stack中取出來的括號對應的上當前的右括號，所以直接丟棄這個括號就好。
    ```
    else {
        st.pop();
    }
    ```

    最後，當已經比對完成，還要確認stack是否為空，假如為空才代表所有括號都已經配對完成，假如不為空，根據前面的流程，那就還會有殘留的左括號沒有被配對到，所以要回傳false，
    那採用empty就可以得到相同的判斷結果。
    ```
    return st.empty();
    ```
- **空間複雜度**: O(N)
- **時間複雜度**: O(N)