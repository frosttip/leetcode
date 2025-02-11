# 334. Increasing Triplet Subsequence

🟠 Medium

Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.

Example 1:
```
Input: nums = [1,2,3,4,5]
Output: true
Explanation: Any triplet where i < j < k is valid.
```

Example 2:
```
Input: nums = [5,4,3,2,1]
Output: false
Explanation: No triplet exists.
```

Example 3:
```
Input: nums = [2,1,5,0,4,6]
Output: true
Explanation: The triplet (3, 4, 5) is valid because nums[3] == 0 < nums[4] == 4 < nums[5] == 6.
```

Constraints:
- 1 <= nums.length <= 5 * 105
- -231 <= nums[i] <= 231 - 1

## Approach
### 
- **Parsing**: 
    題目給出一個array，要求找出是否在裡面有三個數字，index是升序，像是i < j < k，並且內容也是升序，nums[i] < nums[j] < nums[k]，有的話回傳true，沒有回傳false。
    假設使用最暴力的三個for迴圈去解，就會需要n的三次方的時間複雜度，絕對會超時，所以不可以使用。
    這裡改用更簡單的邏輯判斷，宣告兩個變數，low跟mid，兩者都設定為極大值，只要找到最小值跟中間值，那只要再來一個數字大於中間值就是找到了。

    因為要找到三個數字，所以只要輸入的vector大小小於三，直接回傳false，
    ```
    if(nums.size() < 3) {
        return false;
    }
    ```
    宣告兩個變數，都設定為INT_MAX，
    ```
    int low = INT_MAX;
    int mid = INT_MAX;
    ```
    使用for迴圈來掃過整個vector，從最後一個if來看，只要有個數字小於low，將其內容取代low，接著中間的if，只要有個數字大於low並且小於mid，那就找到mid了，只要low跟mid都找到了，那在找到一個數字大於mid，那就找到三個數字，即可返回，因為兩個變數本身宣告都是int的最大值，當還沒有找到這兩個數值時，按造題目的設定，是不可能有數字可以超過INT_MAX的。
    ```
    for(int i=0;i<nums.size();i++) {
        if(nums[i]>mid) {
            return true;
        }
        else if(nums[i] > low && nums[i] < mid) {
            mid = nums[i];
        }
        else if(nums[i] < low) {
            low = nums[i];
        }
    }
    ```
- **空間複雜度**: O(1)
- **時間複雜度**: O(N)