/*
 * @lc app=leetcode.cn id=226 lang=cpp
 * @lcpr version=30102
 *
 * [226] 翻转二叉树
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

// 把二叉树的每一个节点的左右子节点进行交换，最后的结果就是反转后的二叉树
class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        // base case
        if (root == nullptr)
        {
            return nullptr;
        }
        // root节点交换左右子节点
        TreeNode *tmp=root->left;
        root->left=root->right;
        root->right=tmp;

        //左右子节点继续交换起子节点
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [4,2,7,1,3,6,9]\n
// @lcpr case=end

// @lcpr case=start
// [2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */
