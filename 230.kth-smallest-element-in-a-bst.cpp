/*
 * @lc app=leetcode.cn id=230 lang=cpp
 * @lcpr version=30102
 *
 * [230] 二叉搜索树中第K小的元素
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
    // 记录结果
    int res=0;
    // 记录当前元素的排名
    int rank=0;
    int kthSmallest(TreeNode* root, int k) {
        traverse(root,k);
        return res;
    }
    void traverse(TreeNode*root,int k){
        // base case
        if(root==nullptr) return;
        traverse(root->left,k);
        // 中序遍历位置
        rank++;
        if(k==rank){
            res=root->val;
            return;
        }
        traverse(root->right,k);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,1,4,null,2]\n1\n
// @lcpr case=end

// @lcpr case=start
// [5,3,6,2,4,null,null,1]\n3\n
// @lcpr case=end

 */

