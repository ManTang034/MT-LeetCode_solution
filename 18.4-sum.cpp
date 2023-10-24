/*
 * @lc app=leetcode.cn id=18 lang=cpp
 * @lcpr version=30102
 *
 * [18] 四数之和
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
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        // n 为 4，从 nums[0] 开始计算和为 target 的四元组
        return nSumTarget(nums, 4, 0, target);
    }
    vector<vector<int>> nSumTarget(
        vector<int> &nums, int n, int start, long long target)
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
                long long sum = (long long)nums[lo] + nums[hi];
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
                    sub = nSumTarget(nums, n - 1, i + 1, (long long)target - nums[i]);
                for (vector<int> arr : sub)
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
};
// @lc code=end

/*
// @lcpr case=start
// [1,0,-1,0,-2,2]\n0\n
// @lcpr case=end

// @lcpr case=start
// [2,2,2,2,2]\n8\n
// @lcpr case=end

 */
