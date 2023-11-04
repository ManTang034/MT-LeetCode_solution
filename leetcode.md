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







# 时间线1

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
| LC 76  |                  minimum-window-substring                  |  done  | 20231021 |
| LC 567 |                   permutation-in-string                    |  done  | 20231021 |
| LC 438 |               find-all-anagrams-in-a-string                |  done  | 20231021 |
|  LC 3  |       longest-substring-without-repeating-characters       |  done  | 20231021 |
| LC 704 |                       binary-search                        |  done  | 20231022 |
| LC 34  |  find-first-and-last-position-of-element-in-sorted-array   |  done  | 20231023 |
| LC 167 |              two-sum-ii-input-array-is-sorted              |  done  | 20231024 |
| LC 15  |                           3-sum                            |  done  | 20231024 |
| LC 18  |                           4-sum                            |  done  | 20231024 |
| LC 344 |                       reverse-string                       |  done  | 20231024 |
|  LC 5  |               longest-palindromic-substring                |  done  | 20231024 |
| LC 104 |                maximum-depth-of-binary-tree                |  done  | 20231025 |
| LC 543 |                  diameter-of-binary-tree                   |  done  | 20231027 |
| LC 509 |                      fibonacci-number                      |  done  | 20231031 |
| LC 322 |                        coin-change                         |  done  | 20231031 |
| LC 300 |               longest-increasing-subsequence               |  done  | 20231101 |
| LC 322 |                        coin-change                         |  done  | 20231101 |
| LC 509 |                      fibonacci-number                      |  done  | 20231101 |
| LC 543 |                  diameter-of-binary-tree                   |  done  | 20231101 |
| LC 72  |                       edit-distance                        |  done  | 20231103 |
|        |                                                            |        |          |
|        |                                                            |        |          |
|        |                                                            |        |          |
|        |                                                            |        |          |
|        |                                                            |        |          |
|        |                                                            |        |          |
|        |                                                            |        |          |
|        |                                                            |        |          |
|        |                                                            |        |          |
|        |                                                            |        |          |
|        |                                                            |        |          |

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

|     动态规划     | 类型 |   时间    |
| :--------------: | :--: | :-------: |
| 动态规划基本技巧 |      |           |
|  子序列类型问题  |      | 20231103- |
|   背包类型问题   |      |           |
| 用动态规划玩游戏 |      |           |
|   贪心类型问题   |      |           |



### 动态规划-review

| Number                                                       |      |      |
| ------------------------------------------------------------ | ---- | ---- |
| [322. 零钱兑换](https://leetcode.cn/problems/coin-change/)   |      |      |
| [509. 斐波那契数](https://leetcode.cn/problems/fibonacci-number/) |      |      |
| [剑指 Offer II 103. 最少的硬币数目](https://leetcode.cn/problems/gaM7Ch/) |      |      |
| [300. 最长递增子序列](https://leetcode.cn/problems/longest-increasing-subsequence/) |      |      |
| [354. 俄罗斯套娃信封问题](https://leetcode.cn/problems/russian-doll-envelopes/) |      |      |
| [72. 编辑距离](https://leetcode.cn/problems/edit-distance/)  |      |      |













## 阶段三：算法技巧

|   算法技巧   | 类型 | 时间 |
| :----------: | :--: | :--: |
| 暴力搜索算法 |      |      |
| 数学运算技巧 |      |      |
|  经典面试题  |      |      |

