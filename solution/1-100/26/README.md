# 26. Remove Duplicates from Sorted Array

🟢 Easy 

Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:
- Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
- Return k.

## Custom Judge:
The judge will test your solution with the following code:
```
int[] nums = [...]; // Input array
int[] expectedNums = [...]; // The expected answer with correct length

int k = removeDuplicates(nums); // Calls your implementation

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}
```
If all assertions pass, then your solution will be accepted.

Example 1:
```
Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
```

Example 2:
```
Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
```

Constraints:
- 1 <= nums.length <= 3 * 104
- -100 <= nums[i] <= 100
- nums is sorted in non-decreasing order.

## Approach
### 快慢針
- **Parsing**: 
    這裡使用的解題方法是快慢針，只是略有變形，首先建立兩個變數作為指針，
    一個指向vector的頭，作為慢針，
    另一個指向vector的頭的下一個位置，作為快針，
    ```
    int slow = 0;
    int fast = 0;
    ```
    接著通過for迴圈，只用快針去掃過整個vector
    ```
    for(fast = 1;fast<nums.size();fast++) {
    ```
    然後判斷慢針指向的內容跟快針指向的內容是否不同，
    ```
    if(nums[fast]!=nums[slow]) {
    ```
    這裡有一個重點，假如判斷式成立，會有兩個結果，先假設兩個狀態，
    以下狀況，開頭的兩個數值是相同的，所以快針會先跑到位置2，這時候慢針還在0的位置，所以需要先移動慢針，再把快針的內容複製給慢針，這樣才可以完成我們想要的操作。
    ```
    {1,1,2,2,3}
    slow = 0;
    fast = 1;

    nums[0] == fast[1]// 1 == 1

    fast++;
    fast = 2

    nums[0] != nums[2]// 1 != 2
    ```
    另一個狀況是，一開始慢針就不等於快針的內容了，所以這時候直接進入判斷式，慢針先將位置向後一格，挪到快針的位置，接著將快針的內容再複製到慢針，也就是原位複製到原位，這樣也會符合我們想要的操作。
    ```
    {1,2,3,4,4}
    slow = 0;
    fast = 1;

    nums[0] == fast[1]// 1 != 1
    ```
    根據以上的情況設想，所以進入判斷式後就需要先移動慢針，接著再複製資料。
    ```
    slow++;
    nums[slow] = nums[fast];
    ```
    最後，因為要回傳操作完之後的vector大小，而慢針是指向最後一個內容，所以必須回復慢針+1的數值。
    ```
    return slow+1;
    ```


- **空間複雜度**: O(1)
- **時間複雜度**: O(1)