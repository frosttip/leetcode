# 283. Move Zeroes

🟢 Easy 

Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.


Example 1:
```
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
```

Example 2:
```
Input: nums = [0]
Output: [0]
```

Constraints:
- 1 <= nums.length <= 104
- -231 <= nums[i] <= 231 - 1

## Approach
### 快慢針
- **Parsing**: 
    這題使用的是快慢針，題目要求在不改變排序的狀態下，將所有的0移動到vector的尾巴。
    只要使用快慢針的基礎，就可以將非0的數字移動到vector前面了，如下
    ```
    int slow = 0;
    int fast = 0;

    for(fast = 0;fast<nums.size();fast++) {
        if(nums[fast] != 0) {
            nums[slow++] = nums[fast];
        }
    }
    ```
    但是上面的操作結束後，vector的尾巴並不一定都是0，這時候slow指針會是指向最後一個非0數字的後面一個位置，
    所以我們要做的是繼續操作slow指針，通過繼續移動他，將他之後碰到的所有數字都寫為0就可以了。
    ```
    for(;slow<nums.size();slow++) {
        nums[slow] = 0;
    }
    ```
- **空間複雜度**: O(1)
- **時間複雜度**: O(N)