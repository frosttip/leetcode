# 69. Sqrt(x)

🟢 Easy

Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.

 

Example 1:
```
Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.
```

Example 2:
```
Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
```

Constraints:
- 0 <= x <= 231 - 1

## Approach
### 二元搜尋法
- **Parsing**: 
    這題要找出輸入數字的開根號，也就是兩個整數相乘最接近輸入值，假如是有小數點的數值，將其捨去小數點後回傳，
    這裡依樣可以使用二元搜尋法，但是還是有他變形之處，
    首先宣告計算變數，這裡都使用long來宣告是因為，leetcode會傳入相乘後超過int最大值的數值，用int宣告的話，會在計算後超過int的範圍，所以要用long，
    ```
    long left = 0;
    long right = x;
    long mid = 0;
    long ret = 0;
    ```
    老規矩，二元搜尋法就是要用左右邊界去找出中間值，相加除二找中間值，
    ```
    mid = (left + right)/2;
    ```
    假如mid的平方就是x，那就直接回傳，因為回傳值是int，所以要轉型後再回傳，
    ```
    if(mid*mid == x) {
        return (int)mid;
    }
    ```
    假如mid平方大於x，那就代表太大了，移動right到mid左邊再來一次，
    ```
    else if(mid*mid > x) {
        right = --mid;
    }
    ```
    這裡要注意，假如mid的平方小於x，因為我們尋找的是平方根最接近的數值，以8的平方根為例，8的平方根是2.多，根本不可能通過這個算式算出來，
    所以我們每次計算出mid的平方小於x時，都要把mid記錄起來，假如跳出while後，就可以將其回傳。
    ```
    else {
        ret = mid;
        left = ++mid;
    }
    ```


- **空間複雜度**: O(1)
- **時間複雜度**: O(log(N))