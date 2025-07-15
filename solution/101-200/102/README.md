# 102. Binary Tree Level Order Traversal

🟠 Medium

Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

Example 1:
![alt text](image.png)
```
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
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
    這題要求，將tree的每一層節點，按造階層位置，填入一個二維vector中。

    這題可以採用queue來完成，通過queue，可以按造順序，將tree的節點塞進去queue，接著再根據填入的順序將其取出，一層一層的填入vector中。

    首先，先建立要回傳的ret，二維vector，並且判斷輸入的tree是否為NULL，假如是就直接回傳空的vector回去就好了。
    ```
    std::vector<std::vector<int>> ret;

    if(root==NULL) {
        return ret;
    }
    ```

    接著建立用來輔助的queue，要記的，放入queue的是Tree的pointer。
    ```
    std::queue<TreeNode*> q;
    ```

    先將根節點填入queue中。
    ```
    q.push(root);
    ```

    接著開啟while loop，只要queue不為空，就一直loop下去。
    ```
    while(!q.empty()) {
    ```

    在while中，要有幾個輔助的變數，首先，建立size，將queue當前儲存的內容的數量記錄起來，
    因為之後的操作會不斷地取出還有填入，所以要在開始的時候記錄起來。
    接著用來記錄當前階層的vector，
    最後是用來操作的tree pointer。
    ```
    int size = q.size();
    std::vector<int> tmp;
    TreeNode* curr;
    ```

    前面已經記錄下當前的queue的大小，這個大小就是當前階層的節點數量，所以用for迴圈去掃過一整層。
    ```
    for(int i=0;i<size;i++) {
    ```

    開始的時候就將queue中的最前面的內容取出，賦予給curr，然後丟棄，取出來的節點，將其值給與紀錄當前階層的vector。
    ```
    curr = q.front();
    q.pop();

    tmp.push_back(curr->val);
    ```

    當記錄完之後，將這個節點的子節點都填入queue中，因為在開始的時候已經紀錄好前一階層的數量，所以這時候填入並不會影響for。
    ```
    if(curr->left) {
        q.push(curr->left);
    }

    if(curr->right) {
        q.push(curr->right);
    }
    ```

    直到一整個階層都記錄完之後，將這個vector填入ret中即可。
    ```
    ret.push_back(tmp);
    ```
- **空間複雜度**: O(N)
- **時間複雜度**: O(N)