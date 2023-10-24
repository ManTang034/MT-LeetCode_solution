/*
 * @lc app=leetcode.cn id=15 lang=cpp
 * @lcpr version=30102
 *
 * [15] 三数之和
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
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>>res;
        for(int i=0;i<n;i++){
            vector<vector<int>>tuples=twoSum(nums,i+1,-nums[i]);
            for(vector<int> tuple:tuples){
                tuple.push_back(nums[i]);
                res.push_back(tuple);
            }
            while(i<n-1&&nums[i]==nums[i+1]) i++;
        }
        return res;
    }
    //计算两数之和
    vector<vector<int>> twoSum(vector<int>&nums,int start,int target){
        int lo=start,hi=nums.size()-1;
        vector<vector<int>>res;
        while(lo<hi){
            int sum=nums[lo]+nums[hi];
            int left=nums[lo],right=nums[hi];
            if(sum>target){
                while(lo<hi&&nums[hi]==right) hi--;
            }else if(sum<target){
                while(lo<hi&&nums[lo]==left) lo++;
            }else{
                res.push_back({left,right});
                while(lo<hi&&nums[hi]==right) hi--;
                while(lo<hi&&nums[lo]==left) lo++;
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [-1,0,1,2,-1,-4]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,1]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,0]\n
// @lcpr case=end

 */

