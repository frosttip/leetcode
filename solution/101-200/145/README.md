# 145. Binary Tree Postorder Traversal

🟢 Easy

Given the root of a binary tree, return the postorder traversal of its nodes' values.

Example 1:
```
Input: root = [1,null,2,3]

Output: [3,2,1]

Explanation:
```
![alt text](image.png)

Example 2:
```
Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]

Output: [4,6,7,5,2,9,8,3,1]

Explanation:
```
![alt text](image-1.png)

Example 3:
```
Input: root = []

Output: []
```

Example 4:
```
Input: root = [1]

Output: [1]
```

Constraints:
- The number of the nodes in the tree is in the range [0, 100].
- -100 <= Node.val <= 100

## Approach
### 迭代法 || 遞歸法
- **Parsing**: 
    後序遍歷，順序是，左右中，通過最直覺的遞規，只要先遞迴左跟右，最後再將當前訪問到的節點的數值填入回傳的vector中，即可完成，

    但是迭代法就會有點不同了，前序遍歷的順序是中左右，而在144題中，已經詳細解釋過這個流程了，可以先參考144的做法，
    然後小改一下，當作前序遍歷的時候，是中左右，假設將塞入stack的順序稍微改變，變成中右左，接著再反轉，那不就會變成左右中了嗎?
    ```
     前序        改變左右填入順序         反轉
    中左右  -->      中右左       -->    左右中
    ```
    根據以上的推倒，所以只需要將144提的解法，改變一下填入stack的順序，最後再將ret中的數值反轉，那就可以得到後序遍歷的結果了。
- **空間複雜度**: O(N)
- **時間複雜度**: O(N)