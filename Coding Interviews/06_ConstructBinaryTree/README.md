# 题目描述

输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。

（推荐阅读）：[二叉树（Binary tree）](Binarytree.md)

# 解题思路

此题考查二叉树的知识点，个人觉得题目不难，但理解数据结构【二叉树】反倒是一件困难的事情。

**关键知识点**

- 二叉树结构
- 前序遍历
- 后序遍历

- [ ] TODO：解题思路

# 代码

[C++](ConstructBinaryTree.cpp)

```c++
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    struct TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in) {
        // pre: 前序遍历结果
        // vin: 中序遍历结果
        // 判断
        int inlen = in.size();
        int prelen = pre.size();
        if (inlen==0 || prelen==0)
            return NULL;
        // 初始化
        TreeNode* root = new TreeNode(pre[0]);
        // 找到根节点在中序遍历中的位置
        int root_index_in_tin=0;
        for(int i=0; i<inlen; ++i){
            if(in[i] == pre[0]){
                root_index_in_tin = i;
                break;
            }
        }
        // 创建
        vector<int> left_pre, right_pre, left_in, right_in;
        // 左子树
        for (int i=0; i<root_index_in_tin; ++i){
            left_in.push_back(in[i]);        // 获得中序排序中的左子树
            left_pre.push_back(pre[i+1]);    // 获得前序排序中的左子树
        }
        // 右子树
        for (int i=root_index_in_tin+1; i<inlen; ++i){
            right_in.push_back(in[i]);
            right_pre.push_back(pre[i]);
        }
        // 递归
        root->left = reConstructBinaryTree(left_pre, left_in);
        root->right = reConstructBinaryTree(right_pre, right_in);
        
        return root;
        
    }
};
```

[Python](ConstructBinaryTree.py)

```python
# -*- coding:utf-8 -*-
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    # 返回构造的TreeNode根节点
    def reConstructBinaryTree(self, pre, tin):
        # write code here
        if  len(pre)==0 or len(tin)==0:
            return None
        root = TreeNode(pre[0])
        root_index_in_tin = tin.index(root.val)
        root.left = self.reConstructBinaryTree(pre[1:root_index_in_tin+1],tin[:root_index_in_tin])
        root.right = self.reConstructBinaryTree(pre[root_index_in_tin+1:],tin[root_index_in_tin+1:])
        return root
```

