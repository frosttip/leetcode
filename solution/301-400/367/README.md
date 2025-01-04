# 367. Valid Perfect Square

🟢 Easy

Given a positive integer num, return true if num is a perfect square or false otherwise.

A perfect square is an integer that is the square of an integer. In other words, it is the product of some integer with itself.

You must not use any built-in library function, such as sqrt.

Example 1:
```
Input: num = 16
Output: true
Explanation: We return true because 4 * 4 = 16 and 4 is an integer.
```

Example 2:
```
Input: num = 14
Output: false
Explanation: We return false because 3.742 * 3.742 = 14 and 3.742 is not an integer.
```

Constraints:
- 1 <= num <= 231 - 1

## Approach
### 二元搜尋法
- **Parsing**: 
    這題使用的是二元搜尋法，題目很單純，跟34有點類似但更簡單，
    function會輸入一個數值，要求確認這個數值是否會有完美平方根，也就是它會是一個整數的平方，是就回傳true，否就回傳false，
    所以這裡直接描述做法，通過二元搜尋法找到中間值，只要中間值平方會等於輸入值，回傳true，假如跳出while，回傳false。
- **空間複雜度**: O(1)
- **時間複雜度**: O(log(N))