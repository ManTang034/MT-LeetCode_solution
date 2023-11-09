/*
 * @lc app=leetcode.cn id=188 lang=cpp
 * @lcpr version=30106
 *
 * [188] 买卖股票的最佳时机 IV
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
    int maxProfit(int max_k, vector<int>& prices) {
        int n=prices.size();
        if(n<=0) return 0;
        if(max_k>n/2){
            maxProfit_inf(prices);
        }
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(max_k+1,vector<int>(2)));
        for(int i=0;i<n;i++){
            dp[i][0][1]=INT_MIN;
            dp[i][0][0]=0;
        }
        for(int i=0;i<n;i++){
            for(int k=max_k;k>=1;k--){
                if(i-1==-1){
                    //base case
                    dp[i][k][0]=0;
                    dp[i][k][1]=-prices[i];
                    continue;
                }
                dp[i][k][0]=max(dp[i-1][k][0],dp[i-1][k][1]+prices[i]);
                dp[i][k][1]=max(dp[i-1][k][1],dp[i-1][k-1][0]-prices[i]);
            }
        }
        return dp[n-1][max_k][0];
    }

    int maxProfit_inf(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2));
        for(int i=0;i<n;i++){
            if(i-1==-1){
                dp[i][0]=0;
                dp[i][1]=-prices[i];
                continue;
            }
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]);
            dp[i][1]=max(dp[i-1][1],dp[i-1][0]-prices[i]);
        }
        return dp[n-1][0];
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n[2,4,1]\n
// @lcpr case=end

// @lcpr case=start
// 2\n[3,2,6,5,0,3]\n
// @lcpr case=end

 */

