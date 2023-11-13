/*
 * @lc app=leetcode.cn id=337 lang=cpp
 * @lcpr version=30106
 *
 * [337] 打家劫舍 III
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
// @lc code=end



/*
// @lcpr case=start
// [3,2,3,null,3,null,1]\n
// @lcpr case=end

// @lcpr case=start
// [3,4,5,1,3,null,1]\n
// @lcpr case=end

 */

