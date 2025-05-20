# 1047. Remove All Adjacent Duplicates In String

🟢 Easy 

You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.

We repeatedly make duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.

Example 1:
```
Input: s = "abbaca"
Output: "ca"
Explanation: 
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".
```

Example 2:
```
Input: s = "azxxzy"
Output: "ay"
```

Constraints:
- 1 <= s.length <= 105
- s consists of lowercase English letters.

## Approach
### Stack
- **Parsing**: 
    這題給出一個string，要求去除其中連續兩個相同的字元，連續去除，直到最後剩餘不再有兩個連續字元的字串再返回。

    這題解題的方向我採用stack來解，透過for迴圈掃過整個string，掃的過程中，比對當前的字元是否跟stack中的一樣，相同的話就將其去除，不同的話就填入stack，
    因為stack先進後出的模式，假如相鄰的兩個字元是相同的，前一個字元被填入stack後，後一個字元被掃到時，比對時就會配對成功，這時候就將字元從stack中去除，
    而在最後，當stack中不為空，將其中的內容依造順序取出，放入另一個字串，最後再將字串反轉，即可得到正確順序的答案。

    首先宣告用來運作的stack，還有回傳的字串。
    ```
    std::stack<char> st;
    std::string ret;
    ```

    接著通過for迴圈掃過整個字串，
    ```
    for(int i=0;i<s.size();i++) {
    ```

    接著判斷當前遇到的字元，先判斷stack中是否有值，沒有值就直接跳過這個判斷式，代表沒有可以配對的字元，判斷stack是否有值必須寫在前面，if中的判斷式是有
    先後的，接著再取出stack最上方的內容跟當前掃到的內容比對，相同的話就將stack中的數值拋棄。
    ```
    if(!st.empty() && st.top() == s[i]) {
        st.pop();
    }
    ```

    當stack中沒有樹值或是比對後無法成對的字元，就將其填入stack中。
    ```
    else {
        st.push(s[i]);
    }
    ```

    當掃完整個字串後，stack不為空的話，將其中的字元都取出，並賦予到回傳的字串，
    ```
    while(st.size()) {
        ret += st.top();
        st.pop();
    }
    ```

    因為stack是先進後出，所以字串的內容會是顛倒的，所以需要再次反轉才能得到正確的順序。
    ```
    std::reverse(ret.begin(), ret.end());
    ```
- **空間複雜度**: O(N)
- **時間複雜度**: O(N)