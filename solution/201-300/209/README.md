# 209. Minimum Size Subarray Sum

🟠 Medium

Given an array of positive integers nums and a positive integer target, return the minimal length of a 
subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.
 

Example 1:
```
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
```

Example 2:
```
Input: target = 4, nums = [1,4,4]
Output: 1
```

Example 3:
```
Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0
```

Constraints:
- 1 <= target <= 109
- 1 <= nums.length <= 105
- 1 <= nums[i] <= 104

## Approach
### Slide window
- **Parsing**: 
    這題的題目輸入一個vector，還有一個數字target，要求給出vector中，連續幾個數字會大於或等於target，要求找出vctor中最少幾個數字可以達成。
    暴力一點的解法就是通過兩個for迴圈，也可以解出來，但是這樣的時間複雜度就會是O(N^2)，
    更有效率的方式會是slide window，通過一個滑動的視窗來解題，這是一種形象式的說明方式，
    以下說明，
    首先宣告四個變數，
    ret是要回傳的答案，最少幾個數字加總會大於target，
    sum是用來加總的變數，將nums中的數值加起來儲存在這個變數，
    sublen是用來計算當前sum是用幾個變數加起來，
    i跟j是視窗的起點跟終點的指針，i是起點，j是終點，這其實有點像是tow point的變形，通過移動兩個指針來鎖定計算範圍。
    ```
    int ret = INT_MAX;
    int sum = 0;
    int sublen = 0;
    int i = 0, j = 0;
    ```
    接著通過for迴圈來移動j，也就是終點，慢慢的向後移動終點，讓計算範圍慢慢擴張，
    ```
    for(j=0;j<nums.size();j++) {
    ```
    每次向後移動終點，就將其指向的內容加入sum之中，
    ```
    sum += nums[j];
    ```
    而每次移動終點後就檢查，sum是否有大於target，當大於或是等於，就進入while中，
    ```
    while(sum >= target) {
    ```
    在while中的計算，首先已經進來就代表目前的sum已經符合題目的條件了，
    這時候先計算sublen，也就是起點跟終點之間的數值有幾個，
    接著再來確認，是否sublen有小於ret，假如小於就將ret的內容給替換掉，
    接著將sum減去當下i所指向的數字，然後將i向後移動，
    這裡的動作就像是先確定好j所指向的終點，然後慢慢的將i所指向的起點慢慢移動，
    這個動作就是slide window，
    ```
    sublen = j - i + 1;
    ret = ret<sublen? ret:sublen;
    sum -= nums[i++];
    ```
    最後回傳的時候，只要ret的內容還是INT_MAX，就代表沒有符合條件的狀態出現，所以返回0，
    ret的內容不等於INT_MAX，就返回ret。
    ```
    return ret==INT_MAX? 0:ret;
    ```
    
- **空間複雜度**: O(1)
- **時間複雜度**: O(N)