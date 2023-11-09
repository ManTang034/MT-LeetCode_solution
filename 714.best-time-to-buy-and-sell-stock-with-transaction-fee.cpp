/*
 * @lc app=leetcode.cn id=714 lang=cpp
 * @lcpr version=30106
 *
 * [714] 买卖股票的最佳时机含手续费
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
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2));
        for(int i=0;i<n;i++){
            if(i-1==-1){
                //base case
                dp[i][0]=0;
                dp[i][1]=-prices[i]-fee;
                continue;
            }
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]);
            dp[i][1]=max(dp[i-1][1],dp[i-1][0]-prices[i]-fee);
        }
        return dp[n-1][0];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1, 3, 2, 8, 4, 9]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,3,7,5,10,3]\n3\n
// @lcpr case=end

 */

