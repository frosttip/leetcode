# 34. Find First and Last Position of Element in Sorted Array

🟠 Medium

Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

Example 1:
```
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
```

Example 2:
```
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
```

Example 3:
```
Input: nums = [], target = 0
Output: [-1,-1]
```

Constraints:
- 0 <= nums.length <= 105
- -109 <= nums[i] <= 109
- nums is a non-decreasing array.
- 109 <= target <= 109

## Approach
### 二元搜尋法
- **Parsing**: 
    這題的本質還是二元搜尋法，但是有點變形。
    題目要求尋找的是目標的範圍，所以要尋找兩個邊界，以下先尋找左邊界，
    同樣通過for迴圈，用兩個變數作為指向vector的兩端的邊界，不斷的尋找中間值，再去確認要移動哪一端來壓縮搜尋的範圍，
    ```
    while(left <= right) {
    ```
    要注意的是當找到目標後，先將其位置給到ran_l，接著繼續將右邊界指向mid左邊位置，
    要明白，題目要求的是找到target的範圍，所以當前找到的地方可能是target中間，所以要持續尋找，直到左邊界大於右邊界才離開while，
    但是，因為有可能找到的位置就已經是target的邊緣了，所以每次找到的時候還是必須要位置記錄下來，
    這裡是左邊界的找法，所以要移動的就是right，假如要找的是右邊界，那移動的就是left了。
    ```
    if(nums[mid] == target) {
        ran_l = mid;
        right = --mid;
    }
    ```

- **空間複雜度**: O(1)
- **時間複雜度**: O(log(N))