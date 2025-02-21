# 3447. Assign Elements to Groups with Constraints

🟠 Medium

You are given an integer array groups, where groups[i] represents the size of the ith group. You are also given an integer array elements.

Your task is to assign one element to each group based on the following rules:

An element j can be assigned to a group i if groups[i] is divisible by elements[j].
If there are multiple elements that can be assigned, assign the element with the smallest index j.
If no element satisfies the condition for a group, assign -1 to that group.
Return an integer array assigned, where assigned[i] is the index of the element chosen for group i, or -1 if no suitable element exists.

Note: An element may be assigned to more than one group.

Example 1:
```
Input: groups = [8,4,3,2,4], elements = [4,2]

Output: [0,0,-1,1,0]

Explanation:

elements[0] = 4 is assigned to groups 0, 1, and 4.
elements[1] = 2 is assigned to group 3.
Group 2 cannot be assigned any element.
```

Example 2:
```
Input: groups = [2,3,5,7], elements = [5,3,3]

Output: [-1,1,0,-1]

Explanation:

elements[1] = 3 is assigned to group 1.
elements[0] = 5 is assigned to group 2.
Groups 0 and 3 cannot be assigned any element.
```

Example 3:
```
Input: groups = [10,21,30,41], elements = [2,1]

Output: [0,1,0,1]

Explanation:

elements[0] = 2 is assigned to the groups with even values, and elements[1] = 1 is assigned to the groups with odd values.
```

Constraints:
- 1 <= groups.length <= 105
- 1 <= elements.length <= 105
- 1 <= groups[i] <= 105
- 1 <= elements[i] <= 105

## Approach
### Hash map
- **Parsing**: 
    題目給予兩個vector，groups跟elements，要求找出groups中的數值是否可以被elements中的數值整除，可以的話，將其用elements中整除的數值的index取代，並且，要取index較小的來取代，沒辦法被整除的數值用-1取代。

    這題可以採取類似hash map的形式，做一個mapping table，題目已經提出，兩個vector最長只會到1e5，所以我們可以建立一個長度為1e5+1的vector作為map，內容全部填為-1，然後將elements中的數值，作為index，將其倍數的index都設定為數值的index，但是只對為-1的位置進行取代，這樣的話，就算elements中有其他數值是相同的，但是因為前面已經有一個index較小的完成了，就不會動作，最後再將groups的內容作為index去尋找map中的內容，將其複製給回傳vector就好。

    map是宣告作為mapping table使用，因為題目給出的最大長度為1e5，所以這裡設定為1e5+1。
    ret是作為回傳的vector，因為題目要求是根據elements的內容去修改groups的內容，所以大小建立為groups的size。
    ```
    std::vector<int> map(1e5+1, -1);
    std::vector<int> ret(groups.size(), -1);
    ```

    接著用for歷遍elements。
    ```
    for(int i=0;i<elements.size();i++) {
    ```

    將elements當前的內容取出，給予e，並且比較map中這個位置的值是否已經不為-1了，這就代表可能已經有同樣的數值運算過了，或是倍數，或是可被整除的數字運算過了。
    ```
    int e = elements[i];

    if(map[e] != -1) {
        continue;
    }
    ```

    接著進入while中，這裡是將e的所有倍數作為index，將map中的相對位置的值，修改為e，也就是目前指到的elements的位置，給取代，通過這種方式，就可以建立出一個mapping table，
    ```
    while(e <= 1e5) {
        if(map[e] == -1) {
            map[e] = i;
        }

        e += elements[i];
    }
    ```

    最終，離開第一個for，已經完成map後，再次通過for歷遍groups，這次只需要將map中，以groups的值作為index，將map中的數值複製給ret，即可。
    ```
    for(int i=0;i<groups.size();i++) {
        ret[i] = map[groups[i]];
    }

    return ret;
    ```
- **空間複雜度**: O(1e5)
- **時間複雜度**: O(M+N)