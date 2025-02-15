# 454. 4Sum II

🟠 Medium

Given four integer arrays nums1, nums2, nums3, and nums4 all of length n, return the number of tuples (i, j, k, l) such that:

0 <= i, j, k, l < n
nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0

Example 1:
```
Input: nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
Output: 2
Explanation:
The two tuples are:
1. (0, 0, 0, 1) -> nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> nums1[1] + nums2[1] + nums3[0] + nums4[0] = 2 + (-1) + (-1) + 0 = 0
```

Example 2:
```
Input: nums1 = [0], nums2 = [0], nums3 = [0], nums4 = [0]
Output: 1
```

Constraints:
- n == nums1.length
- n == nums2.length
- n == nums3.length
- n == nums4.length
- 1 <= n <= 200
- -228 <= nums1[i], nums2[i], nums3[i], nums4[i] <= 228

## Approach
### 
- **Parsing**: 
    題目給出四個vector，要求找出總共有幾種組合，四個vector中的各一個數字加起來會等於0。
    假如用最笨的方式，四個for迴圈，也可以找出來，但是這樣就會需要O(N^4)的時間複雜度，太費時了，
    所以這裡使用另一種方式，使用unordered_map來操作，先將第一與第二的內容通過兩個for迴圈，加起來的數字作為key放到map，同樣的數字出現的次數作為value存到map，
    接著用第二次雙for迴圈操作在第三與第四個vector，因為要找到加起來等於0的值，所以要找map中是否有(0-(c+d))的key，找到後將valeu累加到ret中，
    因為題目要的是總共有幾種組合，所以要把符合條件的value都加到ret中。
    
    首先，先建立unordered_map用來記錄a+b的組合，ret作為回傳的變數。
    ```
    std::unordered_map<int, int> map;
    int ret = 0;
    ```
    用兩個for迴圈去掃過nums1跟nums2，將兩個數值加起來後做為key給map，然後累加其數值，有重複的數字出現就會增加value，
    ```
    for(int a:nums1) {
        for(int b:nums2) {
            map[a+b]++;
        }
    }
    ```
    在用兩個for迴圈去掃nums3跟nums4，這時候通過unordered_map的find來去找有沒有(0-(c+d))的key，有的話就代表當前的組合可以加起來等於0，
    將其value累加到ret中，最後回傳ret即可。
    ```
    for(int c:nums3) {
        for(int d:nums4) {
            if(map.find(0-(c+d)) != map.end()) {
                ret += map[0-(c+d)];
            }
        }
    }
    ```

- **空間複雜度**: O(N^2)
- **時間複雜度**: O(N^2)