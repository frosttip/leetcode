# 15. 3Sum

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

Example 1:
```
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
```

Example 2:
```
Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
```

Example 3:
```
Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
```

Constraints:
- 3 <= nums.length <= 3000
- -105 <= nums[i] <= 105

## Approach
### Tow point
- **Parsing**: 
    題目給出一個vector，要求找出三個數字相加會等於0的組合，並且數字不可以重複。

    解題思路有點像是two point，因為vector是沒有規律的，所以開頭需要先sort，接著通過for迴圈來先指定第一個數字，接著將當前指定數字後，剩餘的數字，從中找出還有哪兩個數字相加後跟當前數字加起來會等於0，利用兩個指針，讓指針從當前位置之後的位置，跟vector尾巴，慢慢向中間收斂，這樣就可以找到目標。

    首先建立要回傳的vector，ret，接著是用來作為收斂找尋目標的index，left，right。
    ```
    std::vector<std::vector<int>> ret;
    int left = 0;
    int right = 0;
    ```
    像前面所說，因為一開始vector可能其中內容都是無序的，所以通過sort，將其內容都整理成從小到大的排序。
    ```
    std::sort(nums.begin(), nums.end());
    ```
    將著通過for來掃過整個vector。
    ```
    for(int i=0;i<nums.size();i++) {
    ```
    指定for指向的當前位置為第一個數字，因為題目要求三個數相加必須等於0，因為開頭已經排序過了，所以第一個數字必須為負數，不然就不可能相加為0，
    所以這裡加上一個判斷式，只要nums[i]>0就脫離，因為後面已經不可能找到符合要求的組合了，
    
    第二個判斷式是為了去除重複的數字，但是為什麼是當前位置跟前一個位置相比，
    以下面這個組合為例，要相等於0的話，組合應該是[-1, -1, 2]，
    假設我們是寫nums[i] == nums[i+1]，第一個-1就被排除了，這樣就不會找到符合需求的組合，但是題目要求的是index不能相同，可是數字相同可以，所以為了避免這種狀況，就需要使用nums[i] == nums[i-1]判斷。
    [-1, -1, 2]
    ```
    int e = nums[i];

    if(nums[i] > 0) {
        break;
    }

    if(i>0 && nums[i] == nums[i-1]) {
        continue;
    }
    ```
    當確定好第一個數字後，接著指定left跟right的位置，left指定為當前i的位置後面一個，right始終指定為vector中的最後一個位置，因為我們要從這個區間中找出我們想要的數字組合。
    然後使用while來讓我們一直在這個區間中找，脫離條件設定為left要小於right，
    ```
    left = i+1;
    right = nums.size()-1;

    while(left<right) {
    ```
    接著在while中就可以開始找三數相加的結果，這裡會出現三種現象，加起來等於0跟大於或小於0，
    先排除等於，只要大於0，就可以移動right，將其向左移動，所以是--，
    或是小於0，代表其中一個數字偏小，所以移動left，將其向右，所以是++。
    ```
    if(nums[i] + nums[left] + nums[right] > 0) {
        right--;
    }   
    else if(nums[i] + nums[left] + nums[right] < 0) {
        left++;
    }
    else {

    }
    ```
    最後是結果等於0了，找到後只需要將結果填入ret，但是之後還是需要判斷一下，再移動指針，
    以下面這個vector為例，
    假如i像在指向index=1，nums[1] = -1，
    left = 2，nums[2] = 0，
    right = 5，nums[5] = 1，
    所以第一個組合是[-1, 0, 1]，
    我們已經找到組合了，但是只將left跟right各自移動一次的話，又會得到相同的組合[-1, 0, 1]，而回傳的內容不可以是相同的，所以必須要去除掉同樣的內容。
    [-1, -1, 0, 0, 1, 1]
    ```
    std::vector<int> tmp;
    tmp.push_back(nums[i]);
    tmp.push_back(nums[left]);
    tmp.push_back(nums[right]);
    ret.push_back(tmp);

    while(left<right && nums[left] == nums[left+1]) {
        left++;
    }

    while(left<right && nums[right] == nums[right-1]) {
        right--;
    }

    left++;
    right--;
    ```
- **空間複雜度**: O(N^2)
- **時間複雜度**: O(N^2)