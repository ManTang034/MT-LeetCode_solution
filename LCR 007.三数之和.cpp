/*
 * @lc app=leetcode.cn id=LCR 007 lang=cpp
 * @lcpr version=30102
 *
 * [LCR 007] 三数之和
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
        return nSum(nums,3,0,0);
    }
    vector<vector<int>>nSum(vector<int>&nums,int n,int start,int target){
        int sz=nums.size();
        vector<vector<int>>res;
        if(n<2||sz<n) return res;
        if(n==2){
            int lo=start,hi=sz-1;
            while(lo<hi){
                int sum=nums[lo]+nums[hi];
                int left=nums[lo],right=nums[hi];
                if(sum>target){
                    while(lo<hi&&nums[hi]==right) hi--;
                }else if(sum<target){
                    while(lo<hi&&nums[lo]==left) lo++;
                }else{
                    res.push_back({left,right});
                    while(lo<hi&&nums[lo]==left) lo++;
                    while(lo<hi&&nums[hi]==right) hi--;
                }
            }
        }else{
            for(int i=start;i<sz;i++){
                vector<vector<int>>tuples=nSum(nums,n-1,i+1,target-nums[i]);
                for(vector<int>tuple:tuples){
                    tuple.push_back(nums[i]);
                    res.push_back(tuple);
                }
                while(i<sz-1&&nums[i]==nums[i+1]) i++;
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
// []\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */

