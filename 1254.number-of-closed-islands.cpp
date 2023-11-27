/*
 * @lc app=leetcode.cn id=1254 lang=cpp
 * @lcpr version=30110
 *
 * [1254] 统计封闭岛屿的数目
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
    int closedIsland(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        for(int j=0;j<n;j++){
            //把靠上边的岛屿淹掉
            dfs(grid,0,j);
            //把靠下边的岛屿淹掉
            dfs(grid,m-1,j);
        }

        for(int i=0;i<m;i++){
            //把靠左边的岛屿淹掉
            dfs(grid,i,0);
            //把靠右边的岛屿淹掉
            dfs(grid,i,n-1);
        }

        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    res++;
                    dfs(grid,i,j);
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<int>>&grid, int i,int j){
        int m=grid.size(),n=grid[0].size();
        if(i<0||j<0||i>=m||j>=n){
            return;
        }
        if(grid[i][j]==1){
            return;
        }
        grid[i][j]=1;
        dfs(grid,i-1,j);
        dfs(grid,i+1,j);
        dfs(grid,i,j-1);
        dfs(grid,i,j+1);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1,1,1,1,1,1],[1,0,0,0,0,0,1],[1,0,1,1,1,0,1],[1,0,1,0,1,0,1],[1,0,1,1,1,0,1],[1,0,0,0,0,0,1],[1,1,1,1,1,1,1]]\n
// @lcpr case=end

 */

