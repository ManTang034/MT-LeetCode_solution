/*
 * @lc app=leetcode.cn id=52 lang=cpp
 * @lcpr version=30109
 *
 * [52] N 皇后 II
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
    int res=0;
    int totalNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        backtrack(board,0);
        return res;
    }

    //路径：board中小于row的那些行都已经成功放置了皇后
    //选择列表：第row行的所有列都是放置皇后的选择
    //结束条件：row超过board的最后一行
    void backtrack(vector<string>&board, int row){
        //触发结束条件
        if(row==board.size()){
            res++;
            return;
        }

        int n=board[row].size();
        for(int col=0;col<n;col++){
            //排除不合法选择
            if(!isValid(board,row,col)){
                continue;
            }
            //做选择
            board[row][col]='Q';
            //进入下一行决策
            backtrack(board,row+1);
            //撤销选择
            board[row][col]='.';
        }
    }

    bool isValid(vector<string>&board,int row,int col){
        int n=board.size();
        //检查列是否有皇后互相冲突
        for(int i=0;i<=row;i++){
            if(board[i][col]=='Q'){
                return false;
            }
        }
        //检查右上方是否有皇后互相冲突
        for(int i=row-1,j=col+1;i>=0&&j<n;i--,j++){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        //检查左上方是否有皇后互相冲突
        for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 4\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

