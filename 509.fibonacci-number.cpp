/*
 * @lc app=leetcode.cn id=509 lang=cpp
 * @lcpr version=30102
 *
 * [509] 斐波那契数
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
    int fib(int n) {
        if(n==0||n==1) return n;
        //分别代表dp[i-1]和dp[i-2]
        int dp_i_1=1,dp_i_2=0;
        for(int i=2;i<=n;i++){
            int dp_i=dp_i_1+dp_i_2;
            // 滚动更新
            dp_i_2=dp_i_1;
            dp_i_1=dp_i;
        }
        return dp_i_1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 4\n
// @lcpr case=end

 */

