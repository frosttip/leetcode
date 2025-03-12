# 541. Reverse String II

🟢 Easy

Given a string s and an integer k, reverse the first k characters for every 2k characters counting from the start of the string.

If there are fewer than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and leave the other as original.

Example 1:
```
Input: s = "abcdefg", k = 2
Output: "bacdfeg"
```

Example 2:
```
Input: s = "abcd", k = 2
Output: "bacd"
```

Constraints:
- 1 <= s.length <= 104
- s consists of only lowercase English letters.
- 1 <= k <= 104

## Approach
### 
- **Parsing**: 
    題目給出一個string，要求每隔2k長度的字串，將前k個字元順序反轉，假如剩餘長度不足k個，則反轉剩餘部分。
    這題需要的是簡單的邏輯，
    這裡可以使用library提供的reverse function，我這裡使用的是自己寫的反轉function。
    ```
    void reverseTmp(std::string& s, int start, int end) {
        for(int i=start, j=end;i<j;i++, j--) {
            std::swap(s[i], s[j]);
        }
    }
    ```
    接著通過for迴圈，因為題目要求每隔2*k的字元再反轉，所以for的最後一個增長i值的邏輯就是直接每次都增加2*k即可。
    ```
    for(int i=0;i<s.size();i+=(2*k)) {
    ```
    接著根據題目判斷，只要當前index加上k沒有超過整個string大小，就反轉，只要超過了，那就反轉當前位置到最後一個字元就好，完成後直接返回s即可。
    ```
    if((i+k)<s.size()) {
        reverseTmp(s, i, i+k-1);
    }
    else {
        reverseTmp(s, i, s.size()-1);
    }
    ```
- **空間複雜度**: O(1)
- **時間複雜度**: O(N)