# 242. Valid Anagram

🟢 Easy 

Given two strings s and t, return true if t is an 
anagram of s, and false otherwise.

Example 1:
```
Input: s = "anagram", t = "nagaram"

Output: true
```

Example 2:
```
Input: s = "rat", t = "car"

Output: false
```

Constraints:
- 1 <= s.length, t.length <= 5 * 104
- s and t consist of lowercase English letters.

## Approach
### hash table
- **Parsing**: 
    題目給予兩個string，要求確認，是否都是使用相同的字元，組成不同詞，要求同樣的字元也要有同樣的數量。
    這裡使用hash map來解題，宣告大小為26的array，用來代表26個英文字母。
    ```
    int map[26] = {0};
    ```
    然後通過for迴圈掃過整個s字串，通過減去字元'a'就會將該字元映射到map中，掃到的字元就加一。
    ```
    for(int i=0;i<s.size();i++) {
        map[s[i] - 'a']++;
    }
    ```
    在來同樣通過for回圈掃過t字串，這次要減去掃到的字元。
    ```
    for(int i=0;i<t.size();i++) {
        map[t[i] - 'a']--;
    }
    ```
    最後檢查整個map，只要有其中一個字元不為0，就代表有某個字元多或少，直接回傳false，假如全部都為0，那就回傳true。
    ```
    for(int i=0;i<26;i++) {
        if(map[i] != 0) {
            return false;
        }
    }

    return true;
    ```
- **空間複雜度**: O(1)
- **時間複雜度**: O(M+N)