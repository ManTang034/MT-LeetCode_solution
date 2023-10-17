/*
 * @lc app=leetcode.cn id=105 lang=cpp
 * @lcpr version=30102
 *
 * [105] 从前序与中序遍历序列构造二叉树
 */

// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder){
        return build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }
    /*
        定义：前序遍历数组为preorder[preStart..preEnd]
        中序遍历数组为inorder[inStart..inEnd]
        构造这个二叉树并返回该二叉树的根节点
    */
    TreeNode *build(vector<int> &preorder, int preStart, int preEnd, vector<int>&inorder,int inStart,int inEnd){
        // base case
        if(preStart>preEnd) return nullptr;

        // root节点对应的值就是前序遍历数组的第一个元素
        int rootVal=preorder[preStart];
        // rootVal在中序遍历数组中的索引
        int index=0;
        for(int i=inStart;i<=inEnd;i++){
            if(inorder[i] == rootVal){
                index=i;
                break;
            }
        }

        int leftsize=index-inStart;

        //先构造出当前根节点
        TreeNode *root=new TreeNode(rootVal);
        //递归构造左右子树
        root->left=build(preorder,preStart+1,preStart+leftsize,inorder,inStart,index-1);
        root->right=build(preorder,preStart+leftsize+1,preEnd,inorder,index+1,inEnd);
        return root;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [3,9,20,15,7]\n[9,3,15,20,7]\n
// @lcpr case=end

// @lcpr case=start
// [-1]\n[-1]\n
// @lcpr case=end

 */
