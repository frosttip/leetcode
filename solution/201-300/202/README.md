# 202. Happy Number

🟢 Easy

Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.

Example 1:
```
Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
```

Example 2:
```
Input: n = 2
Output: false
```

Constraints:
- 1 <= n <= 231 - 1

## Approach
### 
- **Parsing**: 
    題目輸入一個數字，詢問這個數字是否是快樂數，快樂數的定義是，這個數的每一位數的平方相加後，不斷累加，最後是否會等於1。
    這題乍看之下，只需要正常的一直運算就好，但是有個問題，因為某些數字可能會出現無限迴圈，永遠沒辦法把數字縮小到最後，
    所以要加上一個unordered_ser，用來記錄曾經出現過的數字，只要數字開始重複了，就要回傳false，
    所以一開始先宣告兩個變數，第一個是用來計算的sum，第二個是紀錄曾經出現過的數字的unordered_set，
    ```
    int sum = 0;
    std::unordered_set<int> map;
    ```
    接著使用while迴圈進行連續計算，
    ```
    while(1) {
    ```
    一開始先將sum歸零，避免累加n的每個位的時候計算錯誤，
    接著使用第二個while迴圈，只要n不等於0，不出來，通過%來取得n個位數內容，將其平方後累加進sum，然後將n/10，這樣就可以去掉個位數，繼續去計算10位數，
    通過不斷的動作，最終n會等於0，然後n的每一位數的平方就都計算出來了。
    ```
    sum = 0;
    while(n) {
        sum += (n%10) * (n%10);
        n /=10;
    }
    ```
    接著就是檢查sum是否等於1，等於的話就脫離這個while並回傳true。
    ```
    if(sum == 1) {
        break;
    }
    ```
    而只要sum不等於1，就去檢查sum是否存在map中，存在的話就知道開始進入無窮迴圈了，直接回傳false，不存在就將sum存入map中，繼續下一輪計算。
    ```
    if(map.find(sum) != map.end()) {
        return false;
    }
    else {
        map.insert(sum);
    }
    n = sum;
    ```
- **空間複雜度**: O(logn)
- **時間複雜度**: O(1)