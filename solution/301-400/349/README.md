# 349. Intersection of Two Arrays

🟢 Easy 

Given two integer arrays nums1 and nums2, return an array of their 
intersection
. Each element in the result must be unique and you may return the result in any order.

Example 1:
```
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
```

Example 2:
```
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.
```

Constraints:
- 1 <= nums1.length, nums2.length <= 1000
- 0 <= nums1[i], nums2[i] <= 1000

## Approach
### Hash map
- **Parsing**: 
    題目給出兩個vector，要求找出共同的數字，重複的數字也只計算一次。

    這裡使用的是hash map，因為只要共同的數字就好，重複不需要，那就使用unordered_set就好，
    以下先宣告要回傳的ret，接著在宣告unordered_set，並且直接將nums1塞進其中，以範例一為例，nums1 = {1, 2, 2, 1}，進入unoredered_set後，會變成{2, 1}，重複的數字並不會再產生。
    ```
    vector<int> ret;
    unordered_set<int> tmp(num1.begin(), num1.end());
    ```
    接著使用for來掃過nums2，使用auto自動替換nums2中的數值。
    ```
    for(auto num:num2) {
    ```
    接著使用unordered_set提供的函式，find，只要find回傳不等於end()，那就代表該數字在set中，所以將其推入ret中並把tmp中的內容給去除，完成後直接回傳ret即可。
    ```
    if(tmp.find(num) != tmp.end()) {
        ret.push_back(num);
        tmp.erase(num);
    }
    ```
- **空間複雜度**: O(N+M)
- **時間複雜度**: O(N)