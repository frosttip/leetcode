# 347. Top K Frequent Elements

🟠 Medium

Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Example 1:
```
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
```

Example 2:
```
Input: nums = [1], k = 1
Output: [1]
```

Constraints:
- 1 <= nums.length <= 105
- -104 <= nums[i] <= 104
- k is in the range [1, the number of unique elements in the array].
- It is guaranteed that the answer is unique.

Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

## Approach
### unordered_map, priority_queue
- **Parsing**: 
    題目給出一個vector，還有一個數字K，vector中有多個數字，會有重複的，要求給出這些重複數字，出現頻率最高的前K個數字，並回傳。

    這題快速的解法可以通過unordered_map來蒐集所有數字，將數字做為index，把value作為計算該數字的出現次數，接著把map中的數值填
    入priority_queue，priority_queue就可以幫你自動排序好，只要將queue中的前K個數字取出來就可以得到解答了。

    首先建立用來計算每個數字出現次數的unordered_map
    ```
    std::unordered_map<int, int> mp;
    ```

    接著通過for迴圈掃過整個vector，將數字作為index，每出現一次數字，就將其加一。
    ```
    for(int i=0;i<nums.size();i++) {
        mp[nums[i]]++;
    }
    ```

    建立priority_queue，通過for的auto，將map中的數值取出，這裡要記的，因為要把兩個數值都填入queue中，所以要用pair，但是queue
    會以第一個項目去排序，所以要將數字的出現次數放在第一項，數字放在第二項。
    ```
    std::priority_queue<std::pair<int, int>> pq;

    for(auto x:mp) {
        pq.push(std::make_pair(x.second, x.first));
    }
    ```

    接著通過for迴圈，將前幾大的數字取出後放入回傳的vector中即可。
    ```
    std::vector<int> ret;

    for(int i=k;i>0;i--) {
        ret.push_back(pq.top().second);
        pq.pop();
    }
    ```
- **空間複雜度**: O(N)
- **時間複雜度**: O(N loh N)