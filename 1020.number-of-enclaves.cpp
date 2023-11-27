/*
 * @lc app=leetcode.cn id=1020 lang=cpp
 * @lcpr version=30110
 *
 * [1020] 飞地的数量
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
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        //淹掉靠边的陆地
        for(int i=0;i<m;i++){
            dfs(grid,i,0);
            dfs(grid,i,n-1);
        }
        for(int j=0;j<n;j++){
            dfs(grid,0,j);
            dfs(grid,m-1,j);
        }
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    res+=1;
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<int>>&grid, int i, int j){
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
// [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]\n
// @lcpr case=end

 */

