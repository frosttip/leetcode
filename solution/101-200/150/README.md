# 150. Evaluate Reverse Polish Notation

🟠 Medium

You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:
- The valid operators are '+', '-', '*', and '/'.
- Each operand may be an integer or another expression.
- The division between two integers always truncates toward zero.
- There will not be any division by zero.
- The input represents a valid arithmetic expression in a reverse polish notation.
- The answer and all the intermediate calculations can be represented in a 32-bit integer.

Example 1:
```
Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
```

Example 2:
```
Input: tokens = ["4","13","5","/","+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
```

Example 3:
```
Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
Output: 22
Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
```

Constraints:
- 1 <= tokens.length <= 104
- tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the range [-200, 200].

## Approach
### Stack
- **Parsing**: 
    這題其實是要搞懂後序表達式的做法，其原理是，碰到運算子的時候，將運算子的前兩個數字做運算，然後再取代其位置，基本上就是這麼操作。

    所以這題要使用的解題方法是stack，通過stack將運算子之外的數字壓入stack中，當碰到運算子，取出兩個stack中的數值，與運算子做運算，
    要注意的是，取出來的第一個數字要做為後項，第二個數字要作為前項，運算完成後再壓回去stack中，直到整個運算完成後，將stack中剩下的
    數字返回即可。

    先宣告一個stack，用來做運算。
    ```
    std::stack<int> st;
    ```

    通過for迴圈掃過整個vector，
    ```
    for(int i=0;i<tokens.size();i++) {
    ```

    首先判斷string是否為運算子，也就是加減乘除，不是的話，就通過stoi將字串轉為數字，並壓入stack中。
    ```
    if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/") {
        int tmp = 0;
        tmp = std::stoi(tokens[i]);
        st.push(tmp);
    }
    ```

    接著照前面所說，將stack中的內容取出，第一個做為後項，賦予last，第二個作為前項，賦予first，
    ```
    int last = 0;
    int first = 0;
    int result = 0;

    last = st.top();
    st.pop();
    first = st.top();
    st.pop();
    ```

    然後根據運算子的內容做完運算後將結果壓回去stack中。
    ```
    if(tokens[i][0] == '+') {
        result = first + last;
    }
    else if(tokens[i][0] == '-') {
        result = first - last;
    }
    else if(tokens[i][0] == '*') {
        result = first * last;
    }
    else if(tokens[i][0] == '/') {
        result = first / last;
    }

    st.push(result);
    ```

    當整個運算都結束後，將stack中最後剩下的數值返回就好。
    ```
    return st.top();
    ```
- **空間複雜度**: 
- **時間複雜度**: 