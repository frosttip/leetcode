# 901. Online Stock Span

🟠 Medium

Design an algorithm that collects daily price quotes for some stock and returns the span of that stock's price for the current day.

The span of the stock's price in one day is the maximum number of consecutive days (starting from that day and going backward) for which the stock price was less than or equal to the price of that day.

For example, if the prices of the stock in the last four days is [7,2,1,2] and the price of the stock today is 2, then the span of today is 4 because starting from today, the price of the stock was less than or equal 2 for 4 consecutive days.
Also, if the prices of the stock in the last four days is [7,34,1,2] and the price of the stock today is 8, then the span of today is 3 because starting from today, the price of the stock was less than or equal 8 for 3 consecutive days.
Implement the StockSpanner class:

StockSpanner() Initializes the object of the class.
int next(int price) Returns the span of the stock's price given that today's price is price.

Example 1:
```
Input
["StockSpanner", "next", "next", "next", "next", "next", "next", "next"]
[[], [100], [80], [60], [70], [60], [75], [85]]
Output
[null, 1, 1, 1, 2, 1, 4, 6]

Explanation
StockSpanner stockSpanner = new StockSpanner();
stockSpanner.next(100); // return 1
stockSpanner.next(80);  // return 1
stockSpanner.next(60);  // return 1
stockSpanner.next(70);  // return 2
stockSpanner.next(60);  // return 1
stockSpanner.next(75);  // return 4, because the last 4 prices (including today's price of 75) were less than or equal to today's price.
stockSpanner.next(85);  // return 6
```

Constraints:
- 1 <= price <= 105
- At most 104 calls will be made to next.

## Approach
### Stack
- **Parsing**: 
    這題給出兩個函數要求完成，一個是跟class同名的建構函數，另一個是next，通過呼叫next這個函數，輸入當天的股票價值，
    要給出現在的數值是幾天之中的最高值，當天也算一天。

    解題思路，這題可以通過stack解開，但是需要多點變形，因為要求比較的內容有天數，也有數值，所以可以通過pair來組合兩
    個數值然後填入stack中，
    像是範例，第一個數值是100，因為是第一個數字，所以理所當然是價格無從比較，所以是這一天之類的最高價，那就會是
    stack: {100, 1}
    接著下一個數字是80，80並沒有比100大，所以結果如下，
    stack: {100, 1} {80, 1}
    再來，60，
    stack: {100, 1} {80, 1} {60, 1}
    接著，70，注意，這時候70比60大，所以他應該是這兩天之間的最高點，因為加上當天的數值，所以70的ret為1，加上60的second:1
    所以是
    stack: {100, 1} {80, 1} {70, 2}
    通過以上的邏輯，雖然較小的數值會被丟棄掉，但是因為取代他的數值會將他的成為最高點的數值也一起繼承下來，所以通過這種方式，
    比較大小的邏輯就出來了。

    首先建立，將pair存起來的stack。
    ```
    std::stack<std::pair<int, int>> st;
    ```
    因為這題並不需要其他結構，所以不需要完成建構函數，只要完成next函數就好，先建立變數ret，初值為1，因為沒有大於前幾天，當天
    也需要計算。
    ```
    int ret = 1;
    ```
    接著通過while來嘗試探索stack，但是需要stack不為空，並且輸入的當天股票點數要高於stack中最上面的數值，
    假如沒有，或是已經在while中計算完成了，將他們做成pair後存入stack中。
    ```
    while(!st.empty() && price >= st.top().first) {
    }
    st.push(std::make_pair(price, ret));
    ```
    而在while中，因為pair的first存的是股票數值，而second存的就是該股票為高點的天數，將其跟ret相加，就可以丟棄了。
    ```
    ret += st.top().second;
    st.pop();
    ```
- **空間複雜度**: 
- **時間複雜度**: 