# 35. Search Insert Position

🟢 Easy 

Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.
 

Example 1:
```
Input: nums = [1,3,5,6], target = 5
Output: 2
```

Example 2:
```
Input: nums = [1,3,5,6], target = 2
Output: 1
 ```

 Example 3:
```
Input: nums = [1,3,5,6], target = 7
Output: 4
 ```

Constraints:

- 1 <= nums.length <= 104
- -104 <= nums[i] <= 104
- nums contains distinct values sorted in ascending order.
- -104 <= target <= 104

## Approach
### 二元搜尋法
- **Parsing**:
    這裡使用的還是基本的二元搜尋法，通過設定兩個指針，從vector的頭跟尾計算出中間點，根據中間點數值的大小去移動頭跟尾巴的指針位置，藉由這個方法快速找出想要的位置出來。


- **空間複雜度**: O(1)
- **時間複雜度**: O(1)