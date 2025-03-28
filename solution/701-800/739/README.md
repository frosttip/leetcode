# 739. Daily Temperatures

🟠 Medium

Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

Example 1:
```
Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
```

Example 2:
```
Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]
```

Example 3:
```
Input: temperatures = [30,60,90]
Output: [1,1,0]
```

Constraints:
- 1 <= temperatures.length <= 105
- 30 <= temperatures[i] <= 100

## Approach
### stack
- **Parsing**: 
    題目給出一個vector，vector中的數字代表的是當天的溫度，要求回覆一個vector，表示當天需要再等幾天才能等到比當時還要更高的溫度。
    這題可以通過stack來完成要求，stack的特性是先進後出，這裡的思路是將天氣的index押入stack中，然後只要當前比較的天氣高於stack中
    取出的index指向的天氣，那就可以將當前的index減去stack中的index，就可以取得等待的天數了。

    首先建立用來操作的stack，接著為了要回覆建立的vector，這裡要注意，要預先把vector的大小建立好，並且初始值設定為0。
    ```
    std::stack<int> st;
    std::vector<int> ret(temperatures.size(), 0);
    ```
    接著通過for迴圈掃過整個溫度的vector。
    ```
    for(int i=0;i<temperatures.size();i++) {
    }
    ```
    通過while迴圈，條件設定為stack中必須要不為空，然後stack的top的index所指向的溫度，要小於當前的溫度，這樣才會進入並計算，
    當從while結束，將當前的index押入stack中。
    ```
    while(!st.empty() && temperatures[st.top()] < temperatures[i]) {
    }
    st.push(i);
    ```
    在while中，將stack最上方的數值取出，將其作為index，將當前的指針位置減去index，就會得到要等幾天才會有更高溫，然後將index指
    向的ret的位置，將剛剛減去的數值賦予它，然後將stack中最上方的值拋棄。
    ```
    ret[st.top()] = i - st.top();
    st.pop();
    ```
- **空間複雜度**: O(N)
- **時間複雜度**: O(N)