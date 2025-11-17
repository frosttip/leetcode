# 106. Construct Binary Tree from Inorder and Postorder Traversal

🟠 Medium

Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

Example 1:
![alt text](image.png)
```
Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]
```

Example 2:
```
Input: inorder = [-1], postorder = [-1]
Output: [-1]
```

Constraints:
- 1 <= inorder.length <= 3000
- postorder.length == inorder.length
- -3000 <= inorder[i], postorder[i] <= 3000
- inorder and postorder consist of unique values.
- Each value of postorder also appears in inorder.
- inorder is guaranteed to be the inorder traversal of the tree.
- postorder is guaranteed to be the postorder traversal of the tree.

## Approach
### Inorder, postorder
- **Parsing**: 
    題目給出一個inorder跟一個postorder的陣列，要求通過這兩個陣列，還原出本來的二元樹。

    Inorder，中序歷遍，左中右。
    postorder，後續歷遍，左右中。

    這兩個歷遍方法要熟記。

    因為要通過這兩個陣列來還原二元樹，所以要有辦法從這兩個樹去找出樹跟子樹的根，並且區分出左子樹的範圍跟右子樹的範圍，
    所以這裡建立一個輔助用的func，
    除了本來就有的兩個陣列，還加入了inorder的起點終點，還有postorder的起點終點，
    ```
    TreeNode* help(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int posStart, int posEnd) {
    ```

    並且，這題的設定是，起點跟終點是指向index本身，而不是陣列的大小，
    在遞迴最重要的就是設定停止判斷式，這裡就採用，當起點大於終點，那就回傳nullptr，作為終止遞迴的條件。
    ```
    if(inStart>inEnd || posStart>posEnd) {
        return nullptr;
    }
    ```

    接著重點，找出當前的根，
    其實只要去找postorder的終點的內容就是根，
    因為postorder的歷遍順序是左右中，根結點就會是放在最後一個位置。
    ```
    TreeNode* root = new TreeNode(postorder[posEnd]);
    ```

    因為已經透過postorder找到根結點了，
    再用這個根結點，去找尋根結點落在inorder的哪個位置，
    當找到inorder的根結點後，這個節點的前後，就會是左右子樹的範圍，
    在inorder中，
    根節點的左方第一個節點是左子樹的終點。
    根節點的右方第一個節點是右子樹的起點。
    透過這個做法就可以確認inorder的左右子樹的範圍了。
    ```
    int inStart_l = 0, inEnd_l = 0, inStart_r = 0, inEnd_r = 0;
    for(int i=inStart;i<=inEnd;i++) {
        if(inorder[i]==postorder[posEnd]) {
            inEnd_l = i-1;
            inStart_r = i+1;
            break;
        }
    }
    ```

    接著難題是，如何找到postorder的左右子樹範圍，
    這裡先找左子樹，
    postorder的口訣是左右中，所以本來的start就是左子樹的起點，
    但是左子樹的終點，需要靠inorder來計算，
    因為這是在描述同一樹，所以左右子樹的節點個數是相同的，不可能在inorder歷遍的時候，左子樹是3個節點，在postorder的時候左子樹會變成4個節點，
    子樹的節點一定是相同的，所以前面已經找到inorder的左子樹範圍了，所以只要把inorder的左子樹起點到終點的差值，
    加上postorder的起點，那就會是終點的位置。
    ```
    root->left = help(inorder, postorder, inStart, inEnd_l, posStart, posStart+(inEnd_l-inStart));
    ```

    而右子樹已是相同的邏輯，postorder的終點就是最後一個位置的前一個位置，這就是右子樹終點，
    而右子樹的起點，就是剛剛算出來的左子樹的終點加一，
    因為已知postorder歷遍是左右中，左邊結束後，馬上就接右邊，
    那左子樹的終點的下一個內容，很明顯就是右子樹起點，
    ```
    root->right = help(inorder, postorder, inStart_r, inEnd, posStart+(inEnd_l-inStart+1), posEnd-1);
    ```

    完成遞迴後，直接回傳root就可以了。

- **空間複雜度**: O(N)
- **時間複雜度**: O(N)