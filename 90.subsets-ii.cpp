/*
 * @lc app=leetcode.cn id=90 lang=cpp
 * @lcpr version=30109
 *
 * [90] 子集 II
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
    vector<vector<int>>res;
    vector<int>track;

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        //排序让相同的元素呆在一起
        sort(nums.begin(),nums.end());
        backtrack(nums,0);
        return res;
    }

    void backtrack(vector<int>&nums,int start){
        res.push_back(track);

        for(int i=start;i<nums.size();i++){
            //剪枝逻辑，值相同的相邻树枝，只遍历第一条
            if(i>start&&nums[i]==nums[i-1]){
                continue;
            }
            track.push_back(nums[i]);
            backtrack(nums,i+1);
            track.pop_back();
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,2]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */

