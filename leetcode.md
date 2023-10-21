# 二叉堆

## 泛型编程

> **泛型编程**是一种编程范式，它的目标是编写可以适用于多种数据类型的通用代码。泛型编程使用类型参数来代表未指定的具体类型，从而实现代码的通用性和重用性。
>
> 泛型编程的优势在于可以构建灵活、可扩展且类型安全的代码。通过使用泛型，我们可以以一种抽象的方式操作数据，而不需要为每种数据类型编写特定的代码。
>
> 在C++中，泛型编程主要借助于模板（template）的机制来实现。通过定义模板类和模板函数，我们可以使用类型参数作为通用的数据类型，使得代码能够适应不同的数据类型。

1.容器类：可以创建泛型容器类，例如列表、队列、堆栈等。这些容器可以存储不同类型的元素，而不需要为每种数据类型编写不同的容器类。

```c++
template<typename T>
class List{
    //实现通用的列表操作
};

List<int> intList;//整数列表
List<char> charList;//字符列表
List<double> doubleList;//浮点数列表
```

2.算法：可以编写泛型算法来对各种数据类型执行相同的操作。例如，排序算法、搜索算法或其他数据处理算法可以以类型参数作为输入和输出。

```c++
template<typename T>
void BubbleSort(T arr[],int size){
    //实现通用的冒泡排序算法
}

int intArr[] = { 4, 2, 7, 1, 5 };
char charArr[] = { 'c', 'a', 'b', 'd' };

BubbleSort(intArr, 5); // 对整数数组进行排序
BubbleSort(charArr, 4); // 对字符数组进行排序
```

3.泛型函数：可以编写接受不同类型参数的泛型函数。这些函数可以适用于多种数据类型，并根据实际的类型参数进行相应的操作。

```c++
template <typename T>
void Print(T value) {
    cout << value << endl; // 打印不同类型的值
}

Print(10); // 打印整数
Print("Hello"); // 打印字符串
Print(3.14); // 打印浮点数
```

## **二叉堆实现优先级队列**

```c++
template<typename Key>
class MaxPQ{
private:
    //存储元素的数组
    Key* pq;
    //当前Priority Queue中的元素个数
    int size=0;
    
public:
    MaxPQ(int cap){
        //索引0不用，所以多分配一个空间
        pq=new Key[cap+1];
    }
    
    //返回当前队列中最大元素
    Key max(){
        return pq[1];
    }
    
    //插入元素e
    void insert(Key e){
        size++;
        //先把元素加到最后
        pq[size]=e;
        swim(size);
    }
    
    //删除并返回当前队列中最大元素
    Key delMax(){
        //最大堆的堆顶就是最大元素
        Key max=pq[1];
        //把这个最大元素换到最后并删除
        swap(1,size);
        pq[size]=nullptr;
        size--;
        //让pq[1]下沉到正确位置
        sink(1);
        return max;
    }
    
private:
    //交换数组的两个元素
    void swap(int i,int j){
        Key temp=pq[i];
        pq[i]=pq[j];
        pq[j]=temp;
    }
    
    //pq[i]是否比pq[j]小？
    bool less(int i,int j){
        return pq[i]<pq[j];
    }
    
    //上浮第x个元素，以维护最大堆性质
    void swim(int x){
        //如果浮到堆顶，就不能再上浮了
        while(x>1&&less(parent(x),x)){
            //如果第x个元素比上层大
            //将x换上去
            swap(parent(x),x);
            x=parent(x);
        }
    }
    //下沉第x个元素，以维护最大堆性质
    void sink(int x){
        //如果沉到堆底，就不能再沉下去了
        while(left(x)<=size){
            //先假设左边节点较大
            int max=left(x);
            //如果右边节点存在，比一下大小
            if(right(x)<=size&&less(max,right(x))){
                max=right(x);
            }else if(less(max,x)){
                break;
            }
            swap(x,max);
            x=max;
        }
    }
}
```



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



# 链表

> 双指针：1.快慢指针（两个指针同向而行，一快一慢）
>
> 2.左右指针（两个指针相向而行或者向背而行）
>
> 对于单链表来说，大部分技巧都属于快慢指针，如判断链表中是否有环，倒数第k个链表节点等问题，都是通过一个fast快指针和一个slow满指针配合完成任务。
>
> 虚拟头节点



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
| LC 19  |              remove-nth-node-from-end-of-list              |  done  | 20231019 |
| LC 23  |                    merge-k-sorted-lists                    |  done  | 20231019 |
| LC 141 |                     linked-list-cycle                      |  done  | 20231020 |
| LC 142 |                    linked-list-cycle-ii                    |  done  | 20231020 |
| LC 160 |              intersection-of-two-linked-lists              |  done  | 20231020 |
| LC 876 |                 middle-of-the-linked-list                  |  done  | 20231020 |
| LC 26  |            remove-duplicates-from-sorted-array.            |  done  | 20231021 |
| LC 83  |             remove-duplicates-from-sorted-list             |  done  | 20231021 |
| LC 27  |                       remove-element                       |  done  | 20231021 |
| LC 283 |                        move-zeroes                         |  done  | 20231021 |
|        |                                                            |        |          |

