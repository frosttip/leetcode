# 344. Reverse String

🟢 Easy

Write a function that reverses a string. The input string is given as an array of characters s.

You must do this by modifying the input array in-place with O(1) extra memory.

Example 1:
```
Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
```

Example 2:
```
Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
```

Constraints:
- 1 <= s.length <= 105
- s[i] is a printable ascii character.

## Approach
### two pointer
- **Parsing**: 
    題目輸入一個vector，內容是字元，要求將其中的字元順序都反轉。
    這裡可以簡單的使用reverse(s.begin(), s.end())，但是這樣很明顯不可能只是考對於function的熟悉度，所以要換個方式。
    本來我採用的方式是用單一個指針，從0開始，走到字串的中間點，用swap，去交換i跟size()-i，這樣來達成，但是這有點不直觀，需要稍微轉一圈思考。
    這裡改用兩個指針，一個指針在字串頭，一個指針在字串尾，通過for迴圈，只要指針頭沒有超過指針尾，那就各自移動，每次移動都是指針頭往後，指針尾往前，所以他們終究會相交，當相交的時候就可以離開for，
    而在移動的過程中就可以交換指針指到的內容了。
    ```
    for(int i=0, j=s.size()-1;i<j;i++, j--) {
    ```

    ```
    std::swap(s[i], s[j]);
    ```
- **空間複雜度**: O(1)
- **時間複雜度**: O(N)