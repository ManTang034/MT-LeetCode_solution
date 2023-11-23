/*
 * @lc app=leetcode.cn id=111 lang=cpp
 * @lcpr version=30109
 *
 * [111] 二叉树的最小深度
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
    int minDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        queue<TreeNode*>q;
        q.push(root);
        int depth=1;

        while(!q.empty()){
            int sz=q.size();
            /*将当前队列中的所有节点向四周扩散*/
            for(int i=0;i<sz;i++){
                TreeNode* cur=q.front();
                q.pop();
                /*判断是否到达终点*/
                if(cur->left==nullptr&&cur->right==nullptr){
                    return depth;
                }
                /*将cur的相邻节点加入队列*/
                if(cur->left){
                    q.push(cur->left);
                }
                if(cur->right){
                    q.push(cur->right);
                }
            }
            depth++;
        }
        return depth;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [2,null,3,null,4,null,5,null,6]\n
// @lcpr case=end

 */

