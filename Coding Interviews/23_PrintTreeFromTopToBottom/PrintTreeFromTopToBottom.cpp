/*****************************************
Copyright: Amusi
Author:    Amusi
Date:      2018-07-30


题目描述
从上往下打印出二叉树的每个节点，同层节点从左至右打印。

*****************************************/

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