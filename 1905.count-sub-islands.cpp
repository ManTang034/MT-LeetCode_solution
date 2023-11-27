/*
 * @lc app=leetcode.cn id=1905 lang=cpp
 * @lcpr version=30110
 *
 * [1905] 统计子岛屿
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
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m=grid1.size(),n=grid1[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid1[i][j]==0&&grid2[i][j]==1){
                    //这个岛屿肯定不是子岛，淹掉
                    dfs(grid2,i,j);
                }
            }
        }
        //现在grid2中剩下的岛屿都是子岛，计算岛屿数量
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid2[i][j]==1){
                    res++;
                    dfs(grid2,i,j);
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<int>>&grid,int i,int j){
        int m=grid.size(),n=grid[0].size();
        if(i<0||j<0||i>=m||j>=n){
            return;
        }
        if(grid[i][j]==0){
            return;
        }
        grid[i][j]=0;
        dfs(grid,i-1,j);
        dfs(grid,i+1,j);
        dfs(grid,i,j-1);
        dfs(grid,i,j+1);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]]\n[[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,0,1,0,1],[1,1,1,1,1],[0,0,0,0,0],[1,1,1,1,1],[1,0,1,0,1]]\n[[0,0,0,0,0],[1,1,1,1,1],[0,1,0,1,0],[0,1,0,1,0],[1,0,0,0,1]]\n
// @lcpr case=end

 */

