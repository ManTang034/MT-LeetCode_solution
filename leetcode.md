# 分治

> 分治是一种算法设计思想，它将一个复杂的问题划分成若干个规模较小且结构相似的子问题，然后递归地解决这些子问题，最后将子问题的解合并起来得到原问题的解。
>
> 分治思想通常包含以下三个步骤：
>
> 1. 分解（Divide）：将原问题划分成若干个规模较小且结构相似的子问题，。这一步骤通常通过递归的方式实现。
> 2. 解决（Conquer）：递归地解决每个子问题。当子问题足够小并可以直接求解时，采用直接求解的方法。
> 3. 合并（Combine）：将子问题的解合并成原问题的解。这一步骤通常需要对子问题的解进行合适的处理和组合。
>
> 分治思想的优势在于能够将复杂的问题分解成简单的子问题，每个子问题的解决都是独立的，从而降低了问题的复杂性。同时，分治思想也利用了递归的特性，使得问题的表达更加简洁清晰。



# 单调栈（Monotonic Stack）

> - 特点：单调栈是一个维护元素单调性（递增或递减）的栈。栈顶元素是栈中的最值（最大值或最小值）。
> - 应用场景：
>   - 求元素的下一个更大元素或下一个更小元素
> - 实现方式：
>   - 使用栈作为底层实现
>   - 保证栈中的元素满足单调性，即栈顶到栈底的元素依次递增或递减。
>   - 在插入元素时，比较当前元素与栈顶元素的大小。如果当前元素比栈顶元素大（或小），则出栈，直到满足单调性。
>   - 在取最值操作时，直接返回栈顶元素即可。













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



## 最小堆

```c++
priority_queue<ListNode*,vector<ListNode*>,function<bool(ListNode*,ListNode*)>>pq([](ListNode*a,ListNode*b){return a->val>b->val});
/*
ListNode*表示容器中存储的元素类型
vector<ListNode*>表示底层容器使用vector来实现，存储的元素是指向ListNode对象的指针。
function<bool(ListNode*,ListNode*)>表示定义元素之间比较多自定义函数类型
由于比较函数实现的是a->val>b->val，表示节点值较大的节点优先级更高，因此它是一个最小堆。
*/
```

## 最大堆

```c++
priority_queue<ListNode*,vector<ListNode*>,function<bool(ListNode*,ListNode*)>>pq([](ListNode*a,ListNode*b){return a->val<b->val});
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
*/
```



> 二叉树解题的思维模式：
>
> 1. **是否可以通过遍历一遍二叉树得到答案**？如果可以，用一个`traverse`函数配合外部变量来实现，这叫***<u>遍历</u>***的思维模式。
> 2. 是否可以定义一个递归函数，通过子问题（子树）的答案推导出原问题的答案？如果可以，写出这个递归函数的定义，并充分利用这个函数的返回值，这叫**<u>*分解问题*</u>**的思维模式。
> 3. 无论使用哪一种思维模式，都要明白二叉树的每一个节点需要做什么，需要在什么时候（前中后序）做。

> **迭代和递归的区别：**
>
> 迭代是通过循环来实现的，即在程序中使用循环语句重复执行一段代码，直到满足某个条件退出循环。迭代通常使用for循环或while循环来实现，它的优点是可以节省内存空间，因为循环变量只需要一个就可以了。
>
> 递归是通过函数调用自身来实现的，即在函数内部调用自身，直到满足某个条件才停止递归。递归通常使用if语句来判断是否需要继续调用递归。递归的优点是代码简洁易懂，但是会消耗更多的内存空间，因为每次递归调用都会创建一个新的函数栈。
>
> 迭代通常适用于处理大量数据或者需要反复执行相同操作的场景，而递归通常适用于处理具有递归结构的问题，例如树形结构、图形结构等。





> **快速排序就是二叉树的前序遍历，归并排序是二叉树的后序遍历**

```c++
/*快速排序*/
void sort(vector<int>&nums,int lo,int hi){
    /*前序遍历位置*/
    //通过交换元素构建分界点p
    int p=partition(nums,lo,hi);
    
    sort(nums,lo,p-1);
    sort(nums,p+1,hi);
}

/*归并排序*/
void sort(vector<int>&nums,int lo,int hi){
    int mid=(lo+hi)/2;
    //对nums[lo,mid]进行排序
    sort(nums,lo,mid);
    //对nums[mid+1,hi]进行排序
    sort(nums,mid+1,hi);
    
    /*在后序位置进行归并操作*/
    //合并nums[lo,mid]和nums[mid+1,hi]
    merge(nums,lo,mid,hi);
}
```



### 1. 二叉树的遍历

### 前中后序遍历

按某条搜索路径访问树中的每个结点，使得每个结点均被访问一次，而且仅能访问一次。

> 前序遍历：先输出父节点，再遍历左子树，后遍历右子树
>
> （前序位置的代码在刚刚进入一个二叉树节点的时候执行）
>
> 中序遍历：先遍历左子树，再输出父节点，后遍历右子树
>
> （中序位置的代码在一个二叉树节点左子树都遍历完，即将开始遍历右子树的时候执行）
>
> 后序遍历：先遍历左子树，再遍历右子树，后输出父节点
>
> （后序位置的代码在将要离开一个二叉树节点的时候执行）

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

**前序遍历**

```c++
#include<iostream>
#include<vector>

using namespace std;

vector<int>res;

//前序遍历结果
vector<int>preorderTraverse(TreeNode*root){
    traverse(root);
    return res;
}

//二叉树遍历函数
void traverse(TreeNode*root){
    //base case
    if(root==nullptr){
        return;
    }
    //前序位置
    res.push_back(root->val);
    traverse(root->left);
    traverse(root->right);
}

/*分解问题思路*/
vector<int>preorderTraverse(TreeNode*root){
    vector<int>res;
    if(root==nullptr){
        return res;
    }
    
    res.push_back(root->val);
    vector<int>leftRes=preorderTraverse(root->left);
    res.insert(res.end(),leftRes.begin(),leftRes.end());
    vector<int>rightRes=preorderTraverse(root->right);
    res.insert(res.end(),rightRes.begin(),rightRes.end());
    return res;
}
```



> 前序位置的代码只能从函数参数中获取父节点传递来的数据，而后序位置的代码不仅可以获取参数数据，还可以获取到子树通过函数返回值传递回来的数据。
>
> 举例：给定一颗二叉树
>
> 1. 如果把根节点看作第1层，如何打印出每一个节点所在的层数？
> 2. 如何打印出每个节点的左右子树各有多少节点？
>
> 这两个问题的根本区别在于：一个节点在第几层，从根节点遍历过来的过程就能顺带记录，用递归函数的参数就能传递下去；而以一个节点为根的整个子树有多少个节点，需要遍历完子树之后才能数清楚，然后通过递归函数的返回值拿到答案。

```c++
/*如果把根节点看作第1层，如何打印出每一个节点所在的层数？*/
void traverse(TreeNode*root,int level){
    if(root==nullptr) return;
    //前序位置
    printf("节点%s在第%d层",root,level);
    traverse(root->left,level+1);
    traverse(root->right,level+1);
}
traverse(root,1);
```

```c++
/*如何打印出每个节点的左右子树各有多少节点？*/
//定义：输入一颗二叉树，返回这颗二叉树的节点总数
int count(TreeNode*root){
    if(root==nullptr){
        return 0;
    }
    int leftCount=count(root->left);
    int rightCount=count(root->right);
    //后序位置
    printf("节点%s的左子树有%d个节点，右子树有%d个节点",root->val,leftCount,rightCount);
    return leftCount+rightCount+1;
}
```



> 多叉树没有中序位置，因为二叉树的每个节点只会进行唯一一次左子树切换右子树，而多叉树节点可能有很多子节点，会多次切换子树去遍历，所以多叉树节点没有唯一的中序遍历位置。



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

1. 合并两个有序链表
2. 链表的分解
3. 合并k个有序链表
4. 寻找单链表的倒数第k个节点
5. 寻找单链表的中点
6. 判断单链表是否包含环并找出环起点
7. 判断两个单链表是否相交并找出交点



# 滑动窗口

**滑动窗口算法思路：**

```c++
int left=0,right=0;

while(left<right&&right<s.size()){
  //增大窗口
  window.add(s[right]);
  right++;
  
  while(window needs shrink){
    //缩小窗口
    window.remove(s[left]);
    left++;
  }
}
```

**滑动窗口算法框架**

```c++
/*滑动窗口算法框架*/
void slidingWindow(string s){
  //用合适的数据结构记录窗口中的数据
  unordered_map<char,int>window;
  
  int left=0,right=0;
  while(right<s.size()){
    //c是将移入窗口的字符
    char c=s[right];
    window.add(c);
    //增大窗口
    right++;
    //进行窗口内数据的一系列更新
    ...
      
    /* debug输出位置*/
    printf("window:[%d,%d]\n",left,right);
    
    //判断左侧窗口是否要收缩
    while(left<right&&window need shrink){
      //d是将移出窗口的字符
      char d=s[left];
      window.remove(d);
      //缩小窗口
      left++;
      //进行窗口内数据的一系列更新
      ...
    }
  }
}
```



# 二分搜索

**一、寻找一个数（基本的二分搜索）**

> 计算mid时需要防止溢出，代码中left+(right-left)/2和(left+right)/2的结果相同，但是有效防止了left和right太大，直接相加导致溢出的情况。

```c++
int binarySearch(vector<int>&nums,int target){
  int left=0,right=nums.size()-1;
  
  while(left<=right){
    int mid=left+(right-left)/2;
    if(nums[mid]==target){
      ...
    }else if(nums[mid<target]){
      left=mid+1;
    }else if(nums[mid]>target){
      right=mid-1;
    }
  }
  return ...;
}
```

> **1.为什么while循环的条件中是<=，而不是<?**
>
> 初始化的right=nums.length-1，即最后一个元素的索引，而不是nums.length。这二者可能出现在不同功能的二分查找中，区别是：前者相当于两端都闭区间[left,right]，后者相当于左闭右开区间[left,right)。因为索引大小nums.length是越界的，所以把right这一边视作开区间。
>
> `while(left <= right)` 的终止条件是 `left == right + 1`，写成区间的形式就是 `[right + 1, right]`，或者带个具体的数字进去 `[3, 2]`，可见**这时候区间为空**，因为没有数字既大于等于 3 又小于等于 2 的吧。所以这时候 while 循环终止是正确的，直接返回 -1 即可。
>
> `while(left < right)` 的终止条件是 `left == right`，写成区间的形式就是 `[right, right]`，或者带个具体的数字进去 `[2, 2]`，**这时候区间非空**，还有一个数 2，但此时 while 循环终止了。也就是说区间 `[2, 2]` 被漏掉了，索引 2 没有被搜索，如果这时候直接返回 -1 就是错误的。



**二、寻找左侧边界的二分搜索**

```c++
int left_bound(vector<int>&nums, int target){
    int left=0,right=nums.size()-1;
    
    while(left<=right){
        int mid=left+(right-left)/2;
        if(nums[mid]<target){
            left=mid+1;
        }else if(nums[mid]>target){
            right=mid-1;
        }else if(nums[mid]==target){
            right=mid-1;
        }
    }
    // 如果索引越界，说明数组中无目标元素，返回-1
    if(left<0 || left>=nums.size()){
        return -1;
    }
    // 判断nums[left]是不是target
    return nums[left]==target?left:-1;
}
```



**三、寻找右侧边界的二分查找**

```c++
int right_bound(vector<int>&nums, int target){
    int left=0,right=nums.size()-1;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(nums[mid]>target){
            right=mid-1;
        }else if(nums[mid]<target){
            left=mid+1;
        }else if(nums[mid]==target){
            left=mid+1;
        }
    }
    if(right<0 || right>=nums.size()){
        return -1;
    }
    return nums[right]==target?right:-1;
    /*
    if(left-1<0 || left-1>=nums.size()){
        return -1;
    }
    return nums[left-1]==target?(left-1):-1;
    */
}
```



# nSum问题

**two sum**

```c++
vector<vector<int>>twoSumTarget(vector<int>&nums, int target){
    // nums数组必须有序
    sort(nums.begin(),nums.end());
    int lo = 0, hi = nums.size()-1;
    while(lo<hi){
        int sum=nums[lo]+nums[hi];
        int left=nums[lo],right=nums[hi];
        if(sum<target){
            while(lo<hi && nums[lo]==left){
                lo++;
            }
        }else if(sum>target){
            while(lo<hi && nums[hi]==right){
                hi--;
            }
        }else{
            res.push_back({left,right});
            while(lo<hi&&nums[lo]==left){
                lo++;
            }
            while(lo<hi&&nums[hi]==right){
                hi--;
            }
        }
    }
    return res;
}
```



**triple sum**

```c++
/*从nums[start]开始，计算有序数组nums中所有和为target的二元组*/
vector<vector<int>>twoSumTarget(vector<int>&nums, int start, int target){
    // 左指针改为从start开始，其他不变
    int lo=start,hi=nums.size()-1;
    vector<vector<int>>res;
    while(lo<hi){
        int sum=nums[lo]+nums[hi];
        int left=nums[lo],right=nums[hi];
        if(sum<target){
            while(lo<hi && nums[lo]==left){
                lo++;
            }
        }else if(sum>target){
            while(lo<hi && nums[hi]==right){
                hi--;
            }
        }else{
            res.push_back({left,right});
            while(lo<hi&&nums[lo]==left){
                lo++;
            }
            while(lo<hi&&nums[hi]==right){
                hi--;
            }
        }
    }
    return res;
}

/*计算数组nums中所有和为target的三元组*/
vector<vector<int>>threeSumTarget(vector<int>&nums, int target){
    //数组排序
    sort(nums.begin(),nums.end());
    int n=nums.size();
    vector<vector<int>>res;
    //穷举threeSum的第一个数
    for(int i=0;i<n;i++){
        //对target-nums[i]计算twoSum
        vector<vector<int>> tuples=twoSumTarget(nums,i+1,target-nums[i]);
        //如果存在满足条件的二元组，再加上nums[i]就是结果三元组
        for(vector<int>&tuple:tuples){
            tuple.push_back(nums[i]);
            res.push_back(tuple);
        }
        //跳过第一个数字重复的情况，否则会出现重复结果
        while(i<n-1&&nums[i]==nums[i+1]){
            i++;
        }
    }
    return res;
}
```

**fourSum**

```c++
vector<vector<int>>fourSum(vector<int>&nums, int target){
    // 数组需要排序
    sort(nums.begin(),nums.end());
    int n=nums.size();
    vector<vector<int>>res;
    //穷举fourSum的第一个数
    for(int i=0;i<n;i++){
        //对target-nums[i]计算threeSum
        vector<vector<int>> triples=threeSumTarget(nums,i+1,target-nums[i]);
        //如果存在满足条件的三元组，再加上nums[i]就是结果四元组
        for(vector<int>&triple:triples){
            triple.push_back(nums[i]);
            res.push_back(triple);
        }
        //fourSum的第一个数不能重复
        while(i<n-1&&nums[i]==nums[i+1]) i++;
    }
}

vector<vector<int>>threeSumTarget(vector<int>&nums, int start, int target){
    int n=nums.size();
    vector<vector<int>>res;
    //i从start开始穷举，其他都不变
    for(int i=start;i<n;i++){
        ...
    }
    return res;
}
```



**模板总结**

```c++
//3Sum
vector<vector<int>>threeSum(vector<int>&nums){
    sort(nums.begin(),nums.end());
    return nSumTarget(nums,3,0,0);
}
//4Sum
vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        // n 为 4，从 nums[0] 开始计算和为 target 的四元组
        return nSumTarget(nums, 4, 0, target);
    }
    vector<vector<int>> nSumTarget(
        vector<int> &nums, int n, int start, int target)
    {
        int sz = nums.size();
        vector<vector<int>> res;
        // ⾄少是 2Sum，且数组⼤⼩不应该⼩于 n
        if (n < 2 || sz < n)
            return res;
        // 2Sum 是 base case
        if (n == 2)
        {
            // 双指针那⼀套操作
            int lo = start, hi = sz - 1;
            while (lo < hi)
            {
                int sum = nums[lo] + nums[hi];
                int left = nums[lo], right = nums[hi];
                if (sum < target)
                {
                    while (lo < hi && nums[lo] == left)
                        lo++;
                }
                else if (sum > target)
                {
                    while (lo < hi && nums[hi] == right)
                        hi--;
                }
                else
                {
                    res.push_back({left, right});
                    while (lo < hi && nums[lo] == left)
                        lo++;
                    while (lo < hi && nums[hi] == right)
                        hi--;
                }
            }
        }
        else
        {
            // n > 2 时，递归计算 (n-1)Sum 的结果
            for (int i = start; i < sz; i++)
            {
                vector<vector<int>>
                    sub = nSumTarget(nums, n - 1, i + 1, target - nums[i]);
                for (vector<int> &arr : sub)
                {
                    // (n-1)Sum 加上 nums[i] 就是 nSum
                    arr.push_back(nums[i]);
                    res.push_back(arr);
                }
                while (i < sz - 1 && nums[i] == nums[i + 1])
                    i++;
            }
        }
        return res;
    }
```





# 动态规划

> 动态规划的核心思想是穷举求最值，只有列出**<u>正确的状态转移方程</u>**，才能正确地穷举。而且，需要判断算法问题是否**<u>具备最优子结构</u>**，是否能够通过子问题的最值得到原问题的最值。另外，动态规划问题存在重叠子问题，如果暴力穷举的话效率会很低，所以需要使用**<u>备忘录</u>**或者**<u>DP table</u>**来优化穷举过程，避免不必要的计算。

> **动态规划三要素：<u>重叠子问题</u>、<u>最优子结构</u>、<u>状态转移方程</u>**
>
> 明确base case->明确状态->明确选择->定义dp数组/函数的含义。

```python
# 自顶向下递归的动态规划
def dp(状态1，状态2，...):
    for 选择 in 所有可能的选择:
        # 此时的状态已经因为做了选择而改变
        result=求最值(result,dp(状态1,状态2,...))
    return result

# 自底向上迭代的动态规划
# 初始化base case
dp[0][0][...] = base case
# 进行状态转移
for 状态1 in 状态1的所有取值:
    for 状态2 in 状态2的所有取值:
        for ...
        	dp[状态1][状态2][...] = 求最值(选择1,选择2,...)
```



## 斐波那契数列

```c++
/*暴力递归*/
int fib(int n){
    if(n==1||n==2) return n;
    return fib(n-1)+fib(n-2);
}

/*带备忘录的递归解法*/
int fib(int n){
    //备忘录全初始化为0
    int *memo=new int[n+1]();
    return dp(memo,n);
}

//带着备忘录进行递归
int dp(int memo[],int n){
    //base case
    if(n==1||n==0){
        return n;
    }
    if(memo[n]!=0){
        return memo[n];
    }
    memo[n]=dp(memo,n-1)+dp(memo,n-2);
    return memo[n];
}

/*dp数组的迭代(递推)解法*/
int fib(int n){
    if(n==0) return 0;
    int *dp=new int[n+1];
    // base case
    dp[0]=0;dp[1]=1;
    //状态转移
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

/*当前状态仅和n-1，n-2两个状态有关*/
int fib(int n){
    if(n==0||n==1) return n;
    //分别代表dp[i-1]和dp[i-2]
    int dp_i_1=1,dp_i_2=0;
    for(int i=2;i<=n;i++){
        int dp_i=dp_i_1+dp_i_2;
        // 滚动更新
        dp_i_2=dp_i_1;
        dp_i_1=dp_i;
    }
    return dp_i_1;
}
```



## 凑零钱问题

1.暴力搜索法

```c++
int coinChange(vector<int>&coins,int amount){
    return dp(coins,amount);
}

int dp(vector<int>&coins,int amount){
    //base case
    if(amount==0) return 0;
    if(amount<0) return -1;
    
    int res=INT_MAX;
    for(int coin:coins){
        int subProblem=dp(coins,amount-coin);
        if(subProblem==-1) continue;
        res=min(res,subProblem+1);
    }
    
    return res==INTMAX?-1:res;
}
```

2.带备忘录的递归

```c++
class Solution {
    private:
        vector<int> memo;
        
        /**
         * memo 数组记录了 amount 对应的最优解，-666 代表还未被计算。
         * 因此，在计算 amount 对应的最优解时需要先查找 memo。
         */
        int dp(vector<int>& coins, int amount){
            if(amount == 0) return 0; // 如果 amount = 0，那么硬币数量为 0
            if(amount < 0) return -1; // 如果 amount < 0，那么无解
            if(memo[amount] != -666) return memo[amount]; // 查备忘录，如果有最优解则直接返回
            
            int res = INT_MAX;
            /**
             * 在硬币数组 coins 中依次选取每个硬币。
             * 对于当前选择的硬币，计算是包含该硬币所需的子问题的最优解 subProblem。
             * 如果子问题无解，则直接跳过该硬币。
             * 在所有子问题中，选取最优解，并加上该硬币的数量。
             * 最终的结果 res 即为 amount 对应的最优解，该结果存入 memo 中。
             */
            for(int coin : coins){
                int subProblem = dp(coins, amount - coin);
                if(subProblem == -1) continue;
                res = min(res, subProblem + 1);
            }
            
            memo[amount] = res == INT_MAX ? -1 : res;
            return memo[amount];
        }
        
    public:
        int coinChange(vector<int>& coins, int amount) {
            /**
             * 初始化备忘录 memo，memo 数组的长度为 amount+1。
             * memo 数组记录了 amount 对应的最优解，-666 代表还未被计算。
             * 因此，在计算 amount 对应的最优解时需要先查找 memo，再根据结果进行计算。
             */
            memo = vector<int>(amount + 1, -666);
            return dp(coins, amount);
        }
};
```

3.dp数组的迭代解法

```c++
//dp数组的定义：当目标金额为i时，至少需要dp[i]枚硬币凑出
int coinChange(vector<int>&coins,int amount){
    vector<int>dp(amount+1,amount+1);
    dp[0]=0;
    
    for(int i=0;i<dp.size();i++){
        for(int coin:coins){
            if(i-coin<0){
                continue;
            }
            dp[i]=min(dp[i],dp[i-coin]+1);
        }
    }
    return (dp[amount]==amount+1)?-1:dp[amount];
}
```



## 最优子结构原理和dp数组遍历方向

> 1. 到底什么才叫最优子结构，和动态规划什么关系。
> 2. 如何判断一个问题是动态规划问题，即如何看出是否存在重叠子问题。
> 3. 为什么经常看到将dp数组的大小设置为n+1而不是n。
> 4. 为什么动态规划遍历dp数组的方式五花八门，有的正着遍历，有的倒着遍历，有的斜着遍历。



## 子序列类型问题

