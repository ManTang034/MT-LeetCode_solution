/*
 * @lc app=leetcode.cn id=309 lang=cpp
 * @lcpr version=30106
 *
 * [309] 买卖股票的最佳时机含冷冻期
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
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2));
        for(int i=0;i<n;i++){
            if(i-1==-1){
                dp[i][0]=0;
                dp[i][1]=-prices[i];
                continue;
            }
            if(i-2==-1){
                dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]);
                dp[i][1]=max(dp[i-1][1],-prices[i]);
                continue;
            }
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]);
            dp[i][1]=max(dp[i-1][1],dp[i-2][0]-prices[i]);
        }
        return dp[n-1][0];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,0,2]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

