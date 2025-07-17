# 107. Binary Tree Level Order Traversal II

🟠 Medium

Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values. (i.e., from left to right, level by level from leaf to root).

Example 1:
![alt text](image.png)
```
Input: root = [3,9,20,null,null,15,7]
Output: [[15,7],[9,20],[3]]
```

Example 2:
```
Input: root = [1]
Output: [[1]]
```

Example 3:
```
Input: root = []
Output: []
```

Constraints:
- The number of nodes in the tree is in the range [0, 2000].
- -1000 <= Node.val <= 1000

## Approach
### queue
- **Parsing**: 
    題目要求將tree以階層區分，從最底層開始，將每一層的內容填入vector中回傳。

    可以通過queue來實現tree的每個節點的歷遍，最後再將結果反轉即可。
- **空間複雜度**: O(N)
- **時間複雜度**: O(N)