/*
 * @lc app=leetcode.cn id=695 lang=cpp
 * @lcpr version=30110
 *
 * [695] 岛屿的最大面积
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
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res=0;
        int m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    res=max(res,dfs(grid,i,j));
                }
            }
        }
        return res;
    }
    
    int dfs(vector<vector<int>>&grid,int i,int j){
        int m=grid.size(),n=grid[0].size();
        if(i<0||j<0||i>=m||j>=n){
            return 0;
        }
        if(grid[i][j]==0){
            return 0;
        }
        grid[i][j]=0;
        return dfs(grid,i-1,j)+dfs(grid,i+1,j)+dfs(grid,i,j-1)+dfs(grid,i,j+1)+1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,0,0,0,0,0,0,0]]\n
// @lcpr case=end

 */

