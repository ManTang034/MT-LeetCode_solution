/*
 * @lc app=leetcode.cn id=39 lang=cpp
 * @lcpr version=30109
 *
 * [39] 组合总和
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
    int trackSum=0;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtrack(candidates,0,target);
        return res;
    }

    void backtrack(vector<int>&nums,int start,int target){
        //base case，找到目标和，记录结果
        if(trackSum==target){
            res.push_back(track);
            return;
        }
        //base case，超过目标和，停止向下遍历
        if(trackSum>target){
            return;
        }

        for(int i=start;i<nums.size();i++){
            trackSum+=nums[i];
            track.push_back(nums[i]);
            backtrack(nums,i,target);
            trackSum-=nums[i];
            track.pop_back();
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,6,7]\n7\n
// @lcpr case=end

// @lcpr case=start
// [2,3,5]\n8\n
// @lcpr case=end

// @lcpr case=start
// [2]\n1\n
// @lcpr case=end

 */

