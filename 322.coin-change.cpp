/*
 * @lc app=leetcode.cn id=322 lang=cpp
 * @lcpr version=30102
 *
 * [322] 零钱兑换
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
private:
    vector<int> memo;

    int dp(vector<int> &coins, int amount)
    {
        if (amount == 0)
            return 0;
        if (amount < 0)
            return -1;
        if (memo[amount] != -666)
            return memo[amount];

        int res = INT_MAX;
        for (int coin : coins)
        {
            int subProblem = dp(coins, amount - coin);
            if (subProblem == -1)
                continue;
            res = min(res, subProblem + 1);
        }
        memo[amount] = res == INT_MAX ? -1 : res;
        return memo[amount];
    }

public:
    int coinChange(vector<int> &coins, int amount)
    {
        memo=vector<int>(amount+1,-666);
        return dp(coins,amount);
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1, 2, 5]\n11\n
// @lcpr case=end

// @lcpr case=start
// [2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n0\n
// @lcpr case=end

 */
