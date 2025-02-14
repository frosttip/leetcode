# 1. Two Sum

🟢 Easy

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

Example 1:
```
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
```

Example 2:
```
Input: nums = [3,2,4], target = 6
Output: [1,2]
```

Example 3:
```
Input: nums = [3,3], target = 6
Output: [0,1]
```

Constraints:
- 2 <= nums.length <= 104
- -109 <= nums[i] <= 109
- -109 <= target <= 109
- Only one valid answer exists.

## Approach
### 
- **Parsing**: 
    題目給出一個vector，跟一個target，要求找出vector中哪兩個數字加起來會等於target，vector中一定會有這個組合。
    這題用最簡單的方式就是兩個for迴圈，一個一個地慢慢比對過去，最多就是O(N^2)就可以找到了。
    但是還是有更快的方式，
    將target減去nums中的數值，到unordered_map中尋找，假如找不到，那就將nums當前位置的數字跟index添加進去，然後繼續找下一個，重複後一定會找到，這樣指需要一個for就可以搞定。
    首先宣告用來記錄數字跟位置的unordered_map，還有用來回傳的ret，
    ```
    std::unordered_map<int, int> map;
    std::vector<int> ret;
    ```
    用for迴圈掃過整個vector，
    ```
    for(int i=0;i<nums.size();i++) {
    ```
    先將target減去當前的nums數值，
    ```
    int buf = target - nums[i];
    ```
    接著在map中找尋buf，假如找到就代表找到組合，假如找不到，將當前的nums[i]，數值作為key，i位置作為value放進map中，
    ```
    if(map.find(buf) != map.end()) {
    }
    else {
        map[nums[i]] = i;
    }
    ```
    因為前面已經將數字跟位置放入到map中，所以在後續的計算中，就會找到buf，因為是將位置作為value放進map，就可以將map[buf]填到ret中，另外就是i，當前指到的位置放到ret中。
    ```
    ret.push_back(map[buf]);
    ret.push_back(i);
    break;
    ```
- **空間複雜度**: O(N)
- **時間複雜度**: O(N)