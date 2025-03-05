# 18. 4Sum

🟠 Medium

Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

Example 1:
```
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
```

Example 2:
```
Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
```

Constraints:
- 1 <= nums.length <= 200
- -109 <= nums[i] <= 109
- -109 <= target <= 109

## Approach
### 
- **Parsing**: 
    題目給出一個vector，要求找出其中有幾種組合，是四個數字合起來會等於target。
    這個做法跟15題，三數之合，非常類似，但是加入第四個數字需要考慮。
    開頭按造題目要求回傳的格式，宣告ret，另外是用來收斂搜尋目標的指針，left，right。
    ```
    std::vector<std::vector<int>> ret;
    int left = 0;
    int right = 0;
    ```
    開頭先將nums排序過，這樣才可以方便找出目標。
    ```
    std::sort(nums.begin(), nums.end());
    ```
    接著通過for迴圈來歷遍nums。
    ```
    for(int i=0;i<nums.size();i++) {
    ```
    這裡會有兩個判斷式，
    第一個是為了避免浪費時間，因為這題跟15題不同，這裡要求是四個數字相加起來要等於target，
    但是當前的數字可能有機會是負數，負數再加上後面的數字還是有可能會符合要求，所以這裡不只要求判斷nums[i]大於target，
    還必須是nums[i]要大於等於0，因為開頭已經排序過了，當nums[i]已經是正數，並且也已經大於target了，那後面的數字勢必都絕對是正數，
    那百分之百不可能取得符合要求的組合，所以可以直接中斷for。
    第二個是為了排除重複的內容，但是只比較前一個是因為，
    [-1, -1, 0, 2]，假如是這種組合，比較後一個，那這個組合就會被去除，只有比較前一個才不會造成誤判。
    ```
    if(nums[i]>target && nums[i]>=0) {
        break;
    }

    if(i>0 && nums[i] == nums[i-1]) {
        continue;
    }
    ```
    因為前面已經確認了第一個數字，再來裡面再來一個for迴圈來確認第二個數字，這裡兩個判斷式的邏輯跟前面一樣，所以這裡並不贅述。
    ```
    for(int j=i+1;j<nums.size();j++) {
        if(nums[i] + nums[j] > target && nums[i] + nums[j] >= 0) {
            break;
        }

        if(j>i+1 && nums[j] == nums[j-1]) {
            continue;
        }
    ```
    等確定好兩個數字後，通過收斂left跟right的指針，來找出符合要求的組合。
    ```
    left = j+1;
    right = nums.size() - 1;

    while(left < right) {
        if((long)nums[i] + nums[j] + nums[left] + nums[right] < target) {
            left++;
        }
        else if((long)nums[i] + nums[j] + nums[left] + nums[right] > target) {
            right--;
        }
        else {
            std::vector<int> tmp;
            tmp.push_back(nums[i]);
            tmp.push_back(nums[j]);
            tmp.push_back(nums[left]);
            tmp.push_back(nums[right]);

            ret.push_back(tmp);

            while(left < right && nums[left]==nums[left+1]) {
                left++;
            }

            while(left < right && nums[right]==nums[right-1]) {
                right--;;
            }

            left++;
            right--;
        }
    }
    ```
- **空間複雜度**: O(N)
- **時間複雜度**: O(N^3)