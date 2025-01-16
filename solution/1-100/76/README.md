# 76. Minimum Window Substring

🔴 Hard

Given two strings s and t of lengths m and n respectively, return the minimum window 
substring
 of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

 

Example 1:
```
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
```

Example 2:
```
Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
```

Example 3:
```
Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
```

Constraints:
- m == s.length
- n == t.length
- 1 <= m, n <= 105
- s and t consist of uppercase and lowercase English letters.

## Approach
### Slide window
- **Parsing**: 
    題目會給予兩個字串，t字串是類似一個字典的概念，要找出s字串中，包含所有t字串的最小子字串，t字串中假如有重複的字也需要計算。
    這題需要稍微思考一下怎麼做到，這裡是使用unordered_map來輔助，以下進行說明，
    首先宣告用來記錄下所有t字串中的unordered_map，其實也可以用一般的vector紀錄，不過這裡我選擇用unordered_map，
    ```
    unordered_map<int, int> map;
    ```
    接著宣告slide windows的精隨，起點終點指針，
    ```
    int left = 0, right = 0;
    ```
    因為題目要求找出最小的子字串，所以需要一個變數來記錄最小字串長度，
    ```
    int minlen = INT_MAX;
    ```
    還有因為要回傳的是子字串，所以需要另一個變數來記錄最短字串的起始位置，
    ```
    int startIdx = 0;
    ```
    這個變數是用來計算，s字串中有幾個t字串中的字母，通過倒扣的方式，來確認是否有找到所有t字串中的字母。
    ```
    int count = t.size();
    ```
    變數宣告完成，接著開始紀錄t字串中的字母，通過for loop來記錄所有字母數量，
    ```
    for(int i=0;i<t.size();i++) {
        map[t[i]]++;
    }
    ```
    接著再開始進行slide window的操作，通過for迴圈來改變right指針位置，
    ```
    for(right = 0;right<s.size();right++) {
    ``` 
    這個判斷式做的是，將s[right]當前的字母，假如是t中的字母，那map中他的數字就會是大於0，那就將count減一，只要count減到0，就代表所有t中的字母都找到了，而不在t中的字母，雖然也會被新增到map中，但是他的數值初始就會是0，所以不會通過判斷式，並且經過減一後會變成是-1。
    ```
    if(map[s[right]]-- > 0) {
        count--;
    }
    ``` 
    當count為0，那就代表t中的字母都找到了，這時候就可以去檢查這一段的子字串長度是否可以被記錄。將while迴圈的條件設定為count==0，只要所有t字母都還存在子字串，就不會出來，
    ```
    while(count==0) {
    ```
    只要終點減去起點再加一小於minlen，那就將其記錄下來，記錄下當前的起點，也就是left的位置在startIdx，還有取代minlen。
    ```
    if(right - left + 1 < minlen) {
        startIdx = left;
        minlen = right - left + 1;
    }
    ```
    而這裡就要移動left起點的位置，當移動後超過t中的字母，因為在while迴圈外已經處理過，只有在t中的字母的數值會是等於0，其他字母都會是小於0，所以符合的話就會進入判斷式，將count加一後，就會跳出while迴圈，而假如移動left當前的位置不式t中的字母，因為數值不等於0，就不會進入判斷式。
    ```
    if(map[s[left++]]++ == 0) {
        count++;
    }
    ```
    最後，回傳的時候先確認minlen是否還是維持初始值，假如是的話回傳空字串，否的話，通過s的substr函式，通過記錄下來的startIdx跟minlen將子字串回傳。
    ```
    return minlen==INT_MAX? "":s.substr(startIdx, minlen);
    ```

- **空間複雜度**: O(t.size)
- **時間複雜度**: O(s.size + t.size)