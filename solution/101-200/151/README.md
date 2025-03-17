# 151. Reverse Words in a String

🟠 Medium

Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

Example 1:
```
Input: s = "the sky is blue"
Output: "blue is sky the"
```

Example 2:
```
Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
```

Example 3:
```
Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
```

Constraints:
- 1 <= s.length <= 104
- s contains English letters (upper-case and lower-case), digits, and spaces ' '.
- There is at least one word in s.

## Approach
### 
- **Parsing**: 
    題目給出一個字串，要求將字串中的內容去除無用的空格，並且將單字的字元反轉，但是不要改變單字的順序。

    這題使用的手法較需要想像力，以第二個範例來說，前後都有無用的空格，
    "  hello world  "
    假如我們先將整個字串反轉，那就會變成，
    "  dlrow olleh  "
    在接著，我們需要有方法可以跳過前面的空格，並精準的抓到第一個字，再次將這個字反轉，這樣就會成為符合題目要求的答案了。

    這裡我們不要宣告另一個空間，我們直接使用同一個空間來操作，
    先宣告兩個用來操作的index，
    ```
    int left = 0;
    int right = 0;
    ```

    首先按造前面的第一個步驟，先反轉整個字串。
    ```
    reverse(s.begin(), s.end());
    ```

    接著通過for迴圈來掃過整個string，但是這個for並沒有要慢慢地掃過string，他其實是第三個指針，用來當作跳過空格的一個指針。
    ```
    for(int i=0;i<s.size();) {
    ```

    先用while迴圈判斷i目前指向的內容是不是空格，是的話就一直遞增i，達到跳過空格的目的。
    ```
    while(s[i] == ' ' && i<s.size()) {
        i++;
    }
    ```

    但是指針走著走著有可能會跑出string的範圍，有可能前面就是超出string的範圍才跳離while，這裡多一個判斷式來判斷這個狀況，只要超過string空間就離開for。
    ```
    if(i >= s.size()) {
        break;
    }
    ```

    以第一個範例，當走到這裡時，狀況會如下，
    "  dlrow olleh  "
       ^- i = 2
     ^-right = 0
     ^-left = 0
    i的位置在2，正指向d，right跟left還指向string的起始位置，
    從這個點開始，將i指向的內容複製給right的位置，兩個指針一起向前，當i指向的位置不為空格，就一直往下走。
    ```
    while (s[i] != ' ' && i<s.size())
    {
        s[right++] = s[i++];
    }
    ```
    當脫離while的時候，i指向空格，位在index:7，而right正在index:5，這時候第一個字已經被複製出來了，
    "  dlrow olleh  "
            ^- i = 7
    "dlrowow olleh  "
          ^-right = 5
     ^-left = 0
     
    這時候我們可以再做一次翻轉，將第一個字給扭回來。
    要注意，reverse的時候是以前項的位置到後項的位置的前一個來反轉，所以寫法如下，
    ```
    reverse(s.begin()+left, s.begin()+right);
    ```
    可以看到第一個"world"已經被扭回來了，
    "  dlrow olleh  "
            ^- i = 7
    "worldow olleh  "
          ^-right = 5
     ^-left = 0

    因為字與字間會需要一個空格，所以將right當前的位置指定為空格，然後right向後移動一格。
    ```
    s[right++] = ' ';
    ```
    "  dlrow olleh  "
            ^- i = 7
    "world w olleh  "
           ^-right = 6
     ^-left = 0

    接著將left移到right當前的位置，這就是下一個字的起始點，
    因為當前i的位置指向的內容一定為空格，所以將其再往後移動一個，如此往復，所有的字都會扭回來。
    ```
    left = right;
    i++;
    ```

    當脫離整個for之後，這時候各個指針應該會是下面這個狀況，i因為已經超出string的大小了，所以脫離for，
    而right跟left會再12的位置，
    "  dlrow olleh  "
                    ^- i = 15
    "world hello h  "
                 ^-right = 12
                 ^-left = 12
    
    這時候要把整個string的大小重新調整，因為題目要求回傳的字串除了字跟字中間的空格，前後都不能有空格，
    而這時候string的尾巴不只有空格，還有不需要的字元，所以可以通過字串的resize來將大小調整並捨棄不要的內容，
    因為right目前的數值是12，因為每個字結束後就會再字的後面加上一個空格後再往後移一格，
    而right的意義是index，index是從0開始計算，所以其值就會是當前字串所需長度再加一，
    所以resize的數字就會是right減一後的值。
    ```
    s.resize(right-1);
    ```
- **空間複雜度**: O(1)
- **時間複雜度**: O(N)