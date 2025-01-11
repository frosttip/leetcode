# 904. Fruit Into Baskets

🟠 Medium

You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

- You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
- Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
- Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
Given the integer array fruits, return the maximum number of fruits you can pick.

Example 1:
```
Input: fruits = [1,2,1]
Output: 3
Explanation: We can pick from all 3 trees.
```

Example 2:
```
Input: fruits = [0,1,2,2]
Output: 3
Explanation: We can pick from trees [1,2,2].
If we had started at the first tree, we would only pick from trees [0,1].
```

Example 3:
```
Input: fruits = [1,2,3,2,2]
Output: 4
Explanation: We can pick from trees [2,3,2,2].
If we had started at the first tree, we would only pick from trees [1,2].
```

Constraints:
- 1 <= fruits.length <= 105
- 0 <= fruits[i] < fruits.length

## Approach
### Slide window
- **Parsing**: 
    這題的題目輸入給予一個vector，vector中的每個數字代表的是樹的種類，但是只給你兩個籃子，要求你只能從左邊到右邊之間選定一棵樹開始摘水果，中間不能跳過果樹，每個籃子只能裝一種水果，但是數量不限，當遇到第三種果樹就必須停止。
    按造這個思路，這題需要用到的就是slide window，以下是思考方式
    - 從左到右
    - 只能有兩個數字可以放進籃子
    - 紀錄最長紀錄
    根據這個邏輯我們需要有個結構可以記錄水果種類，所以要用到unordered_map
    ```
    unordered_map<int, int> map;
    ```
    回傳符合條件下，所能拿到最多棵果樹的結果
    ```
    int ret = 0;
    ```
    用來操作slide window的指針
    ```
    int left = 0, right = 0;
    ```
    首先依樣通過操作終點指針，也就是right，通過for迴圈慢慢向後方移動
    ```
    for(right = 0;right<fruits.size();right++) {
    ```
    接著操作unordered_map，將right指向的果樹放到map中，只要map沒有這個數字，就會自動將其新增到map中，fruits[right]會做為index，然後這個index的數值會自動設定為0，因為已經將他放到籃子中了，所以需要將他的數值加一
    ```
    map[fruits[right]]++;
    ```
    接著通過while迴圈一職檢查map的大小是否小於2，假如不小於，那就進入，
    ```
    while(map.size()>2) {
    ```
    接著開始操作window的頭，也就是left指針，當map大小超過2，就代表遇到第三種果樹了，這時候將left指針指到的果樹，將他在map中的index數值減一，
    ```
    map[fruits[left]]--;
    ```
    減完之後檢查map中left指向的果樹index是否已經為0了，確定的話代表這種類的果樹已經沒有了，就要把他從map中去除，
    ```
    if(map[fruits[left]]==0) {
        map.erase(fruits[left]);
    }
    ```
    最後再將left指針向右移
    ```
    left++;
    ```
    當離開while，就代表目前window的內容都是符合題目的要求，所以就可以計算window的長度，然後與回傳值比較大小，較大的那個儲存到ret中
    ```
    ret = max(ret, right - left + 1);
    ```

- **空間複雜度**: O(1)
- **時間複雜度**: O(N)