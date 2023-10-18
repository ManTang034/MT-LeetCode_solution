# 二叉堆





# 二叉树

```c++
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    TreeNode(int x,TreeNode *left,TreeNode *right):val(x),left(left),right(right){}
};
/*
val表示节点的值，left和right分别表示左子节点和右子节点的指针。
TreeNode():默认构造函数，将val设置为0，left和right设置为nullptr。这个构造函数没有参数，用于创建一个空节点。当我们需要创建一个初始值为空的节点时，可以使用默认构造函数。
TreeNode(int val):构造函数，将val设置为参数值x，left和right设置为nullptr。这个构造函数接受一个整数参数x，用于创建一个只有值为x的节点。当我们只关心节点值而不关心节点时，可以使用值构造函数快速创建一个带有特定值的节点。
TreeNode(int val,TreeNode *left,TreeNode *right):构造函数，将val设置为参数值x，left设置为参数left指向的节点，right设置为参数right指向的节点。
/*
```



### 1. 二叉树的遍历

### 前中后序遍历

按某条搜索路径访问树中的每个结点，使得每个结点均被访问一次，而且仅能访问一次。

> 前序遍历：先输出父节点，再遍历左子树，后遍历右子树
>
> 中序遍历：先遍历左子树，再输出父节点，后遍历右子树
>
> 后序遍历：先遍历左子树，再遍历右子树，后输出父节点

前序、中序、后序遍历依靠父节点输出位置确定。

```c++
void traverse(TreeNode *root){
    // base case
     if(root==nullptr){
         return;
     }
    //前序位置
    traverse(root->left);
    //中序位置
    traverse(root->right);
    //后序位置
}
```



| Number |            Question             | Status |
| :----: | :-----------------------------: | :----: |
| LC 144 | binary-tree-preorder-traversal  |  done  |
| LC 94  |  binary-tree-inorder-traversal  |  done  |
| LC 145 | binary-tree-postorder-traversal |  done  |



### 2.二叉树重构

| Number |                          Question                          | Status |
| :----: | :--------------------------------------------------------: | :----: |
| LC 105 | construct-binary-tree-from-preorder-and-inorder-traversal  |  done  |
| LC 106 | construct-binary-tree-from-inorder-and-postorder-traversal |  done  |



# Timeline

| Number |                          Question                          | Status |   Date   |
| :----: | :--------------------------------------------------------: | :----: | :------: |
| LC 144 |               binary-tree-preorder-traversal               |  done  | 20231017 |
| LC 94  |               binary-tree-inorder-traversal                |  done  | 20231017 |
| LC 145 |              binary-tree-postorder-traversal               |  done  | 20231017 |
| LC 105 | construct-binary-tree-from-preorder-and-inorder-traversal  |  done  | 20231017 |
| LC 106 | construct-binary-tree-from-inorder-and-postorder-traversal |  done  | 20231017 |
| LC 21  |                   merge-two-sorted-lists                   |  done  | 20231018 |
| LC 86  |                       partition-list                       |  done  | 20231018 |
| LC 230 |               kth-smallest-element-in-a-bst                |  done  | 20231018 |
|        |                                                            |        |          |

