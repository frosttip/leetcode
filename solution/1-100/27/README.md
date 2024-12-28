# 27. Remove Element

Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
Return k.
Custom Judge:

The judge will test your solution with the following code:
```
int[] nums = [...]; // Input array
int val = ...; // Value to remove
int[] expectedNums = [...]; // The expected answer with correct length.
                            // It is sorted with no values equaling val.

int k = removeElement(nums, val); // Calls your implementation

assert k == expectedNums.length;
sort(nums, 0, k); // Sort the first k elements of nums
for (int i = 0; i < actualLength; i++) {
    assert nums[i] == expectedNums[i];
}
```
 

Example 1:
```
Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 2.
It does not matter what you leave beyond the returned k (hence they are underscores).
```

Example 2:
```
Input: nums = [0,1,2,2,3,0,4,2], val = 2
Output: 5, nums = [0,1,4,0,3,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums containing 0, 0, 1, 3, and 4.
Note that the five elements can be returned in any order.
It does not matter what you leave beyond the returned k (hence they are underscores).
 ```

Constraints:

- 0 <= nums.length <= 100
- 0 <= nums[i] <= 50
- 0 <= val <= 100

## Approach
### 快慢針
- **Parsing**: 
    這一題使用的解法是快慢針，題目的要求是將指定的數值去除，如果使用暴力的兩個for迴圈，應該也是可以解出來，只是效率低，
    但是通過快慢針，也就是兩個指針的操作，就可以掃完整個vector一次後就取得結果，說明如下:
    首先是建立快慢針，這裡先宣告慢針，
    ```
    int slowIndex = 0;
    ```
    接著建立for迴圈，而for迴圈建立的變數就是快針，
    ```
    for(int fastIndex = 0;fastIndex<nums.size();fastIndex++) {
    ```
    通過for迴圈就可以掃過整個vector，
    接著在for迴圈裡進行判斷，
    假如當前數值不是要排除的數值，那就將慢針一起遞增，並且將快針的內容複製到慢針的位置，
    假如當前數值是要排除的數值，那慢針就不需要向後了，
    ```
    if(nums[fastIndex] != val) {
        nums[slowIndex++] = nums[fastIndex];
    }
    ```
    這裡可以發揮一點想像力，因為慢針停留在原地，也就是要排除的位置，
    當快針繼續向後移動，這時候移動過後的快針指向的目標不是欲排除數值，這時候就可以將他複製到慢針的位置，
    也就會變相去除了慢針所指向的數值，也就是欲排除數值，
    通過這種方式，整個vector走完之後，慢針的位置就會是排除完所有數值後，vector應該剩餘的內容數量。

- **空間複雜度**: O(1)
- **時間複雜度**: O(1)