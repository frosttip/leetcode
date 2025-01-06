# 977. Squares of a Sorted Array

🟢 Easy 

Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

Example 1:
```
Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].
```

Example 2:
```
Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]
```

Constraints:
- 1 <= nums.length <= 104
- -104 <= nums[i] <= 104
- nums is sorted in non-decreasing order.

## Approach
### Two point
- **Parsing**: 
    這題用到的邏輯是two point，通過兩個指針移動操作來實現O(N)的算法，
    題目給出一個vector，要求要將內容平方後再排序完，聽起來很簡單，但是其中會有負數，
    負數平方後就有可能會超過正數的平方，這裡需要想個辦法來把正確的評估要把數字平方後再快速的排序好，

    這裡宣告變數，首先left跟right分別是指向vector的頭跟尾，因為數字雖然有正有負，
    但是數字取絕對值之後還是可以比較，所以我們可以用兩個指針指向vector的頭尾，假如vector中有正負數字，0應該在中間，所以向中間夾緊應該可以得到正確的順序，
    ret是用來回傳的vector，而因為我們需要回傳的vector是由小排到大，所以最大的數字應該要放在尾巴，
    所以cnt是用來將計算出來的數字放到ret中對應的位置，這裡就傾向從尾巴開始放，
    ```
    int left = 0; 
    int right = nums.size()-1;
    int cnt = nums.size()-1;
    vector<int> ret(nums.size(), 0);
    ```
    通過for迴圈掃過整個vector，
    ```
    for(int i=0;i<nums.size();i++) {
    ```
    比較兩端的數字絕對值，假如是left這端比較大，將其平方後放入到ret中，然後移動cnt跟left的位置，
    ```
    if(abs(nums[left]) > abs(nums[right])) {
        ret[cnt--] = nums[left]*nums[left];
        left++;
    }
    ```
    假如是right端比較大，也是做同樣的動作，差別是left是加，right是減
    ```
    else {
        ret[cnt--] = nums[right]*nums[right];
        right--;
    }
    ```
- **空間複雜度**: O(1)
- **時間複雜度**: O(N)