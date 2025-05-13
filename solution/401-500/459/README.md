# 459. Repeated Substring Pattern

🟢 Easy

Given a string s, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.

Example 1:
```
Input: s = "abab"
Output: true
Explanation: It is the substring "ab" twice.
```

Example 2:
```
Input: s = "aba"
Output: false
```

Example 3:
```
Input: s = "abcabcabcabc"
Output: true
Explanation: It is the substring "abc" four times or the substring "abcabc" twice.
```

Constraints:
- 1 <= s.length <= 104
- s consists of lowercase English letters.

## Approach
### 
- **Parsing**: 
    題目給出一個string，要求確認該string是否為多個相同的子字串所組成的。

    要確認這件事的話，我有兩種解法，
    第一種，假如這個字串可以被多個相同的子字串組成，那可以複製兩個字串組合再一起，並且去除頭一個字元跟尾巴一個字元，處理完畢後，還可以在這個字串中找到原字串，
    那就是符合要求的字串，
    像是題目給出的abab，當複製兩次後就會是，abababab，去頭去尾，bababa，但是你還是可以在其中找到本來的字串。
    以下是複製兩個字串組成新字串。
    ```
    std::string tmp = s+s;
    ```

    接著去頭去尾，
    ```
    tmp.erase(tmp.begin());
    tmp.erase(tmp.end()-1);
    ```

    只要從中找到原字串，那就回傳true，找不到就回傳false。
    ```
    if(tmp.find(s) != std::string::npos) {
        return true;
    }
    return false;
    ```

    第二種方法，因為要相同的子字串組合起來還可以成為原字串才符合條件，
    那就當每次子字串的長度可以被原字串整除的時候，將子字串多次複製到原字串長度，看是否跟原字串相同，
    通過這種方式來比較，這種方式效率較差，但也是可以完成要求。

    先計算輸入的字串長度。
    ```
    int slen = s.size();
    ```

    因為要成為字串至少要有兩個字元，所以通過for迴圈來慢慢改變字串長度，然後從index:1開始，並且子字串不可能超過原字串的一半，所以條件設定不超過原字串的一半。
    ```
    for(int i=1;i<=(s.size()/2);i++) {
    ```

    通過substr，取出子字串。
    ```
    std::string tmp = s.substr(0, i);
    ```

    當子字串的長度可以被原字串長度整除，代表該字串有機會進行判斷。
    ```
    if(slen%tmp.size() == 0) {
    ```

    計算子字串需要複製幾次才可以達到原字串的長度。
    ```
    int times = slen/(tmp.size());
    ```

    建立另一個用來比較的空字串，並且多次複製子字串給比較字串。
    ```
    std::string tmp2 = "";
    for(int l=0;l<times;l++) {
        tmp2 += tmp;
    }
    ```

    只要比較字串等同於原字串，那就可以回傳true，當整個for迴圈都跑完了還是不符合條件，那就回傳false。
    ```
    if(tmp2 == s) {
        return true;
    }
    ```
- **空間複雜度**: O(N)
- **時間複雜度**: O(N)