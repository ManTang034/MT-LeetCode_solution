/*
 * @lc app=leetcode.cn id=200 lang=cpp
 * @lcpr version=30110
 *
 * [200] 岛屿数量
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
    int numIslands(vector<vector<char>>& grid) {
        int res=0;
        int m=grid.size(),n=grid[0].size();
        //遍历grid
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    //每发现一个岛屿，岛屿数量加一
                    res++;
                    //然后使用DFS将岛屿淹了
                    dfs(grid,i,j);
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<char>>&grid, int i, int j){
        int m=grid.size(),n=grid[0].size();
        if(i<0||j<0||i>=m||j>=n){
            //超出索引边界
            return;
        }
        if(grid[i][j]=='0'){
            //已经是海水
            return;
        }
        grid[i][j]='0';
        dfs(grid,i+1,j);
        dfs(grid,i-1,j);
        dfs(grid,i,j-1);
        dfs(grid,i,j+1);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]\n
// @lcpr case=end

// @lcpr case=start
// [["1","1","0","0","0"],["1","1","0","0","0"],["0","0","1","0","0"],["0","0","0","1","1"]]\n
// @lcpr case=end

 */

