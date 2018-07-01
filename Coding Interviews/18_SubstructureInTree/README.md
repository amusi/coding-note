# 题目描述

输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）

# 解题思路

此题考查[二叉树](https://github.com/amusi/coding-note/blob/master/Coding%20Interviews/06_ConstructBinaryTree/Binarytree.md)知识点。

假设输入两颗二叉树的根结点分别是是pRoot1和pRoot2。

**方法：递归法**

先在pRoot1中找到与pRoot2根结点数值相同的结点，然后判断该结点以下的结构与pRoot2是否一致。

如何找到相同的结点呢？那就需要遍历二叉树了。

如何遍历二叉树呢？那就分别从左子树和右子树开始遍历。

此题的关键点在于使用“递归法”和对二叉树遍历的理解（左子树和右子树）。

注：递归法真的很重要！很重要！编写的时候一定要搞清楚输入是什么，输出是什么？以及何时停止问题。

扩展知识点：二叉树的三种遍历方法（前序遍历、中序遍历和后序遍历）

# 代码

[C++](SubstructureInTree.cpp)

递归法

```c++
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    // 判断pRoot2是不是pRoot1的子结构
    // 递归法: 先在pRoot1中找到与pRoot2根结点数值相同的结点，然后判断该结点以下的结构与pRoot2是否一致
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        bool result = false;
        if(pRoot1!=NULL && pRoot2!=NULL){
            // 从pRoot1中查找与pRoot2根结点相同的值
            if(pRoot1->val == pRoot2->val){
                result = DoesTree1HaveTree2(pRoot1, pRoot2);    // 找到啦
                // 从右树开始找
                if(!result)
                    result = HasSubtree(pRoot1->left, pRoot2);
                // 从左树开始找
                if(!result)
                    result = HasSubtree(pRoot1->right, pRoot2);
            }
        }
        return result;
    }
    // 判断pRoot2是不是pRoot1的子树
    bool DoesTree1HaveTree2(TreeNode* pRoot1, TreeNode* pRoot2){
        if(pRoot2==NULL)
            return true;     // 遍历完pRoot2的所有结点
        if(pRoot1==NULL)
            return false;
        if(pRoot1->val != pRoot2->val)
            return false;
        
        return DoesTree1HaveTree2(pRoot1->left, pRoot2->left) && DoesTree1HaveTree2(pRoot1->right, pRoot2->right);
    }
};
```



[Python](SubstructureInTree.py)

递归法

```python
# -*- coding:utf-8 -*-
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    # 递归法
    def HasSubtree(self, pRoot1, pRoot2):
        '''判断pRoot2是不是pRoot1的子树'''
        result = False
        if pRoot1!=None and pRoot2!=None:
            if pRoot1.val==pRoot2.val:
                result = self.DoesTree1HaveTree2(pRoot1, pRoot2)
            if result == False:
                result = self.HasSubtree(pRoot1.left, pRoot2)    # 判断左子树
            if result == False:
                result = self.HasSubtree(pRoot1.right, pRoot2)   # 判断右子树
                
        return result

    def DoesTree1HaveTree2(self, pRoot1, pRoot2):
        '''判断pRoot2是不是pRoot1的子树'''
        if pRoot2==None:
            return True
        if pRoot1==None:
            return False
        if pRoot1.val != pRoot2.val:
            return False
        
        return self.DoesTree1HaveTree2(pRoot1.left,pRoot2.left) and self.DoesTree1HaveTree2(pRoot1.right,pRoot2.right)
```

# 参考

https://www.nowcoder.com/questionTerminal/6e196c44c7004d15b1610b9afca8bd88