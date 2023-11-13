/*
 * @lc app=leetcode.cn id=198 lang=cpp
 * @lcpr version=30106
 *
 * [198] 打家劫舍
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
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [2,7,9,3,1]\n
// @lcpr case=end

 */

