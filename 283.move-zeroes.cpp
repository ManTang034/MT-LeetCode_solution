/*
 * @lc app=leetcode.cn id=283 lang=cpp
 * @lcpr version=30102
 *
 * [283] 移动零
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
    void moveZeroes(vector<int>& nums) {
        //去除所有0,返回不含0的数组长度
        int p=removeElement(nums,0);
        for(;p<nums.size();p++){
            nums[p]=0;
        }
    }
    int removeElement(vector<int>&nums,int val){
        if(nums.size()==0) return 0;
        int slow=0,fast=0;
        while(fast<nums.size()){
            if(nums[fast]!=val){
                nums[slow]=nums[fast];
                slow++;
            }
            fast++;
        }
        return slow;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,1,0,3,12]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */

