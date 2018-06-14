# 数据结构—二叉树

## 树的定义

[树](http://www.cnblogs.com/polly333/p/4739567.html)是一种数据结构，它是由n（n>=1）个有限结点组成一个具有层次关系的集合。

注：二叉树中的元素称为**结点（node）**

![树](https://img-blog.csdn.net/20170324154348019)

树具有的特点有：

（1）每个结点有零个或多个子结点

（2）没有父节点的结点称为根节点

（3）每一个非根结点有且只有一个父节点

（4）除了根结点外，每个子结点可以分为多个不相交的子树。

 

树的基本术语有：

若一个结点有子树，那么该结点称为子树根的“**双亲**”，子树的根称为该结点的“**孩子**”。有相同双亲的结点互为“**兄弟**”。一个结点的所有子树上的任何结点都是该结点的**后裔**。从根结点到某个结点的路径上的所有结点都是该结点的**祖先**。



**结点的度**：结点拥有的子树的数目

**叶子结点**：度为0的结点

**分支结点**：度不为0的结点

**树的度**：树中结点的最大的度

**层次**：根结点的层次为1，其余结点的层次等于该结点的双亲结点的层次加1

**树的高度**：树中结点的最大层次

**森林**：0个或多个不相交的树组成。对森林加上一个根，森林即成为树；删去根，树即成为森林。

## 二叉树

### 二叉树的定义

二叉树是树的特殊一种，具有如下特点：

1、每个结点最多有两颗子树，结点的度最大为2。

2、左子树和右子树是有顺序的，次序不能颠倒。

3、即使某结点只有一个子树，也要区分左右子树。

二叉树有五种基本形态：二叉树可以是空集；根可以有空的左子树或右子树；或者左、右子树皆为空。

![二叉树五种形态](https://img-blog.csdn.net/20170324154426661)

### 二叉树的性质

性质1：二叉树第i层上的结点数目最多为2^(i-1) (i>=1)

性质2：深度为k的二叉树至多有(2^k)-1个结点（k>=1）

性质3：包含n个结点的二叉树的高度至少为(log2n)+1

性质4：在任意一棵非空的二叉树中，若叶子结点（度为0）的个数为n0，度为2的结点数为n2，则n0=n2+1

- 证明：在一棵二叉树中，除了叶子结点（度为0）之外，就剩下度为2(n2)和1(n1)的结点了。则树的结点总数为T = n0+n1+n2; 在二叉树中结点总数为T，而连线数为T-1（至于非0度采用连线）.所以有：n0+n1+n2-1 = 2*n2 +n1;最后得到n0 = n2+1。

- 举个栗子

  ![二叉树性质4栗子](https://images0.cnblogs.com/blog/451660/201508/181911001445541.png)

### 二叉树种类

#### 斜树(Oblique Tree)

所有的结点都只有左子树（左斜树），或者只有右子树（右斜树）。这就是斜树，应用较少

![斜树](https://note.youdao.com/yws/public/resource/e5d22712496f4f6585b7247eac93871c/xmlnote/WEBRESOURCE0ecdc57388f2c98b9e20a959900a08d7/47830)

#### 满二叉树**(Perfect Binary Tree)**

所有的分支结点都存在左子树和右子树，并且所有的叶子结点都在同一层上，这样就是满二叉树。就是完美圆满的意思，关键在于树的平衡。

换个说法：高度为h，并且由2^h-1个结点组成的二叉树，称为满二叉树

![满二叉树](https://img-blog.csdn.net/20170324154449411)

根据满二叉树的定义，得到其特点为：

1. 叶子只能出现在最下一层。
2. 非叶子结点度一定是2.
3. 在同样深度的二叉树中，满二叉树的结点个数最多，叶子树最多。

#### 完全二叉树**(Complete Binary Tree)**

**定义**：一棵二叉树中，只有最下面两层结点的度可以小于2，并且最下层的叶结点集中在靠左的若干位置上，这样的二叉树称为完全二叉树。

**特点**：叶子结点只能出现在最下层和次下层，且最下层的叶子结点集中在树的左部。显然，一棵满二叉树必定是一棵完全二叉树，而完全二叉树未必是满二叉树。

结合完全二叉树定义得到其特点：

1. 叶子结点只能出现在最下一层（满二叉树继承而来）
2. 最下层叶子结点一定集中在左 部连续位置。
3. 倒数第二层，如有叶子节点，一定出现在右部连续位置。
4. 同样结点树的二叉树，完全二叉树的深度最小（满二叉树也是对的）。

![完全二叉树](https://img-blog.csdn.net/20170324154512412)

根据下图加深理解，什么时候是完全二叉树。

![完全二叉树](http://img.blog.csdn.net/20140424162035437?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvaml1cWl5dWxpYW5n/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

**完全二叉树性质**

a、具有n的结点的完全二叉树的深度为log2n+1.

- 证明：满二叉树是完全二叉树，对于深度为k的满二叉树中结点数量是(2^k)-1 = n，完全二叉树结点数量肯定最多(2^k)-1,同时完全二叉树倒数第二层肯定是满的（倒数第一层有结点，那么倒是第二层序号和满二叉树相同），所以完全二叉树的结点数最少大于少一层的满二叉树，为(2^(k-1)-1。

  根据上面推断得出： (2^(k-1)-1< n=<(2^k)-1，因为结点数Nn为整数那么n<=(2^k)-1可以推出n<=2^k ,n>(2^(k-1)-1可以推出 n>=(2^k)-1,所以(2^k)-1<n<=2^k  。即可得k-1<=log2n<k 而k作为整数因此k=[log2n]+1。

b、如果有一颗有n个节点的完全二叉树的节点按层次序编号，对任一层的节点i（1<=i<=n）有

​    1.如果i=1，则节点是二叉树的根，无双亲，如果i>1，则其双亲节点为[i/2]，向下取整

​    2.如果2i>n那么节点i没有左孩子，否则其左孩子为2i

​    3.如果2i+1>n那么节点没有右孩子，否则右孩子为2i+1

**举个栗子**

![](https://images0.cnblogs.com/blog/451660/201508/181911019725482.png)

在上图中验证

第一条：

当i=1时，为根节点。当i>1时，比如结点为7，他的双亲就是7/2= 3；结点9双亲为4.

第二条：

结点6，6x2 = 12>10，所以结点6无左孩子，是叶子结点；结点5，5x2 = 10，左孩子是10；结点4，4x2=8<10，左孩子为8.

第三条：

结点5，2*5+1>10，没有右孩子；结点4，4x2+1<10，则有右孩子。



**完全二叉树面试题**：如果一个完全二叉树的结点总数为768个，求叶子结点的个数。

由二叉树的性质知：n0=n2+1，将之带入768=n0+n1+n2中得：768=n1+2n2+1，因为完全二叉树度为1的结点个数要么为0，要么为1，那么就把n1=0或者1都代入公式中，很容易发现n1=1才符合条件。所以算出来n2=383，所以叶子结点个数n0=n2+1=384。

**总结规律**：如果一棵完全二叉树的结点总数为n，那么叶子结点等于n/2（当n为偶数时）或者(n+1)/2（当n为奇数时）

### 完满二叉树(Full Binary Tree)

```
A Full Binary Tree (FBT) is a tree in which every node other than the leaves has two children.
```

换句话说，**所有非叶子结点的度都是2**。（**只要你有孩子，你就必然是有两个孩子。**） 

**注：**Full Binary Tree又叫做Strictly Binary Tree。

![完满二叉树](https://images2015.cnblogs.com/blog/1094457/201702/1094457-20170225183305616-1864401342.png)

**总结：完美二叉树（满二叉树）、完全二叉树和完满二叉树**

| **完美二叉树** | Perfect Binary Tree       | Every node except the leaf nodes have two children and every level (last level too) is completely filled. **除了叶子结点之外的每一个结点都有两个孩子，每一层(当然包含最后一层)都被完全填充。** |
| --------- | ------------------------- | ---------------------------------------- |
| **完全二叉树** | Complete Binary Tree      | Every level except the last level is completely filled and all the nodes are left justified. **除了最后一层之外的其他每一层都被完全填充，并且所有结点都保持向左对齐。** |
| **完满二叉树** | Full/Strictly Binary Tree | Every node except the leaf nodes have two children. **除了叶子结点之外的每一个结点都有两个孩子结点。** |

- 完美(Perfect)二叉树一定是完全(Complete)二叉树，但完全(Complete)二叉树不一定是完美(Perfect)二叉树。
- 完美(Perfect)二叉树一定是完满(Full)二叉树，但完满(Full)二叉树不一定是完美(Perfect)二叉树。
- 完全(Complete)二叉树可能是完满(Full)二叉树，完满(Full)二叉树也可能是完全(Complete)二叉树。
- 既是完全(Complete)二叉树又是完满(Full)二叉树也不一定就是完美(Perfect)二叉树。

## 二叉树遍历

二叉树遍历：从树的根节点出发，按照某种次序依次访问二叉树中所有的结点，使得每个结点被访问仅且一次。

这里有两个关键词：**访问**和**次序**。

### 二叉树结构

在介绍二叉树遍历方法之前，先介绍一下二叉树结构。

```
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct BiTree{
  int data;
  struct BiTree *left;
  struct BiTree *right;
};
```

### 前序遍历(Pre-Order Traversal)

![前序遍历](http://my.csdn.net/uploads/201203/27/1332780800_2559.jpg)

基本思想：先访问根结点，再先序遍历左子树，最后再先序遍历右子树，即**根—左—右**。

图中前序遍历结果是：1，2，4，5，7，8，3，6。

**前序遍历算法**：Algorithm Preorder(tree)

      1. Visit the root.
      2. Traverse the left subtree, i.e., call Preorder(left-subtree)
      3. Traverse the right subtree, i.e., call Preorder(right-subtree) 

**1）前序递归遍历**

```c++
//前序递归遍历
void PreOrderTraverse(BiTree t)
{
  	//注意跳出条件
    if(t != NULL)
    {
       //注意访问语句顺序
        printf("%c ", t->data);
        PreOrderTraverse(t->lchild);	// 遍历左子树
        PreOrderTraverse(t->rchild);	// 遍历右子树
    }
}
```

**2）前序非递归遍历**

对于任一结点p：

​        a. 访问结点p，并将结点p入栈；

​        b. 判断结点p的左孩子是否为空，若为空，则取栈顶结点并进行出栈操作，并将栈顶结点的右孩子置为当前的结点p，循环置a；若不为空，则将p的左孩子置为当前结点p；

​        c. 直到p为空，并且栈为空，则遍历结束。

```c++
//前序非递归遍历
int NoPreOrderTraverse(BiTree t)
{
    SqStack s;
    InitStack(&s);
 
    BiTree tmp = t;
    if(tmp == NULL)
    {
        fprintf(stdout, "the tree is null.\n");
        return ERROR;
    }
   //现将左子树压入栈，当到叶子结点后，出栈，获取右子树，然后在压入右子树的左子树。
  //顺序不能变
    while((tmp != NULL) || (IsEmpty(&s) != 1)) 
    {
        while(tmp != NULL)
        {
            Push(&s, tmp);
            printf("%c ", tmp->data);
            tmp = tmp->lchild;
        }
        if(IsEmpty(&s) != 1)
        {
            Pop(&s, &tmp);
            tmp = tmp->rchild;
        }
    }
     
    return OK;
}
```

### 中序遍历(In-Order Traversal)

![中序遍历](http://my.csdn.net/uploads/201203/27/1332780987_8583.jpg)

基本思想：先中序遍历左子树，然后再访问根结点，最后再中序遍历右子树即**左—根—右**。

图中中序遍历结果是：4，2，7，8，5，1，3，6。

**中序遍历算法**：Algorithm Inorder(tree)

      1. Traverse the left subtree, i.e., call Inorder(left-subtree)
      2. Visit the root.
      3. Traverse the right subtree, i.e., call Inorder(right-subtree)

**1）中序遍历迭代代码**

```c++
//中序递归遍历
void InOrderTraverse(BiTree t)
{
    if(t != NULL)
    {
        InOrderTraverse(t->lchild);
        printf("%c ", t->data);
        InOrderTraverse(t->rchild);
    }
}
```

**2）中序非递归遍历**

​    根据中序遍历的顺序，对于任一结点，优先访问其左孩子，而左孩子结点又可以看做一个根结点，然后继续访问其左孩子结点，直到遇到左孩子结点为空的结点才停止访问，然后按相同的规则访问其右子树。其处理过程如下：

​       对于任一结点：

​       a. 若其左孩子不为空，则将p入栈，并将p的左孩子设置为当前的p，然后对当前结点再进行相同的操作；

​       b. 若其左孩子为空，则取栈顶元素并进行出栈操作，访问该栈顶结点，然后将当前的p置为栈顶结点的右孩子；

​       c. 直到p为空并且栈为空，则遍历结束。

```c++
//中序非递归遍历二叉树
int NoInOrderTraverse(BiTree t)
{
    SqStack s;
    InitStack(&s);
     
    BiTree tmp = t;
    if(tmp == NULL)
    {
        fprintf(stderr, "the tree is null.\n");
        return ERROR;
    }
 
    while(tmp != NULL || (IsEmpty(&s) != 1))
    {
        while(tmp != NULL)
        {
            Push(&s, tmp);
            tmp = tmp->lchild;
        }
 
        if(IsEmpty(&s) != 1)
        {
            Pop(&s, &tmp);
            printf("%c ", tmp->data);
            tmp = tmp->rchild;
        }
    }
    return OK;
}
```

### 后序遍历(Post-Order Traversal)

![后序遍历](http://my.csdn.net/uploads/201203/27/1332781113_9913.jpg)

基本思想：先后序遍历左子树，然后再后序遍历右子树，最后再访问根结点即**左—右—根**。

图中后序遍历结果是：4，8，7，5，2，6，3，1。

**后序遍历算法**：Algorithm Postorder(tree)

      1. Traverse the left subtree, i.e., call Postorder(left-subtree)
      2. Traverse the right subtree, i.e., call Postorder(right-subtree)
      3. Visit the root.

后序递归遍历代码实现，如下所示。

```c++
//后序递归遍历
void PostOrderTraverse(BiTree t)
{
    if(t != NULL)
    {
        PostOrderTraverse(t->lchild);
        PostOrderTraverse(t->rchild);
        printf("%c ", t->data);
    }
}
```

**后序遍历的非递归实现是三种遍历方式中最难的一种**。因为在后序遍历中，要保证左孩子和右孩子都已被访问，并且左孩子在右孩子之前访问才能访问根结点，这就为流程控制带来了难题。下面介绍一种思路。

要保证根结点在左孩子和右孩子访问之后才能访问，因此对于任一结点p，先将其入栈。若p不存在左孩子和右孩子，则可以直接访问它，或者p存在左孩子或右孩子，但是其左孩子和右孩子都已经被访问过了，则同样可以直接访问该结点。若非上述两种情况，则将p的右孩子和左孩子依次入栈，这样就保证了每次取栈顶元素的时候，左孩子在右孩子之前别访问，左孩子和右孩子都在根结点前面被访问。

```c++
//后序非递归遍历二叉树
int NoPostOrderTraverse(BiTree t)
{
    SqStack s;
    InitStack(&s);
 
    BiTree cur;     //当前结点  
    BiTree pre = NULL;      //前一次访问的结点
    BiTree tmp;
 
    if(t == NULL)
    {
        fprintf(stderr, "the tree is null.\n");
        return ERROR;
    }
 
    Push(&s, t);
    while(IsEmpty(&s) != 1)
    {
        GetTop(&s, &cur);//
        if((cur->lchild == NULL && cur->rchild == NULL) || (pre != NULL && (pre == cur->lchild || pre == cur->rchild)))
        {
            printf("%c ", cur->data);    //如果当前结点没有孩子结点或者孩子结点都已被访问过
            Pop(&s, &tmp);
            pre = cur;
        }
        else
        {
            if(cur->rchild != NULL)
            {
                Push(&s, cur->rchild);
            }
            if(cur->lchild != NULL)
            {
                Push(&s, cur->lchild);
            }
        }
    }
    return OK;
}
```

**前序排序、中序排序和后序排序总结**

以根结点为基础，根据其位置关系即可判断是前序、中序还是后序。如：

- 前序排序：**根**—左—右
- 中序排序：左—**根**—右
- 后序排序：左—右—**根**

**举个栗子**

![Example Tree](https://www.geeksforgeeks.org/wp-content/uploads/2009/06/tree12.gif)

Depth First Traversals

(a) 前序遍历 Preorder (Root, Left, Right) : 1 2 4 5 3

(b) 中序遍历 Inorder (Left, Root, Right) : 4 2 5 1 3

(c) 后序遍历 Postorder (Left, Right, Root) : 4 5 2 3 1

c++代码

```c++
// C program for different tree traversals
#include <stdio.h>
#include <stdlib.h>
 
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
     int data;
     struct node* left;
     struct node* right;
};
 
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node* newNode(int data)
{
     struct node* node = (struct node*)
                                  malloc(sizeof(struct node));
     node->data = data;
     node->left = NULL;
     node->right = NULL;
 
     return(node);
}
 
/* Given a binary tree, print its nodes according to the
  "bottom-up" postorder traversal. */
void printPostorder(struct node* node)
{
     if (node == NULL)
        return;
 
     // first recur on left subtree
     printPostorder(node->left);
 
     // then recur on right subtree
     printPostorder(node->right);
 
     // now deal with the node
     printf("%d ", node->data);
}
 
/* Given a binary tree, print its nodes in inorder*/
void printInorder(struct node* node)
{
     if (node == NULL)
          return;
 
     /* first recur on left child */
     printInorder(node->left);
 
     /* then print the data of node */
     printf("%d ", node->data);  
 
     /* now recur on right child */
     printInorder(node->right);
}
 
/* Given a binary tree, print its nodes in preorder*/
void printPreorder(struct node* node)
{
     if (node == NULL)
          return;
 
     /* first print data of node */
     printf("%d ", node->data);  
 
     /* then recur on left sutree */
     printPreorder(node->left);  
 
     /* now recur on right subtree */
     printPreorder(node->right);
}    
 
/* Driver program to test above functions*/
int main()
{
     struct node *root  = newNode(1);
     root->left             = newNode(2);
     root->right           = newNode(3);
     root->left->left     = newNode(4);
     root->left->right   = newNode(5); 
 
     printf("\nPreorder traversal of binary tree is \n");
     printPreorder(root);
 
     printf("\nInorder traversal of binary tree is \n");
     printInorder(root);  
 
     printf("\nPostorder traversal of binary tree is \n");
     printPostorder(root);
 
     getchar();
     return 0;
}

```

Python代码

```python
# Python program to for tree traversals
 
# A class that represents an individual node in a
# Binary Tree
class Node:
    def __init__(self,key):
        self.left = None
        self.right = None
        self.val = key
 
 
# A function to do inorder tree traversal
def printInorder(root):
 
    if root:
 
        # First recur on left child
        printInorder(root.left)
 
        # then print the data of node
        print(root.val),
 
        # now recur on right child
        printInorder(root.right)
 
 
 
# A function to do postorder tree traversal
def printPostorder(root):
 
    if root:
 
        # First recur on left child
        printPostorder(root.left)
 
        # the recur on right child
        printPostorder(root.right)
 
        # now print the data of node
        print(root.val),
 
 
# A function to do postorder tree traversal
def printPreorder(root):
 
    if root:
 
        # First print the data of node
        print(root.val),
 
        # Then recur on left child
        printPreorder(root.left)
 
        # Finally recur on right child
        printPreorder(root.right)
 
 
# Driver code
root = Node(1)
root.left      = Node(2)
root.right     = Node(3)
root.left.left  = Node(4)
root.left.right  = Node(5)
print "Preorder traversal of binary tree is"
printPreorder(root)
 
print "\nInorder traversal of binary tree is"
printInorder(root)
 
print "\nPostorder traversal of binary tree is"
printPostorder(root)
```

JAVA

```java
// Java program for different tree traversals
 
/* Class containing left and right child of current
   node and key value*/
class Node
{
    int key;
    Node left, right;
 
    public Node(int item)
    {
        key = item;
        left = right = null;
    }
}
 
class BinaryTree
{
    // Root of Binary Tree
    Node root;
 
    BinaryTree()
    {
        root = null;
    }
 
    /* Given a binary tree, print its nodes according to the
      "bottom-up" postorder traversal. */
    void printPostorder(Node node)
    {
        if (node == null)
            return;
 
        // first recur on left subtree
        printPostorder(node.left);
 
        // then recur on right subtree
        printPostorder(node.right);
 
        // now deal with the node
        System.out.print(node.key + " ");
    }
 
    /* Given a binary tree, print its nodes in inorder*/
    void printInorder(Node node)
    {
        if (node == null)
            return;
 
        /* first recur on left child */
        printInorder(node.left);
 
        /* then print the data of node */
        System.out.print(node.key + " ");
 
        /* now recur on right child */
        printInorder(node.right);
    }
 
    /* Given a binary tree, print its nodes in preorder*/
    void printPreorder(Node node)
    {
        if (node == null)
            return;
 
        /* first print data of node */
        System.out.print(node.key + " ");
 
        /* then recur on left sutree */
        printPreorder(node.left);
 
        /* now recur on right subtree */
        printPreorder(node.right);
    }
 
    // Wrappers over above recursive functions
    void printPostorder()  {     printPostorder(root);  }
    void printInorder()    {     printInorder(root);   }
    void printPreorder()   {     printPreorder(root);  }
 
    // Driver method
    public static void main(String[] args)
    {
        BinaryTree tree = new BinaryTree();
        tree.root = new Node(1);
        tree.root.left = new Node(2);
        tree.root.right = new Node(3);
        tree.root.left.left = new Node(4);
        tree.root.left.right = new Node(5);
 
        System.out.println("Preorder traversal of binary tree is ");
        tree.printPreorder();
 
        System.out.println("\nInorder traversal of binary tree is ");
        tree.printInorder();
 
        System.out.println("\nPostorder traversal of binary tree is ");
        tree.printPostorder();
    }
}
```



## 二叉树的建立

其实二叉树的建立就是二叉树的遍历，只不过将输入内容改为建立结点而已，比如，利用前序遍历建立二叉树

```c++
//创建树
//按先后次序输入二叉树中结点的值(一个字符),#表示空树
//构造二叉链表表示的二叉树
BiTree CreateTree(BiTree t)
{
    char ch;
    scanf("%c", &ch);
 
    if(ch == '#')
    {
        t = NULL;
    }
    else
    {
        t = (BitNode *)malloc(sizeof(BitNode));
        if(t == NULL)
        {
            fprintf(stderr, "malloc() error in CreateTree.\n");
            return;
        }
 
        t->data = ch;                        //生成根结点
        t->lchild = CreateTree(t->lchild);    //构造左子树
        t->rchild = CreateTree(t->rchild);    //构造右子树
    }
    return t;
}
```



# 参考

[Wiki: Binary tree](https://en.wikipedia.org/wiki/Binary_tree)

**（推荐）**[浅谈数据结构—二叉树](http://www.cnblogs.com/polly333/p/4740355.html)：以文字、图示和代码的方式，详细介绍二叉树的定义、性质和种类（中文版）

**（推荐）**[Binary Tree](http://btechsmartclass.com/DS/U3_T3.html) ：以文字、图示和代码的方式，详细介绍二叉树的定义、性质和种类（英文版）

**（重磅推荐）**[Binary Tree Data Structure](https://www.geeksforgeeks.org/binary-tree-data-structure/#Introduction)	：二叉树的定义、遍历和大量练习题，（英文版）

[二叉树常见面试题（进阶）](https://www.cnblogs.com/33debug/p/7252371.html)

[二叉树基础知识总结](https://blog.csdn.net/xiaoquantouer/article/details/65631708)

[完美二叉树, 完全二叉树和完满二叉树](https://www.cnblogs.com/idorax/p/6441043.html)

[看懂二叉树的三种遍历](https://blog.csdn.net/soundwave_/article/details/53120766)

[二叉树可视化网址](https://visualgo.net/zh)

[Binary Trees](https://www.cs.cmu.edu/~adamchik/15-121/lectures/Trees/trees.html)

