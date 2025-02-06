# 1002. Find Common Characters

🟢 Easy

Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates). You may return the answer in any order.

Example 1:
```
Input: words = ["bella","label","roller"]
Output: ["e","l","l"]
```

Example 2:
```
Input: words = ["cool","lock","cook"]
Output: ["c","o"]
```

Constraints:
- 1 <= words.length <= 100
- 1 <= words[i].length <= 100
- words[i] consists of lowercase English letters.

## Approach
### Hash map
- **Parsing**: 
    這題給出連續幾個詞，要求找出這幾個詞中的共同字元，假如有重複的字元，只要重複的次數相同，也要記錄下來。
    這裡使用的是hash map，通過宣告array來記錄出現字元的頻率。先用一個array來記錄第一個詞的每個字元的數量，接著用第二個array來記錄之後每個詞的每個字元的數量，每紀錄完一次，就跟第一個array比較每個字元的數量，取較少數量存到第一個array，一路做到最後一個詞後，就可以取得有出現在所有詞的字元了。
    以下是初始宣告的變數，一開始是回覆的vector ret，接著是用來記錄字元頻率的map，最後是用來記錄除了第一個詞之外的所有字元的compare_map。
    ```
    std::vector<std::string> ret;
    int map[26] = {0};
    int compare_map[26] = {0};
    ```
    首先先用for迴圈將第一個詞的每個字元記錄到第一個array。
    ```
    for(int i=0;i<words[0].size();i++) {
        map[words[0][i] - 'a']++;
    }
    ```
    接著用雙for迴圈將之後的每個詞的字元都記錄到compare_map，要記的，每次比較另一個新的詞的時候，都要將compare_map的內容清為0，記錄完之後要跟map的內容比較，取較少的數量存回到map中。
    ```
    for(int i=1;i<words.size();i++) {
        memset(compare_map, 0, sizeof(compare_map));
        for(int j=0;j<words[i].size();j++) {
            compare_map[words[i][j] - 'a']++;
        }

        for(int k = 0;k<26;k++) {
            map[k] = std::min(map[k], compare_map[k]);
        }
    }
    ``` 
    當比較完所有的詞後，因為map中的字元數量就會是出現在所有詞中的字元，這時候建立一個暫時的string s來儲存字元，然後放到ret中，完成後回傳即可。
    ```
    for(int i=0;i<26;i++) {
        while(map[i]--) {
            std::string s(1, i + 'a');
            ret.push_back(s);
        }
    }

    return ret;
    ```
- **空間複雜度**: O(1)
- **時間複雜度**: O(N*M)