/*
 * @lc app=leetcode.cn id=78 lang=cpp
 * @lcpr version=30109
 *
 * [78] 子集
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
private:
    vector<vector<int>>res;
    //记录回溯算法的递归路径
    vector<int>track;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums,0);
        return res;
    }

    void backtrack(vector<int>&nums,int start){
        //前序位置，每个节点的值都是一个子集
        res.push_back(track);

        //回溯算法标准框架
        for(int i=start;i<nums.size();i++){
            //做选择
            track.push_back(nums[i]);
            //通过start参数控制树枝的遍历，避免产生重复的子集
            backtrack(nums,i+1);
            //撤销选择
            track.pop_back();
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */

