# 1679. Max Number of K-Sum Pairs

🟠 Medium

You are given an integer array nums and an integer k.

In one operation, you can pick two numbers from the array whose sum equals k and remove them from the array.

Return the maximum number of operations you can perform on the array.

Example 1:
```
Input: nums = [1,2,3,4], k = 5
Output: 2
Explanation: Starting with nums = [1,2,3,4]:
- Remove numbers 1 and 4, then nums = [2,3]
- Remove numbers 2 and 3, then nums = []
There are no more pairs that sum up to 5, hence a total of 2 operations.
```

Example 2:
```
Input: nums = [3,1,3,4,3], k = 6
Output: 1
Explanation: Starting with nums = [3,1,3,4,3]:
- Remove the first two 3's, then nums = [1,4,3]
There are no more pairs that sum up to 6, hence a total of 1 operation.
```

Constraints:
- 1 <= nums.length <= 105
- 1 <= nums[i] <= 109
- 1 <= k <= 109

## Approach
### two point
- **Parsing**: 
    題目給出一個vector，還有一個k值，要求找出裡面有幾種組合，可以兩個數字加起來等於K。
    這題可以使用類似two point的方式來操作，但是需要先經過sort，然後在通過兩個指針左右向中間夾，找到符合條件的數字，符合就紀錄，不符合就操作指針繼續尋找。
    以下先宣告變數，ret做為紀錄有幾組數字符合條件並返回，left跟right是用來操作的指針，用來從vector的起點跟末端尋找。
    ```
    int ret = 0;
    int left = 0, right = nums.size()-1;
    ```
    首先，先將vector排序，以範例為例，[3, 1, 3, 4, 3]，經過排序後，[1, 3, 3, 3, 4]，這樣就會更好找尋。至少有個規則可以去走。
    ```
    std::sort(nums.begin(), nums.end());
    ```
    然後通過while迴圈，只要左不超過右，就繼續尋找。
    ```
    while(left < right) {
    ```
    接著開始找尋，一開始左指針指向1，而右指針指向4，這兩個值加起來1+4=5，小於K，所以我們嚐試將左指針右移。
    [ 1, 3, 3, 3, 4 ]
      ^           ^
    左指針指向3，右指針指向4，3+4=7，大於K，所以右指針左移。
    [ 1, 3, 3, 3, 4 ]
         ^        ^
    3+3=6，符合，所以ret++，並且同時移動左右指針，然後他們就會在中間的3重合，而跳出while，這樣就可以計算出結果了。
    [ 1, 3, 3, 3, 4 ]
         ^     ^   
    ```
    int sum = nums[left] + nums[right];
    if(sum == k) {
        ret++;
        left++;
        right--;
    }
    else if(sum > k) {
        right--;
    }
    else {
        left++;
    }
    ```
- **空間複雜度**: O(1)
- **時間複雜度**: O(n log n)