# 404. Sum of Left Leaves

🟢 Easy

Given the root of a binary tree, return the sum of all left leaves.

A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.

Example 1:
![alt text](image.png)
```
Input: root = [3,9,20,null,null,15,7]
Output: 24
Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.
```

Example 2:
```
Input: root = [1]
Output: 0
```

Constraints:
- The number of nodes in the tree is in the range [1, 1000].
- -1000 <= Node.val <= 1000

## Approach
### DFS
- **Parsing**: 
    題目給出一個二元樹，要求計算出這個二元樹的所有左子葉的合，葉子的定義是沒有左右子樹的節點才叫葉子。

    這題可以使用遞迴，只要在呼叫function本身，用inorder的方法來完成二元樹歷遍，
    所以遞迴的第一要點，就是確定停止的時間，只要輸入的pointer為nullptr，那就停止，並回傳0。
    ```
    if(root == NULL) {
        return 0;
    }
    ```

    接著建立當前節點要計算回傳的變數ret，
    然後判斷，要注意，判斷式有優先順序，所以首先判斷左樹是否為空，假如不為空，那再接著判斷是否左樹的左右子樹都為空，
    假如成立，那當前節點的左子樹就是左葉子，所以要將其累加進回傳的變數裡。
    ```
    int ret = 0;

    if(root->left!=nullptr && root->left->left==nullptr && root->left->right==nullptr) {
        ret += root->left->val;
    }
    ```

    因為採用的是inorder，所以再去往左右子樹探索，因為停止的條件為root為nullptr的時候，
    所以並不需要確定左子樹或是右子樹存在才可以向下探索。
    ```
    ret += sumOfLeftLeaves(root->left);
    ret += sumOfLeftLeaves(root->right);
    ```

- **空間複雜度**: O(N)
- **時間複雜度**: O(N)