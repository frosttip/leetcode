# 844. Backspace String Compare

🟢 Easy 

Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

Example 1:
```
Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".
```

Example 2:
```
Input: s = "ab##", t = "c#d#"
Output: true
Explanation: Both s and t become "".
```

Example 3:
```
Input: s = "a#c", t = "b"
Output: false
Explanation: s becomes "c" while t becomes "b".
```

Constraints:
- 1 <= s.length, t.length <= 200
- s and t only contain lowercase letters and '#' characters.

Follow up: Can you solve it in O(n) time and O(1) space?

## Approach
### 快慢針
- **Parsing**: 
    這題使用的是快慢針，因為#代表的是刪除，所以需要有個指針指向#前一個位置才可以，以下進行說明，
    題目要求輸入兩個字串，其中會帶有數量不等的#刪除符號，要求刪除結束後要比對兩個字串是否一樣，
    所以一開始先宣告兩個字串各自的快慢針，
    ```
    int s_slow = 0;
    int s_fast = 0;
    int t_slow = 0;
    int t_fast = 0;
    ```
    一樣通過for迴圈將整個字串掃過，
    ```
    for(s_fast = 0;s_fast<s.size();s_fast++) {
    ```
    當掃到的字元不是刪除符號，就將快針的內容複製給慢針的位置，然後將慢針向後移動一格，
    ```
    if(s[s_fast] != '#') {
        s[s_slow++] = s[s_fast];
    }
    ```
    這裡要注意，假如碰到刪除號，這時候要先確認慢針是否在0的位置，假如是，就不要移動慢針，假如不是，將慢針向前移動一格，
    這樣下一次的動作，就會將內容複製到慢針的前一個位置，製造出一種刪除的情況。
    ```
    else {
        if(s_slow>0) {
            s_slow--;
        }
    }
    ```
    然後掃完整個字串後，要再通過另一個for迴圈，將慢針之後的內農都清空，假如沒清空，會造成比較的時候比對錯誤，
    ```
    for(int i = s_slow;i<s.size();i++) {
        s[i] = ' ';
    }
    ```
    另一個字串可以通過同樣的操作，來完成刪除的動作，
    最後，比較兩個字串的慢針大小，這時候的慢針大小所代表的是字串完成刪除後，剩餘的字元長度，我們需要取較長的字串長度來進行比較，
    這裡使用的比較function，是string在C++自帶的function，substr，輸入的參數前項是起始位置，後項是結束位置，
    通過==可以比較這兩個字串指定位置的內容是否相等。
    ```
    if(s_slow > t_slow) {
        return s.substr(0, s_slow) == t.substr(0, s_slow);
    }
    else {
        return s.substr(0, t_slow) == t.substr(0, t_slow);
    }
    ```
- **空間複雜度**: 
- **時間複雜度**: 