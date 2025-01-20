# 59. Spiral Matrix II

🟠 Medium

Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

Example 1:
```
Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]
```
![示例圖片](image.png)

Example 2:
```
Input: n = 1
Output: [[1]]
```

Constraints:
- 1 <= n <= 20

## Approach
### 暴力解
- **Parsing**: 
    題目給出一個數字，要求回傳這個數字n*n的vector，內容要是1~n*n，並且是以螺旋的方式填滿。
    首先建立要回傳的二維vector，這裡要注意，建立vector的時候可以通過()來宣告大小跟其內容，()中的前項是vector的大小，()的後項是其中要填滿的內容，
    所以這裡要建立二維vector，前面先宣告大小為n，接著再宣告其中的內容是另一個vector，基本上就是二維陣列了。
    ```
    vector<vector<int>> ret(n, vector<int>(n));
    ```
    因為要螺旋填滿，所以宣告四個變數來紀錄四方的邊界，還有要填入的數值cnt，最後是控制的方向dir。
    ```
    int left = 0, right = n-1, up = 0, down = n-1;
    int cnt = 1;
    int dir = 0;
    ```
    然後通過while迴圈來限制住計算的條件，因為隨著逐漸地計算，四方邊界會漸漸收斂，所以while的條件是左邊不能超過右邊，下面不能小於上面，只要超過就代表表格已經填滿，可以跳出了。
    ```
    while(left<=right && up<=down) {
    ```
    這裡選擇一個方向說明，首先從表格的左方填到右方，這時候i要等於左方，一路處理到右方所在的地方，在過程中要累加cnt，當走完一個方向後，因為這時候是左到右，所以上方邊界要向下一格，並且轉移方向。
    ```
    if(dir==0) {
        for(int i=left;i<=right;i++) {
            ret[up][i] = cnt++;
        }
        up++;
        dir = 1;
    } 
    ```
- **空間複雜度**: O(N*N)
- **時間複雜度**: O(N*N)