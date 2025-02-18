# 3066. Minimum Operations to Exceed Threshold Value II

🟠 Medium

You are given a 0-indexed integer array nums, and an integer k.

You are allowed to perform some operations on nums, where in a single operation, you can:

Select the two smallest integers x and y from nums.
Remove x and y from nums.
Insert (min(x, y) * 2 + max(x, y)) at any position in the array.
Note that you can only apply the described operation if nums contains at least two elements.

Return the minimum number of operations needed so that all elements of the array are greater than or equal to k.

Example 1:
```
Input: nums = [2,11,10,1,3], k = 10

Output: 2

Explanation:

In the first operation, we remove elements 1 and 2, then add 1 * 2 + 2 to nums. nums becomes equal to [4, 11, 10, 3].
In the second operation, we remove elements 3 and 4, then add 3 * 2 + 4 to nums. nums becomes equal to [10, 11, 10].
At this stage, all the elements of nums are greater than or equal to 10 so we can stop. 

It can be shown that 2 is the minimum number of operations needed so that all elements of the array are greater than or equal to 10.
```

Example 2:
```
Input: nums = [1,1,2,4,9], k = 20

Output: 4

Explanation:

After one operation, nums becomes equal to [2, 4, 9, 3]. 
After two operations, nums becomes equal to [7, 4, 9]. 
After three operations, nums becomes equal to [15, 9]. 
After four operations, nums becomes equal to [33].
At this stage, all the elements of nums are greater than 20 so we can stop. 

It can be shown that 4 is the minimum number of operations needed so that all elements of the array are greater than or equal to 20.
```

Example 3:
```

```

Constraints:
- 2 <= nums.length <= 2 * 105
- 1 <= nums[i] <= 109
- 1 <= k <= 109
- The input is generated such that an answer always exists. That is, after performing some number of operations, all elements of the array are greater than or equal to k.

## Approach
### minimum heap
- **Parsing**: 
    這題要熟悉的是miniheap，通過priority_queue的一種變形，一般的priority_queue會自動將最大的數值放到queue的最前面，但是minimum heap會將最小值放到最前面，而這個操作會消耗O(nlogn)，通過這個特性，我們就可以達成題目要求的動作，將vector中的最小的兩個數值取出來後，做完運算，放回去vector，並讓整個vector的所有值大於k，計算總共要運算幾次才可以達成。
    首先，
    宣告要回傳的運算次數，ret，
    第二個就是minimum heap的宣告，因為vector中的最大值是10的9次方，int雖然可以容納，但是經過運算後的數值，有可能會超過，所以需要用long來容納，宣告時直接將nums全部填入queue中，
    再來是需要用來運算公式的xy，
    ```
    int ret = 0;
    std::priority_queue<long, std::vector<long>, std::greater<long>> minheap(nums.begin(), nums.end());;
    long x = 0;
    long y = 0;
    ```
    將著通過top()來取出queue中的最小值，只要最小值還沒有大於k，就不脫離while迴圈，
    ```
    while(minheap.top() < k) {
    ```
    通過top()來將queue中的值取出，取出後再用pop()丟棄，連續兩次後就可以取出最小的兩個數值，
    ```
    x = minheap.top();
    minheap.pop();
    y = minheap.top();
    minheap.pop();
    ```
    最後在通過運算後，將數值push回去queue中，完成後就可以將ret累加一，脫離while後，只要將ret回傳即可。
    ```
    minheap.push(std::min(x, y)*2 + std::max(x, y));

    ret++;
    ```
- **空間複雜度**: 
- **時間複雜度**: 