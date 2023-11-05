/*
 * @lc app=leetcode.cn id=53 lang=cpp
 * @lcpr version=30102
 *
 * [53] 最大子数组和
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
// @lc code=end



/*
// @lcpr case=start
// [-2,1,-3,4,-1,2,1,-5,4]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

// @lcpr case=start
// [5,4,-1,7,8]\n
// @lcpr case=end

 */