### 经典动态规划：编辑距离

1.暴力解法

```c++
if s1[i]==s2[j]:
	啥都别做(skip);
	i,j同时向前移动
else:
	三选一:
		插入(insert);
		删除(delete);
		替换(replace);
```

```c++
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.length();
        int n=word2.length();
        //i,j初始化指向最后一个索引
        return dp(word1,m-1,word2,n-1);
    }
    //定义：返回s1[0..i]和s2[0..j]最小编辑距离
    int dp(string s1,int i,string s2,int j){
        //base case
        if(i==-1) return j+1;
        if(j==-1) return i+1;

        if(s1[i]==s2[j]){
            return dp(s1,i-1,s2,j-1);
        }
        return Min(
            dp(s1,i,s2,j-1)+1, //插入
            dp(s1,i-1,s2,j)+1, //删除
            dp(s1,i-1,s2,j-1)+1 //替换
        );
    }
    int Min(int a,int b,int c){
        return min(min(a,b),c);
    }
};
```

> 暴力解法存在重叠子问题，如下所示，对于子问题`dp(i-1,j-1)`，如何通过原问题`dp(i,j)`得到呢？有不止一条路径，比如`dp(i,j)->#1`和`dp(i,j)->#2->#3`。一旦发现一条重复路径，就说明存在巨量重复路径，也就是重叠子问题。

```c++
int dp(i,j){
    dp(i-1,j-1)+1; // #1
    dp(i,j-1); // #2
    dp(i-1,j); // #3
}
```

2.动态规划优化

**备忘录优化**

```c++
class Solution {
private:
    //备忘录
    vector<vector<int>>memo;
    int dp(string s1,int i,string s2,int j){
        //base case
        if(i==-1) return j+1;
        if(j==-1) return i+1;
        //查备忘录，避免重复子问题
        if(memo[i][j]!=-1){
            return memo[i][j];
        }
        //状态转移，结果存入备忘录
        if(s1[i]==s2[j]){
            memo[i][j]=dp(s1,i-1,s2,j-1);
        }else{
            memo[i][j]=Min(
                dp(s1,i-1,s2,j)+1,
                dp(s1,i,s2,j-1)+1,
                dp(s1,i-1,s2,j-1)+1
            );
        }
        return memo[i][j];
    }
public:
    int minDistance(string word1, string word2) {
        int m=word1.length(),n=word2.length();
        //初始化备忘录
        memo=vector<vector<int>>(m,vector<int>(n,-1));
        return dp(word1,m-1,word2,n-1);
    }
    
    int Min(int a,int b,int c){
        return min(min(a,b),c);
    }
};
```

3.dp数组

```c++
class Solution {
public:
    int minDistance(string s1, string s2) {
        int m = s1.length(), n = s2.length();
        // 定义：s1[0..i] 和 s2[0..j] 的最小编辑距离是 dp[i+1][j+1]
        int dp[m + 1][n + 1];
        dp[0][0]=0;
        // base case 
        for (int i = 1; i <= m; i++)
            dp[i][0] = i;
        for (int j = 1; j <= n; j++)
            dp[0][j] = j;
        // 自底向上求解
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = Min(
                        dp[i - 1][j] + 1,

                        dp[i][j - 1] + 1,

                        dp[i - 1][j - 1] + 1

                    );
                }
            }
        }
    // 储存着整个 s1 和 s2 的最小编辑距离
    return dp[m][n];
}
    
    int Min(int a,int b,int c){
        return min(min(a,b),c);
    }
};
```



### 动态规划设计：最长递增子序列

```c++
int lengthOfLIS(vector<int>&nums){
  	//定义：dp[i]表示以nums[i]这个数结尾的最长递增子序列的长度
  	vector<int>dp(nums.size(),1);
  	for(int i=0;i<nums.size();i++){
    	for(int j=0;j<i;j++){
      	if(nums[i]>nums[j]){
        	dp[i]=max(dp[i],dp[j]+1);
      	}
    	}
  	}
  
  	int res=0;
  	for(int i=0;i<dp.size();i++){
    	res=max(res,dp[i]);
  	}
  	return res;
}
```



### 动态规划设计：最大子数组

```c++
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        //定义:dp[i]记录以nums[i]为结尾的最大子数组和
        vector<int>dp(n);
        //base case
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            dp[i]=max(nums[i],nums[i]+dp[i-1]);
        }
        //得到nums的最大子数组
        return *max_element(dp.begin(),dp.end());
    }
};
```



### 经典动态规划：最长公共子序列

> 对于两个字符串求子序列的问题，都是用两个指针`i`和`j`分别在两个字符串上移动，大概率是动态规划思路。

```c++
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.length(),n=text2.length();
        //定义:dp[0..i-1]和dp[0..j-1]的lcs长度为dp[i][j]
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};
```

> **字符串的删除操作**

```c++
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.length(),n=word2.length();
        int lcs=longestCommonSubsequence(word1,word2);
        return m-lcs+n-lcs;
    }

    int longestCommonSubsequence(string s1,string s2){
        int m=s1.length(),n=s2.length();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};
```

> **最小ASCII删除和**

```c++
class Solution {
public:
    vector<vector<int>>memo;
    int minimumDeleteSum(string s1, string s2) {
        int m=s1.length(),n=s2.length();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));

        for(int i=1;i<=m;i++){
            dp[i][0]=dp[i-1][0]+s1[i-1];
        }
        for(int j=1;j<=n;j++){
            dp[0][j]=dp[0][j-1]+s2[j-1];
        }

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }else{
                    dp[i][j]=min(
                        dp[i-1][j]+s1[i-1],
                        dp[i][j-1]+s2[j-1]
                    );
                }
            }
        }
        return dp[m][n];
    }
};
```



### 经典动态规划：0-1背包问题

> 给你一个可装载重量为 `W` 的背包和 `N` 个物品，每个物品有重量和价值两个属性。其中第 `i` 个物品的重量为 `wt[i]`，价值为 `val[i]`，现在让你用这个背包装物品，最多能装的价值是多少？

**第一步：明确状态和选择**

> **<u>状态</u>**有两个，就是背包的容量和可选择的物品。
>
> **<u>选择</u>**就是装进背包或者不装进背包。

```c++
for 状态1 in 状态1的所有取值:
	for 状态2 in 状态2的所有取值:
		for ...
            dp[状态1][状态2][...] = 择优(选择1,选择2,...)
```

**第二步：明确dp数组的定义**

> `dp[i][w]`的定义：对于前`i`个物品，当前背包的容量为`w`，这种情况下可以装的最大价值。
>
> 根据这个定义，我们想求的最终答案就是`dp[N][W]`。base case就是`dp[0][..]=dp[..][0]=0`，因为没有物品或者背包没有空间的时候，能装的最大价值就是0.

```c++
int dp[N+1][W+1]
dp[0][..] = 0
dp[..][0] = 0
    
for i in [1..N]:
	for w in [1..W]:
		dp[i][w]=max(
        	把物品i装进背包
            不把物品i装进背包
        )
return dp[N][W]
```

**第三步：根据选择，思考状态转移的逻辑**

> 如果没有把第`i`个物品装入背包，则最大价值`dp[i][w]`等于`dp[i-1][w]`。
>
> 如果把第`i`个物品装入了背包，那么`dp[i][w]=dp[i-1][w-wt[i-1]]+val[i-1]`
>
> 由于`i`是从1开始，所以对`val`和`wt`的取值是`i-1`

```c++
for i in [1..N]:
	for w in [1..W]:
		dp[i][w]=max(
        	dp[i-1][w],
            dp[i-1][w-wt[i-1]]+val[i-1];
        )
return dp[N][W]
```

**第四步：把伪代码翻译成代码，处理一些边界情况**

```c++
int knapsack(int W, int N, vector<int>& wt, vector<int>& val) {
    // vector 全填入 0，base case 已初始化
    vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= N; i++) {
        for (int w = 1; w <= W; w++) {
            if (w - wt[i-1] < 0) {
                // 当前背包容量装不下，只能选择不装入背包
                dp[i][w] = dp[i - 1][w];
            } else {
                // 装入或者不装入背包，择优
                dp[i][w] = max(dp[i - 1][w - wt[i-1]] + val[i-1], 
                               dp[i - 1][w]);
            }
        }
    }

    return dp[N][W];
}
```

### 经典动态规划：0-1背包问题的变体

416.分割等和子集

```c++
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int num:nums) sum+=num;
        //和为奇数时，不可能划分成两个和相等的集合
        if(sum%2!=0) return false;
        int n=nums.size();
        sum=sum/2;
        vector<vector<bool>>dp(n+1,vector<bool>(sum+1,false));
        //base case
        for(int i=0;i<=n;i++){
            dp[i][0]=true;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(j-nums[i-1]<0){
                    //背包容量不足，不能装入第i个物品
                    dp[i][j]=dp[i-1][j];
                }else{
                    //装入或不装入背包
                    dp[i][j]=dp[i-1][j] | dp[i-1][j-nums[i-1]];
                }
            }
        }
        return dp[n][sum];
    }
};
```

> **进行状态压缩**
>
> 注意到`dp[i][j]`都是通过上一行`dp[i-1][..]`转移过来的，之前的数据都不会再使用了。
>
> 所以可以进行状态压缩，将二维`dp`数组压缩为一维，节约空间复杂度

```c++
bool canPartition(vector<int>& nums) {
    int sum = 0, n = nums.size();
    for (int num : nums) sum += num;
    if (sum % 2 != 0) return false;
    sum = sum / 2;
    vector<bool> dp(sum + 1, false);
    // base case
    dp[0] = true;

    for (int i = 0; i < n; i++) 
        for (int j = sum; j >= 0; j--) 
            if (j - nums[i] >= 0) 
                dp[j] = dp[j] || dp[j - nums[i]];

    return dp[sum];
}
```

> 主要注意的是`j`应该从后往前反向遍历，因为每个物品（或者说数字）只能用一次，以免之前的结果影响其他的结果。

### 经典动态规划：完全背包问题

**第一步：明确状态和选择**

> 状态有两个，就是背包的容量和可选择的物品，选择就是装进背包或不装进背包。

```c++
for 状态1 in 状态1的所有取值:
	for 状态2 in 状态2的所有取值:
		for ...
            dp[状态1][状态2][...]=计算(选择1,选择2,...)
```

**第二步：明确dp数组的定义**

> 若只使用前`i`个物品，当背包容量为`j`时，有`dp[i][j]`种方法可以装满背包。即只使用`coins`中的前`i`个硬币的面值，若想凑出金额`j`，有`dp[i][j]`种凑法。
>
> base case为`dp[0][..]=0,dp[..][0]=1`。因为如果不使用任何硬币面值，就无法凑出任何金额；如果凑出的目标金额为0，那么“无为而治”就是唯一一种凑法。
>
> 最终想得到的答案是`dp[N][amount]`，其中`N`为`coins`数组的大小。

```c++
int dp[N+1][amount+1]
dp[0][..]=0
dp[..][0]=1
    
for i in [1..N]:
	for j in [1..amount]:
		把物品i装进背包,
		不把物品i装进背包
return dp[N][amount]
```

**第三步：根据选择，思考状态转移的逻辑**

> 如果不把第`i`个物品装入背包，那么凑出面额`j`的方法`dp[i][j]`应该等于`dp[i-1][j]`，继承之前的结果。
>
> 如果把第`i`个物品装入背包，那么`dp[i][j]`应该等于`dp[i][j-coins[i-1]]`

```c++
for(int i=1;i<=n;i++){
    for(int j=1;j<=amount;j++){
        if(j-coins[i-1]>=0){
            dp[i][j]=dp[i-1][j]+dp[i][j-coins[i-1]];
        }
    }
}
```

```c++
int change(int amount, vector<int>&coins){
    int n=coins.size();
    vector<vector<int>>dp(n+1,vector<int>(amount+1));
    //base case
    for(int i=0;i<=n;i++){
        dp[i][0]=1;
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=amount;j++){
            if(j-coins[i-1]>=0){
                dp[i][j]=dp[i-1][j]+dp[i][j-coins[i-1]];
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][amount];
}
```

> 状态压缩

```c++
int change(int amount, vector<int>&coins){
    int n=coins.size();
    vector<int>dp(amount+1);
    dp[0]=1;
    for(int i=0;i<n;i++){
        for(int j=1;j<=amount;j++){
            if(j-coins[i]>=0){
                dp[j]=dp[j]+dp[j-coins[i]];
            }
        }
    }
    return dp[amount];
}
```



## 用动态规划玩游戏

### 团灭LeetCode股票买卖问题

**一、穷举框架**

> 每天都有三种选择：买入、卖出、无操作，使用`buy`,`sell`,`rest`表示这三种选择。
>
> 但不是每天都可以任意选择三种选择的，因为`sell`必须在`buy`之后，`buy`必须在`sell`之后。`rest`操作还分为两种状态，一种是`buy`之后的`rest`(持有了股票)，一种是`sell`之后的`rest`(没有持有股票)。且交易次数`k`的限制，就是说`buy`只能在`k>0`的前提下操作。

> 这个问题的状态有三个，第一个是天数，第二个是允许交易的最大次数，第三个是当前的持有状态（1表示持有，0表示没有持有）。使用三维数组就可以装下这几种状态的全部组合：

```c++
dp[i][k][0 or 1]
0 <= i <= n-1, 1 <= k <=K
n为天数，K为交易数的上限，0和1代表是否持有股票。
此问题共n*K*2种状态，全部穷举就能搞定。
    
for 0<=i<n-1:
	for 1<=k<=K:
		for s in {0,1}:
			dp[i][k][s] = max(buy,sell,rest)
```

> 想求的最终答案是`dp[n-1][K][0]`，即最后一天，最多允许`K`次交易，最多获得多少利润。

二、状态转移框架

```c++
dp[i][k][0]=max(dp[i-1][k][0], dp[i-1][k][1]+prices[i])
```

> 解释：我今天没有持有股票，有两种可能：
>
> 1. 昨天就没有持有，且截至昨天最大交易次数限制为`k`；然后今天选择`rest`，所以今天仍然没有持有，最大交易次数限制依然为`k`。
> 2. 昨天持有股票，且截至昨天最大交易次数限制为`k`；但今天选择`sell`，所以今天没有持有股票，最大交易次数限制依然为`k`。

```c++
dp[i][k][1]=max(dp[i-1][k][1], dp[i-1][k-1][0]-prices[i])
```

> 1. 昨天就持有着股票，且截至昨天最大交易次数限制为`k`；然后今天选择`rest`，所以我今天还持有着股票，最大交易次数限制依然为`k`
>
> 2. 昨天本没有持有，且截至昨天最大交易次数限制为`k-1`；但今天选择`buy`，所以今天持有股票，最大交易次数限制为`k`

定义base case

```c++
dp[-1][...][0] = 0
解释：因为 i 是从 0 开始的，所以 i = -1 意味着还没有开始，这时候的利润当然是 0。

dp[-1][...][1] = -infinity
解释：还没开始的时候，是不可能持有股票的。
因为我们的算法要求一个最大值，所以初始值设为一个最小值，方便取最大值。

dp[...][0][0] = 0
解释：因为 k 是从 1 开始的，所以 k = 0 意味着根本不允许交易，这时候利润当然是 0。

dp[...][0][1] = -infinity
解释：不允许交易的情况下，是不可能持有股票的。
因为我们的算法要求一个最大值，所以初始值设为一个最小值，方便取最大值。
```

```c++
base case：
dp[-1][...][0] = dp[...][0][0] = 0
dp[-1][...][1] = dp[...][0][1] = -infinity

状态转移方程：
dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])
dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i])
```



121.买卖股票的最佳时机

k=1

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2));
        for(int i=0;i<n;i++){
            if(i-1==-1){
                dp[i][0]=0;
                dp[i][1]=-prices[i];
                continue;
            }
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]);
            dp[i][1]=max(dp[i-1][1],-prices[i]);
        }
        return dp[n-1][0];
    }
};
```

122.买卖股票的最佳时机II

k=+infinity

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2));
        for(int i=0;i<n;i++){
            if(i-1==-1){
                dp[i][0]=0;
                dp[i][1]=-prices[i];
                continue;
            }
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]);
            dp[i][1]=max(dp[i-1][1],dp[i-1][0]-prices[i]);
        }
        return dp[n-1][0];
    }
};
```

123.买卖股票的最佳时机III

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_k=2,n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(max_k+1,vector<int>(2)));
        for(int i=0;i<n;i++){
            for(int k=max_k;k>=1;k--){
                if(i-1==-1){
                    //base case
                    dp[i][k][0]=0;
                    dp[i][k][1]=-prices[i];
                    continue;
                }
                dp[i][k][0]=max(dp[i-1][k][0],dp[i-1][k][1]+prices[i]);
                dp[i][k][1]=max(dp[i-1][k][1],dp[i-1][k-1][0]-prices[i]);
            }
        }
        return dp[n-1][max_k][0];
    }
};
```

188.买卖股票的最佳时机IV

```c++
class Solution {
public:
    int maxProfit(int max_k, vector<int>& prices) {
        int n=prices.size();
        if(n<=0) return 0;
        if(max_k>n/2){
            maxProfit_inf(prices);
        }
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(max_k+1,vector<int>(2)));
        for(int i=0;i<n;i++){
            dp[i][0][1]=INT_MIN;
            dp[i][0][0]=0;
        }
        for(int i=0;i<n;i++){
            for(int k=max_k;k>=1;k--){
                if(i-1==-1){
                    //base case
                    dp[i][k][0]=0;
                    dp[i][k][1]=-prices[i];
                    continue;
                }
                dp[i][k][0]=max(dp[i-1][k][0],dp[i-1][k][1]+prices[i]);
                dp[i][k][1]=max(dp[i-1][k][1],dp[i-1][k-1][0]-prices[i]);
            }
        }
        return dp[n-1][max_k][0];
    }

    int maxProfit_inf(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2));
        for(int i=0;i<n;i++){
            if(i-1==-1){
                dp[i][0]=0;
                dp[i][1]=-prices[i];
                continue;
            }
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]);
            dp[i][1]=max(dp[i-1][1],dp[i-1][0]-prices[i]);
        }
        return dp[n-1][0];
    }
};
```





309.买卖股票的最佳时机含冷冻期

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2));
        for(int i=0;i<n;i++){
            if(i-1==-1){
                dp[i][0]=0;
                dp[i][1]=-prices[i];
                continue;
            }
            if(i-2==-1){
                dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]);
                dp[i][1]=max(dp[i-1][1],-prices[i]);
                continue;
            }
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]);
            dp[i][1]=max(dp[i-1][1],dp[i-2][0]-prices[i]);
        }
        return dp[n-1][0];
    }
};
```



714.买卖股票的最佳时机含手续费

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2));
        for(int i=0;i<n;i++){
            if(i-1==-1){
                //base case
                dp[i][0]=0;
                dp[i][1]=-prices[i]-fee;
                continue;
            }
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]);
            dp[i][1]=max(dp[i-1][1],dp[i-1][0]-prices[i]-fee);
        }
        return dp[n-1][0];
    }
};
```



### 团灭Leetcode打家劫舍问题

> 面前房子的索引就是状态，抢和不抢就是选择。

**198.打家劫舍**

如果两间相邻的房屋在同一晚上被盗走闯入，系统会自动报警。

空间复杂度：O(n)

```c++
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        //dp[i]表示从第i间房子开始抢劫，最多能抢劫到的钱
        //base case:dp[n]=0即走过最后一间房后就没有可以抢劫的了
        vector<int>dp(n+2);
        for(int i=n-1;i>=0;i--){
            dp[i]=max(dp[i+1],nums[i]+dp[i+2]);
        }
        return dp[0];
    }
};
```

空间复杂度：O(1)

```c++
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        //记录dp[i+1]和dp[i+2]
        int dp_i_1=0,dp_i_2=0;
        int dp_i=0;
        for(int i=n-1;i>=0;i--){
            dp_i=max(dp_i_1,dp_i_2+nums[i]);
            dp_i_2=dp_i_1;
            dp_i_1=dp_i;
        }
        return dp_i;
    }
};
```

213.打家劫舍II

强盗依然不能抢劫相邻的房子，但这些房子围成了一个圈。

> 只有三种不同情况：要么都不被抢；要么第一间房子被抢最后一间不抢；要么最后一间房子被抢第一间不抢。情况二和情况三肯定比情况一多，所以只需比较情况二和情况三。

```c++
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        //第一间被抢，最后一间不抢
        //第一间不抢，最后一间抢
        return max(robRange(nums,0,n-2),robRange(nums,1,n-1));
    }

    int robRange(vector<int>&nums,int start,int end){
        int n=nums.size();
        int dp_i_1=0,dp_i_2=0;
        int dp_i=0;
        for(int i=end;i>=start;i--){
            dp_i=max(dp_i_1,dp_i_2+nums[i]);
            dp_i_2=dp_i_1;
            dp_i_1=dp_i;
        }
        return dp_i;
    }
};
```

337.打家劫舍III

> 在`rob`函数中，首先调用`dp`函数来计算根节点为起点的最大收益，然后返回其中较大的值。在`dp`函数中，我们使用递归的方式处理每个节点以及其左右子树的情况。
>
> 对于每个节点，我们用一个包含两个元素的数组来表示两种情况下的最大收益。数组中的第一个元素表示不抢劫该节点时的最大收益，第二个元素表示抢劫该节点时的最大收益、当递归到叶子节点时，返回{0,0}表示不抢劫时和抢劫时的收益都是0.
>
> 在递归的过程中，对于当前节点，我们分别计算了抢劫该节点和不抢劫该节点两种情况下的最大收益。具体来说，如果选择抢劫该节点，那么左右子树的节点就不能抢劫，因此我们累加当前节点的值和左右子树不抢劫时的最大收益；如果选择不抢劫该节点，那么我们可以灵活选择左右子树抢或者不抢，取收益最大的情况作为当前节点不抢劫时的最大收益。
>
> 最终，我们返回这两种情况下的最大收益数组，然后在`rob`函数中取其中较大的值作为最终结果返回。

```c++
class Solution {
public:
    int rob(TreeNode* root) {
        vector<int>res=dp(root);
        return max(res[0],res[1]);
    }

