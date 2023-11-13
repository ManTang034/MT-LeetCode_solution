/*
 * @lc app=leetcode.cn id=213 lang=cpp
 * @lcpr version=30106
 *
 * [213] 打家劫舍 II
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
        if(n==1) return nums[0];
        //第一间被抢，最后一间不抢
        //第一间不抢，最后一间抢
        return max(robRange(nums,0,n-2),robRange(nums,1,n-1));
    }

    int robRange(vector<int>&nums,int start,int end){
        int n=nums.size();
        int dp_i_1=0,dp_i_2=0;
        int dp_i=0;
        for(int i=end;i>=start;i--){
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
// [2,3,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

 */

