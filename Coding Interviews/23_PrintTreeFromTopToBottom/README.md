# 从上往下打印二叉树

# 题目描述

从上往下打印出二叉树的每个节点，同层节点从左至右打印。

# 解题思路

考查知识点：

- 二叉树
- 队列（queue）知识点

这道题看起来是考查树的遍历算法，但这种按层遍历算法并不是我们熟悉的前序遍历、中序遍历和后序遍历。

解决此题的关键在于使用先入先出的队列（queue）。因为我们可以观察从上往下打印二叉树的规律：每一次打印一个结点的时候，如果该结点有子结点，则把该结点的子结点放到一个队列的末尾。接下来到队列头部取出最早进入队列的结点，重复前面的打印操作，直到队列中的所有的结点都被打印出来为止。详见下述代码

# 代码

[C++](PrintTreeFromTopToBottom.cpp)

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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        /* 方法1：不管指针是不是空的都先入队，出队的时候再判断
        std::queue<TreeNode*> q;    // 最早被压入队列的元素
        q.push(root);
        vector<int> resultTree;
        // 判断队列是否为空
        while(q.size()){         // while(!q.empty())
            root = q.front();    // 最早被压入队列中的元素
            q.pop();             // 弹出队列的第一个元素
            // 不管指针是不是空的都先入队，出队的时候再判断
            if(!root)
                continue;
            // 将当前队列中的第一个元素存储起来
            resultTree.push_back(root->val);
            q.push(root->left);    // 从左
            q.push(root->right);   // 到右
        }
        return resultTree;
        */
        
        // 方法2：先判断指针是否为空
        vector<int> resultTree;
        if(root == NULL)
            return resultTree;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            resultTree.push_back(q.front()->val);
            if(q.front()->left!=NULL)
                q.push(q.front()->left);
            if(q.front()->right!=NULL)
                q.push(q.front()->right);
            q.pop();
        }
        return resultTree;
    }
};
```

[Python](PrintTreeFromTopToBottom.py)

```python
# -*- coding:utf-8 -*-
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    # 返回从上到下每个节点值列表，例：[1,2,3]
    # 广度优先搜索 BFS, 借助一个队列就可以实现
    def PrintFromTopToBottom(self, root):
        # write code here
        result_list = []
        if root==None:
            return result_list
        q = []
        q.append(root)
        while len(q) > 0:
            node = q.pop(0)
            result_list.append(node.val)
            if node.left:
                q.append(node.left)
            if node.right:
                q.append(node.right)
            
        return result_list
```

# 参考

https://www.nowcoder.com/questionTerminal/d77d11405cc7470d82554cb392585106