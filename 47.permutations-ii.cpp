/*
 * @lc app=leetcode.cn id=47 lang=cpp
 * @lcpr version=30109
 *
 * [47] 全排列 II
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
    vector<vector<int>>res; //保存结果
    vector<int>track; //记录当前位置的元素
    vector<bool>used; //记录元素是否被使用

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        //排序，让相同的元素靠在一起
        sort(nums.begin(),nums.end());
        //初始化used数组
        used=vector<bool>(nums.size(),false);
        backtrack(nums);
        return res;
    }

    void backtrack(vector<int>&nums){
        //当长度相等时，记录结果
        if(track.size()==nums.size()){
            res.push_back(track);
            return;
        }

        //遍历没有被使用过的元素
        for(int i=0;i<nums.size();i++){
            if(used[i]){
                continue;
            }
            //剪枝
            if(i>0&&nums[i]==nums[i-1]&&!used[i-1]){
                continue;
            }
            //添加元素，标记为使用过
            track.push_back(nums[i]);
            used[i]=true;
            //继续回溯
            backtrack(nums);
            track.pop_back();
            used[i]=false;
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

 */

