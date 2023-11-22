/*
 * @lc app=leetcode.cn id=40 lang=cpp
 * @lcpr version=30109
 *
 * [40] 组合总和 II
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
    vector<vector<int>> res;
    //记录回溯的路径
    vector<int> track;
    //记录 track 中的元素之和
    int trackSum = 0;

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // 先排序，让相同的元素靠在一起
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, 0, target);
        return res;
    }

    //回溯算法主函数
    void backtrack(vector<int>& nums, int start, int target) {
        //base case，达到目标和，找到符合条件的组合
        if(trackSum == target) {
            res.push_back(track);
            return;
        }
        //base case，超过目标和，直接结束
        if(trackSum > target) {
            return;
        }

        //回溯算法标准框架
        for(int i = start; i < nums.size(); i++) {
            //剪枝逻辑，值相同的树枝，只遍历第一条
            if(i > start && nums[i] == nums[i-1]) {
                continue;
            }
            //做选择
            track.push_back(nums[i]);
            trackSum += nums[i];
            //递归遍历下一层回溯树
            backtrack(nums, i+1, target);
            //撤销选择
            track.pop_back();
            trackSum -= nums[i];
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [10,1,2,7,6,1,5]\n8,\n
// @lcpr case=end

// @lcpr case=start
// [2,5,2,1,2]\n5,\n
// @lcpr case=end

 */

