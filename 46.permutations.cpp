/*
 * @lc app=leetcode.cn id=46 lang=cpp
 * @lcpr version=30109
 *
 * [46] 全排列
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

    /*主函数，输入一组不重复的数字，返回它们的全排列*/
    vector<vector<int>>Permute(vector<int>&nums){
        //记录路径
        vector<int>track;
        //路径中的元素会被标记为true，避免重复使用
        vector<bool>used(nums.size(),false);

        backtrack(nums,track,used);
        return res;
    }

    //路径：记录在track中
    //选择列表：nums中不存在于track的那些元素
    //结束条件：nums中的元素全都在track中出现
    void backtrack(vector<int>&nums,vector<int>&track,vector<bool>&used){
        //触发结束条件
        if(track.size()==nums.size()){
            res.push_back(track);
            return;
        }

        for(int i=0;i<nums.size();i++){
            //排除不合法选择
            if(used[i]){
                //nums[i]已经在track中，跳过
                continue;
            }
            //做选择
            track.push_back(nums[i]);
            used[i]=true;
            //进入下一层决策树
            backtrack(nums,track,used);
            //取消选择
            track.pop_back();
            used[i]=false;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        return Permute(nums);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0,1]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

