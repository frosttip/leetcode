# 704. Binary Search

Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:
```
Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4
```

Example 2:
```
Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1
 ```

Constraints:

- 1 <= nums.length <= 104
- -104 < nums[i], target < 104
- All the integers in nums are unique.
- nums is sorted in ascending order.

## Approach
### 二元搜尋法
- **Parsing**: 
  這一題使用的應該是二元搜尋法，通過建立兩個index，一個為vector的頭，一個為vector的尾，
  通過while迴圈來不斷比較，頭必須小於尾，
  每次都將兩個index相加並除二就可以取得中間的index，確認該index所指向的內容是否為target，
  假如是，可以直接返回，
  假如不是，比較其大小，
  大於target代表尾巴位置太右邊，將其設定為mid的位置再減一，
  小於target代表頭的位置太左邊，將其設定為mid的位置再加一，
  通過不斷的改變頭尾位置，就可以找出taget所在，
  假如一直找不到，終究頭尾會交錯，就會跳出while迴圈。

- **空間複雜度**: O(1)
- **時間複雜度**: O(log(N))