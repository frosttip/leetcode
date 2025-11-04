# Q1. Remove Zeros in Decimal Representation

🟢 Easy

You are given a positive integer n.

Return the integer obtained by removing all zeros from the decimal representation of n.

Note: Please do not copy the description during the contest to maintain the integrity of your submissions.

Example 1:
```
Input: n = 1020030

Output: 123

Explanation:

After removing all zeros from 1020030, we get 123.
```

Example 2:
```
Input: n = 1

Output: 1

Explanation:

1 has no zero in its decimal representation. Therefore, the answer is 1

Note: Please do not copy the description during the contest to maintain the integrity of your submissions.
```

Constraints:
- 1 <= n <= 1015

## Approach
### greedy
- **Parsing**: 
    題目給出一個數值，要求將其中的0都去除並返回。

    這題其實體簡單的，當拿到數值後，只要先取出當前數字除以10的餘數，先拿到這個數值，
    接著因為我們是從取餘數，所以計算是從尾巴開始，所以要有一個用來記錄當前是10的倍數的變數，
    接著每次找到一個餘數，就將餘數呈上10倍數的變數後，加回回傳值，
    之後將10倍數變數再乘10，並將n除10，如此反覆直到n為0即可。

    這裡先建立回傳值跟用來記錄目前走到第幾位的10倍數。
    ```
    int times = 1;
    long long ret = 0;
    ```

    用while迴圈，每次都將n除以10，直到n為0之後，就會自動跳出while，
    ```
    while(n) {
        n /= 10;
    }
    ```

    接著就是取n除以10的餘數，只要有餘數，就將餘數tmp，乘上當前10的倍數變數，並加給回傳值，最後將10倍數再乘10，這樣下一次的餘數就可以在上到下一個位置。
    ```
    if(n%10) {
        int tmp = n%10;
        ret += tmp*times;
        times *= 10;
    }
    ```
- **空間複雜度**: O(N)
- **時間複雜度**: O(N)