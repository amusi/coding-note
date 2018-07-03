/*****************************************
Copyright: Amusi
Author:    Amusi
Date:      2018-07-03


题目描述
操作给定的二叉树，将其变换为源二叉树的镜像。

输入描述:
二叉树的镜像定义：源二叉树 
    	    8
    	   /  \
    	  6   10
    	 / \  / \
    	5  7 9 11
    	镜像二叉树
    	    8
    	   /  \
    	  10   6
    	 / \  / \
    	11 9 7  5

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
    // 思路: 左右非子结点互换

    void Mirror(TreeNode *pRoot) {
        // 递归法
        /*
        // 判断输入是不是空树
        if(pRoot == NULL)
            return;
        //(可选) 判断是不是非叶子结点
        if(pRoot.left==NULL && pRoot.right==NULL)
            return;
        // 交换非叶子结点
        TreeNode *pTemp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = pTemp;
        
        // 如果是非叶子结点，则继续递归
        if(pRoot->left!=NULL)
            Mirror(pRoot->left);
        if(pRoot->right!=NULL)
            Mirror(pRoot->right);
        */
    
        // 循环法（非递归）
        if(pRoot==NULL)
            return;
        stack<TreeNode*> stackNode;
        stackNode.push(pRoot);
        while(stackNode.size()){
            TreeNode* tree=stackNode.top();
            stackNode.pop();
            if(tree->left!=NULL || tree->right!=NULL){
                TreeNode *ptemp=tree->left;
                tree->left=tree->right;
                tree->right=ptemp;
            }
            if(tree->left)
                stackNode.push(tree->left);
            if(tree->right)
                stackNode.push(tree->right);
        }
    }
};