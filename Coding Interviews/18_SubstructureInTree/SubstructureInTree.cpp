/*****************************************
Copyright: Amusi
Author:    Amusi
Date:      2018-07-01

题目描述
输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）

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