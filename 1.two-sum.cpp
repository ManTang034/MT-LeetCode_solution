/*
 * @lc app=leetcode.cn id=1 lang=cpp
 * @lcpr version=21917
 *
 * [1] 两数之和
 */
using namespace std;
#include <algorithm>
#include <vector>
#include<unordered_map>
// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>map;
        for(int i=0;i<nums.size();i++){
            if(map.count(target-nums[i])){
                return {i,map[target-nums[i]]};
            }
            map[nums[i]]=i;
        }
        return {};
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,7,11,15]\n9\n
// @lcpr case=end

// @lcpr case=start
// [3,2,4]\n6\n
// @lcpr case=end

// @lcpr case=start
// [3,3]\n6\n
// @lcpr case=end

 */

