/*
 * @lc app=leetcode.cn id=123 lang=cpp
 * @lcpr version=30106
 *
 * [123] 买卖股票的最佳时机 III
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
        int max_k=2,n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(max_k+1,vector<int>(2)));
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
};
// @lc code=end



/*
// @lcpr case=start
// [3,3,5,0,0,3,1,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [7,6,4,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

