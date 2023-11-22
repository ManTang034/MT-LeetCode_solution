/*
 * @lc app=leetcode.cn id=77 lang=cpp
 * @lcpr version=30109
 *
 * [77] 组合
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

    vector<vector<int>> combine(int n, int k) {
        backtrack(1,n,k);
        return res;
    }

    void backtrack(int start,int n,int k){
        //base case
        if(k==track.size()){
            //遍历到了第k层，收集当前节点的值
            res.push_back(track);
            return;
        }

        //回溯算法标准框架
        for(int i=start;i<=n;i++){
            //选择
            track.push_back(i);
            backtrack(i+1,n,k);
            //撤销选择
            track.pop_back();
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// 4\n2\n
// @lcpr case=end

// @lcpr case=start
// 1\n1\n
// @lcpr case=end

 */