    vector<int>dp(TreeNode*root){
        if(root==nullptr){
            return {0,0};
        }
        vector<int>left=dp(root->left);
        vector<int>right=dp(root->right);
        //抢，下家不能抢
        int rob = root->val+left[0]+right[0];
        //不抢，下家可抢可不抢，取决于收益大小
        int not_rob=max(left[0],left[1])+max(right[0],right[1]);
        return {not_rob,rob};
    }
};
```

























# 时间线1

| Number  |                          Question                          | Status |   Date   |
| :-----: | :--------------------------------------------------------: | :----: | :------: |
| LC 144  |               binary-tree-preorder-traversal               |  done  | 20231017 |
|  LC 94  |               binary-tree-inorder-traversal                |  done  | 20231017 |
| LC 145  |              binary-tree-postorder-traversal               |  done  | 20231017 |
| LC 105  | construct-binary-tree-from-preorder-and-inorder-traversal  |  done  | 20231017 |
| LC 106  | construct-binary-tree-from-inorder-and-postorder-traversal |  done  | 20231017 |
|  LC 21  |                   merge-two-sorted-lists                   |  done  | 20231018 |
|  LC 86  |                       partition-list                       |  done  | 20231018 |
| LC 230  |               kth-smallest-element-in-a-bst                |  done  | 20231018 |
|  LC 19  |              remove-nth-node-from-end-of-list              |  done  | 20231019 |
|  LC 23  |                    merge-k-sorted-lists                    |  done  | 20231019 |
| LC 141  |                     linked-list-cycle                      |  done  | 20231020 |
| LC 142  |                    linked-list-cycle-ii                    |  done  | 20231020 |
| LC 160  |              intersection-of-two-linked-lists              |  done  | 20231020 |
| LC 876  |                 middle-of-the-linked-list                  |  done  | 20231020 |
|  LC 26  |            remove-duplicates-from-sorted-array.            |  done  | 20231021 |
|  LC 83  |             remove-duplicates-from-sorted-list             |  done  | 20231021 |
|  LC 27  |                       remove-element                       |  done  | 20231021 |
| LC 283  |                        move-zeroes                         |  done  | 20231021 |
|  LC 76  |                  minimum-window-substring                  |  done  | 20231021 |
| LC 567  |                   permutation-in-string                    |  done  | 20231021 |
| LC 438  |               find-all-anagrams-in-a-string                |  done  | 20231021 |
|  LC 3   |       longest-substring-without-repeating-characters       |  done  | 20231021 |
| LC 704  |                       binary-search                        |  done  | 20231022 |
|  LC 34  |  find-first-and-last-position-of-element-in-sorted-array   |  done  | 20231023 |
| LC 167  |              two-sum-ii-input-array-is-sorted              |  done  | 20231024 |
|  LC 15  |                           3-sum                            |  done  | 20231024 |
|  LC 18  |                           4-sum                            |  done  | 20231024 |
| LC 344  |                       reverse-string                       |  done  | 20231024 |
|  LC 5   |               longest-palindromic-substring                |  done  | 20231024 |
| LC 104  |                maximum-depth-of-binary-tree                |  done  | 20231025 |
| LC 543  |                  diameter-of-binary-tree                   |  done  | 20231027 |
| LC 509  |                      fibonacci-number                      |  done  | 20231031 |
| LC 322  |                        coin-change                         |  done  | 20231031 |
| LC 300  |               longest-increasing-subsequence               |  done  | 20231101 |
| LC 322  |                        coin-change                         |  done  | 20231101 |
| LC 509  |                      fibonacci-number                      |  done  | 20231101 |
| LC 543  |                  diameter-of-binary-tree                   |  done  | 20231101 |
|  LC 72  |                       edit-distance                        |  done  | 20231103 |
|  LC 53  |                      maximum-subarray                      |  done  | 20231106 |
| LC 1143 |                 longest-common-subsequence                 |  done  | 20231106 |
| LC 583  |              delete-operation-for-two-strings              |  done  | 20231106 |
| LC 712  |          minimum-ascii-delete-sum-for-two-strings          |  done  | 20231106 |
| LC 416  |                 partition-equal-subset-sum                 |  done  | 20231108 |
| LC 518  |                       coin-change-ii                       |  done  | 20231108 |
| LC 121  |              best-time-to-buy-and-sell-stock               |  done  | 20231109 |
| LC 122  |             best-time-to-buy-and-sell-stock-ii             |  done  | 20231109 |
| LC 309  |       best-time-to-buy-and-sell-stock-with-cooldown        |  done  | 20231109 |
| LC 714  |    best-time-to-buy-and-sell-stock-with-transaction-fee    |  done  | 20231109 |
| LC 123  |            best-time-to-buy-and-sell-stock-iii             |  done  | 20231109 |
| LC 188  |             best-time-to-buy-and-sell-stock-iv             |  done  | 20231109 |
|         |                                                            |        |          |
|         |                                                            |        |          |
|         |                                                            |        |          |
|         |                                                            |        |          |
|         |                                                            |        |          |
|         |                                                            |        |          |
|         |                                                            |        |          |
|         |                                                            |        |          |
|         |                                                            |        |          |
|         |                                                            |        |          |
|         |                                                            |        |          |
|         |                                                            |        |          |
|         |                                                            |        |          |
|         |                                                            |        |          |
|         |                                                            |        |          |
|         |                                                            |        |          |
|         |                                                            |        |          |
|         |                                                            |        |          |
|         |                                                            |        |          |

**剑指offer**

| Number  | Question | Status |   Date   |
| :-----: | :------: | :----: | :------: |
| LCR 007 | 三数之和 |  done  | 20231024 |
|         |          |        |          |
|         |          |        |          |
|         |          |        |          |
|         |          |        |          |





# 时间线2

## 阶段一：数据结构

|   数据结构   | 类型 |       时间        |
| :----------: | :--: | :---------------: |
|     链表     |      | 20231018-20231024 |
|     数组     |      | 20231021-20231024 |
|    二叉树    |      |     20231025-     |
|      图      |      |                   |
| 设计数据结构 |      |                   |

### 链表-review

| Number                                                       |      |      |      |      |      |
| :----------------------------------------------------------- | :--: | :--: | :--: | :--: | :--: |
| [141. 环形链表](https://leetcode.cn/problems/linked-list-cycle/) |      |      |      |      |      |
| [142. 环形链表 II](https://leetcode.cn/problems/linked-list-cycle-ii/) |      |      |      |      |      |
| [160. 相交链表](https://leetcode.cn/problems/intersection-of-two-linked-lists/) |      |      |      |      |      |
| [19. 删除链表的倒数第 N 个结点](https://leetcode.cn/problems/remove-nth-node-from-end-of-list/) |      |      |      |      |      |
| [21. 合并两个有序链表](https://leetcode.cn/problems/merge-two-sorted-lists/) |      |      |      |      |      |
| [23. 合并K个升序链表](https://leetcode.cn/problems/merge-k-sorted-lists/) |      |      |      |      |      |
| [86. 分隔链表](https://leetcode.cn/problems/partition-list/) |      |      |      |      |      |
| [876. 链表的中间结点](https://leetcode.cn/problems/middle-of-the-linked-list/) |      |      |      |      |      |
| [剑指 Offer 22. 链表中倒数第k个节点](https://leetcode.cn/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/) |      |      |      |      |      |
| [剑指 Offer 25. 合并两个排序的链表](https://leetcode.cn/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof/) |      |      |      |      |      |
| [剑指 Offer 52. 两个链表的第一个公共节点](https://leetcode.cn/problems/liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof/) |      |      |      |      |      |
| [剑指 Offer II 021. 删除链表的倒数第 n 个结点](https://leetcode.cn/problems/SLwz0R/) |      |      |      |      |      |
| [剑指 Offer II 022. 链表中环的入口节点](https://leetcode.cn/problems/c32eOV/) |      |      |      |      |      |
| [剑指 Offer II 023. 两个链表的第一个重合节点](https://leetcode.cn/problems/3u1WK4/) |      |      |      |      |      |
| [剑指 Offer II 078. 合并排序链表](https://leetcode.cn/problems/vvXgSW/) |      |      |      |      |      |



### 滑动窗口-review

| Number                                                       |      |      |      |      |      |
| ------------------------------------------------------------ | ---- | ---- | ---- | ---- | ---- |
| [3. 无重复字符的最长子串](https://leetcode.cn/problems/longest-substring-without-repeating-characters/) |      |      |      |      |      |
| [438. 找到字符串中所有字母异位词](https://leetcode.cn/problems/find-all-anagrams-in-a-string/) |      |      |      |      |      |
| [567. 字符串的排列](https://leetcode.cn/problems/permutation-in-string/) |      |      |      |      |      |
| [76. 最小覆盖子串](https://leetcode.cn/problems/minimum-window-substring/) |      |      |      |      |      |
| [剑指 Offer 48. 最长不含重复字符的子字符串](https://leetcode.cn/problems/zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof/) |      |      |      |      |      |
| [剑指 Offer II 014. 字符串中的变位词](https://leetcode.cn/problems/MPnaiL/) |      |      |      |      |      |
| [剑指 Offer II 015. 字符串中的所有变位词](https://leetcode.cn/problems/VabMRr/) |      |      |      |      |      |
| [剑指 Offer II 016. 不含重复字符的最长子字符串](https://leetcode.cn/problems/wtcaE1/) |      |      |      |      |      |
| [剑指 Offer II 017. 含有所有字符的最短字符串](https://leetcode.cn/problems/M1oyTv/) |      |      |      |      |      |



### 二分搜索-review

| Number                                                       |      |      |
| ------------------------------------------------------------ | ---- | ---- |
| [34. 在排序数组中查找元素的第一个和最后一个位置](https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/) |      |      |
| [704. 二分查找](https://leetcode.cn/problems/binary-search/) |      |      |
| [剑指 Offer 53 - I. 在排序数组中查找数字 I](https://leetcode.cn/problems/zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof/) |      |      |



### 数组-review

| Number                                                       |      |      |
| ------------------------------------------------------------ | ---- | ---- |
| [167. 两数之和 II - 输入有序数组](https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/) |      |      |
| [26. 删除有序数组中的重复项](https://leetcode.cn/problems/remove-duplicates-from-sorted-array/) |      |      |
| [27. 移除元素](https://leetcode.cn/problems/remove-element/) |      |      |
| [283. 移动零](https://leetcode.cn/problems/move-zeroes/)     |      |      |
| [344. 反转字符串](https://leetcode.cn/problems/reverse-string/) |      |      |
| [5. 最长回文子串](https://leetcode.cn/problems/longest-palindromic-substring/) |      |      |
| [83. 删除排序链表中的重复元素](https://leetcode.cn/problems/remove-duplicates-from-sorted-list/) |      |      |
| [剑指 Offer 57. 和为s的两个数字](https://leetcode.cn/problems/he-wei-sde-liang-ge-shu-zi-lcof/) |      |      |
| [剑指 Offer II 006. 排序数组中两个数字之和](https://leetcode.cn/problems/kLl5u1/) |      |      |

### nSum-review

| Number                                                       |      |      |
| ------------------------------------------------------------ | ---- | ---- |
| [1. 两数之和](https://leetcode.cn/problems/two-sum/)         |      |      |
| [15. 三数之和](https://leetcode.cn/problems/3sum/)           |      |      |
| [167. 两数之和 II - 输入有序数组](https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/) |      |      |
| [18. 四数之和](https://leetcode.cn/problems/4sum/)           |      |      |
| [剑指 Offer II 007. 数组中和为 0 的三个数](https://leetcode.cn/problems/1fGaJU/) |      |      |

### 二叉树-review

| Number                                                       |      |      |
| ------------------------------------------------------------ | ---- | ---- |
| [104. 二叉树的最大深度](https://leetcode.cn/problems/maximum-depth-of-binary-tree/) |      |      |
| [144. 二叉树的前序遍历](https://leetcode.cn/problems/binary-tree-preorder-traversal/) |      |      |
| [543. 二叉树的直径](https://leetcode.cn/problems/diameter-of-binary-tree/) |      |      |
| [剑指 Offer 55 - I. 二叉树的深度](https://leetcode.cn/problems/er-cha-shu-de-shen-du-lcof/) |      |      |
|                                                              |      |      |
|                                                              |      |      |
|                                                              |      |      |
|                                                              |      |      |
|                                                              |      |      |





## 阶段二：动态规划

|     动态规划     | 类型 |       时间        |
| :--------------: | :--: | :---------------: |
| 动态规划基本技巧 |      |                   |
|  子序列类型问题  |      | 20231103-20231106 |
|   背包类型问题   |      |                   |
| 用动态规划玩游戏 |      |                   |
|   贪心类型问题   |      |                   |



### 动态规划-review

| Number                                                       |      |      |
| ------------------------------------------------------------ | ---- | ---- |
| [322. 零钱兑换](https://leetcode.cn/problems/coin-change/)   |      |      |
| [509. 斐波那契数](https://leetcode.cn/problems/fibonacci-number/) |      |      |
| [剑指 Offer II 103. 最少的硬币数目](https://leetcode.cn/problems/gaM7Ch/) |      |      |
| [300. 最长递增子序列](https://leetcode.cn/problems/longest-increasing-subsequence/) |      |      |
| [354. 俄罗斯套娃信封问题](https://leetcode.cn/problems/russian-doll-envelopes/) |      |      |
| [72. 编辑距离](https://leetcode.cn/problems/edit-distance/)  |      |      |
| [53. 最大子数组和](https://leetcode.cn/problems/maximum-subarray/) |      |      |
| [剑指 Offer 42. 连续子数组的最大和](https://leetcode.cn/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof/) |      |      |
| [1143. 最长公共子序列](https://leetcode.cn/problems/longest-common-subsequence/) |      |      |
| [583. 两个字符串的删除操作](https://leetcode.cn/problems/delete-operation-for-two-strings/) |      |      |
| [712. 两个字符串的最小ASCII删除和](https://leetcode.cn/problems/minimum-ascii-delete-sum-for-two-strings/) |      |      |
| [剑指 Offer II 095. 最长公共子序列](https://leetcode.cn/problems/qJnOS7/) |      |      |
| [1312. 让字符串成为回文串的最少插入次数](https://leetcode.cn/problems/minimum-insertion-steps-to-make-a-string-palindrome/) |      |      |
| [516. 最长回文子序列](https://leetcode.cn/problems/longest-palindromic-subsequence/) |      |      |
| [121. 买卖股票的最佳时机](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/) |      |      |
| [122. 买卖股票的最佳时机 II](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/) |      |      |
| [123. 买卖股票的最佳时机 III](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/) |      |      |
| [188. 买卖股票的最佳时机 IV](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/) |      |      |
| [309. 最佳买卖股票时机含冷冻期](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/) |      |      |
| [714. 买卖股票的最佳时机含手续费](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/) |      |      |
| [剑指 Offer 63. 股票的最大利润](https://leetcode.cn/problems/gu-piao-de-zui-da-li-run-lcof/) |      |      |
| [198. 打家劫舍](https://leetcode.cn/problems/house-robber/)  |      |      |
| [213. 打家劫舍 II](https://leetcode.cn/problems/house-robber-ii/) |      |      |
| [337. 打家劫舍 III](https://leetcode.cn/problems/house-robber-iii/) |      |      |
| [剑指 Offer II 089. 房屋偷盗](https://leetcode.cn/problems/Gu0c2T/) |      |      |
| [剑指 Offer II 090. 环形房屋偷盗](https://leetcode.cn/problems/PzWKhm/) |      |      |
|                                                              |      |      |
|                                                              |      |      |
|                                                              |      |      |













## 阶段三：算法技巧

|   算法技巧   | 类型 | 时间 |
| :----------: | :--: | :--: |
| 暴力搜索算法 |      |      |
| 数学运算技巧 |      |      |
|  经典面试题  |      |      |

