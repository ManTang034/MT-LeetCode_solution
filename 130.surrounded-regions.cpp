/*
 * @lc app=leetcode.cn id=130 lang=cpp
 * @lcpr version=30111
 *
 * [130] 被围绕的区域
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

class UF{
    vector<int>parent;
public:
    UF(int n){
        for(int i=0;i<n;i++){
            parent.push_back(i);
        }
    }

    int find(int x){
        if(x!=parent[x]){
            parent[x]=find(parent[x]);
        }
        return parent[x];
    }

    void _union(int x,int y){
        int rootX=find(x);
        int rootY=find(y);
        if(rootX!=rootY){
            parent[rootX]=rootY;
        }
    }

    bool isConnected(int x,int y){
        int rootX=find(x);
        int rootY=find(y);
        return rootX==rootY;
    }
};

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty()) return;

        int m=board.size();
        int n=board[0].size();

        //给dummy留一个额外位置
        UF uf(m*n+1);
        int dummy=m*n;
        //将首列和末列的O与dummy相连
        for(int i=0;i<m;i++){
            if(board[i][0]=='O'){
                uf._union(i*n,dummy);
            }
            if(board[i][n-1]=='O'){
                uf._union(i*n+n-1,dummy);
            }
        }

        //将首行和末行的O与dummy相连
        for(int j=0;j<n;j++){
            if(board[0][j]=='O'){
                uf._union(j,dummy);
            }
            if(board[m-1][j]=='O'){
                uf._union(n*(m-1)+j,dummy);
            }
        }

        //方向数组d是上下左右搜索的常用手法
        int d[4][2]={{1,0},{0,1},{0,-1},{-1,0}};
        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){
                if(board[i][j]=='O'){
                    //将此O与上下左右的O相连
                    for(int k=0;k<4;k++){
                        int x=i+d[k][0];
                        int y=j+d[k][1];

                        if(board[x][y]=='O'){
                            uf._union(x*n+y,i*n+j);
                        }
                    }
                }
            }
        }

        //将所有不和dummy相连的O，都要被替换
        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){
                if(!uf.isConnected(dummy,i*n+j)){
                    board[i][j]='X';
                }
            }
        }
    }
};


// @lc code=end



/*
// @lcpr case=start
// [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]\n
// @lcpr case=end

// @lcpr case=start
// [["X"]]\n
// @lcpr case=end

 */

