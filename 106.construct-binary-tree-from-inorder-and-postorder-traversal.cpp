/*
 * @lc app=leetcode.cn id=106 lang=cpp
 * @lcpr version=30102
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
    }
    TreeNode* build(vector<int>&inorder,int inStart,int inEnd,vector<int>&postorder,int postStart,int postEnd){
        //base case
        if(inStart>inEnd) return nullptr;

        int rootVal=postorder[postEnd];

        int index=0;
        for(int i=inStart;i<=inEnd;i++){
            if(inorder[i]==rootVal){
                index=i;
                break;
            }
        }

        int leftsize=index-inStart;

        TreeNode *root=new TreeNode(rootVal);
        root->left=build(inorder,inStart,index-1,postorder,postStart,postStart+leftsize-1);
        root->right=build(inorder,index+1,inEnd,postorder,postStart+leftsize,postEnd-1);
        return root;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [9,3,15,20,7]\n[9,15,7,20,3]\n
// @lcpr case=end

// @lcpr case=start
// [-1]\n[-1]\n
// @lcpr case=end

 */

