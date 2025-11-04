# Q2. Maximum Alternating Sum of Squares

🟠 Medium

You are given an integer array nums. You may rearrange the elements in any order.

The alternating score of an array arr is defined as:

score = arr[0]2 - arr[1]2 + arr[2]2 - arr[3]2 + ...
Return an integer denoting the maximum possible alternating score of nums after rearranging its elements.

Note: Please do not copy the description during the contest to maintain the integrity of your submissions.

Example 1:
```
Input: nums = [1,2,3]

Output: 12

Explanation:

A possible rearrangement for nums is [2,1,3], which gives the maximum alternating score among all possible rearrangements.

The alternating score is calculated as:

score = 22 - 12 + 32 = 4 - 1 + 9 = 12

Note: Please do not copy the description during the contest to maintain the integrity of your submissions.
```

Example 2:
```
Input: nums = [1,-1,2,-2,3,-3]

Output: 16

Explanation:

A possible rearrangement for nums is [-3,-1,-2,1,3,2], which gives the maximum alternating score among all possible rearrangements.

The alternating score is calculated as:

score = (-3)2 - (-1)2 + (-2)2 - (1)2 + (3)2 - (2)2 = 9 - 1 + 4 - 1 + 9 - 4 = 16

Note: Please do not copy the description during the contest to maintain the integrity of your submissions.
```

Constraints:
- 1 <= nums.length <= 105
- -4 * 104 <= nums[i] <= 4 * 104

## Approach
### 
- **Parsing**: 
    題目給出一個vector，可以任意排序，將其數值平方後，要按造奇數相加，偶數相減的步驟，找出操作完成後最大的結果。

    這題有點小tricky，
    將數值平方，可以預先操作完成，
    已知vector總數量，那就可以知道要減去的數字有幾個，
    所以只要將所有數字平方後排序，取總數的一半，將較大的那一半加總後，減去較小的那一半，就會是最大值。

    先將vector中的數值平方計算完成，
    ```
    for(int i=0;i<nums.size();i++) {
        nums[i] = nums[i]*nums[i];
    }
    ```

    接著排序，
    ```
    sort(nums.begin(), nums.end());
    ```

    再來計算要減去的偶數數量應該是多少，
    ```
    int n = nums.size()/2;
    ```

    因為已經排序過，較小的一半在前面的位置，所以小於n的都剪去，大於n的都加起來，結果回傳即可。
    ```
    for(int i=0;i<nums.size();i++) {
        if(i<n) {
            ret -= nums[i];
        }
        else {
            ret += nums[i];
        }
    }
    ```
- **空間複雜度**: O(1)
- **時間複雜度**: O(nlogn)