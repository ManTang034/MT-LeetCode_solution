/*
 * @lc app=leetcode.cn id=773 lang=cpp
 * @lcpr version=30110
 *
 * [773] 滑动谜题
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
    int slidingPuzzle(vector<vector<int>>& board) {
        int m=2,n=3;
        string target="123450";
        string start="";
        //将2*3的数组转化成字符串作为BFS的起点
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                start+=to_string(board[i][j]);
            }
        }

        //记录一维字符串的相邻索引
        //含义就是在一维字符串中，索引i在二维数组中的相邻索引为neighbor[i]
        vector<vector<int>>neighbor={
            {1,3},
            {0,4,2},
            {1,5},
            {0,4},
            {3,1,5},
            {4,2}
        };

        queue<string>q;
        unordered_set<string>visited;
        //从起点开始BFS搜索
        q.push(start);
        visited.insert(start);

        int step=0;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                string cur=q.front();
                q.pop();
                //判断是否达到目标局面
                if(cur==target){
                    return step;
                }
                //找到数字0的索引
                int idx=0;
                for(;cur[idx]!='0';idx++);
                //将数字0和相邻的数字交换位置
                for(int adj:neighbor[idx]){
                    string new_board=swap(cur,adj,idx);
                    //防止走回头路
                    if(!visited.count(new_board)){
                        q.push(new_board);
                        visited.insert(new_board);
                    }
                }
            }
            step++;
        }
        return -1;
    }

    string swap(string s,int i,int j){
        char temp=s[i];
        s[i]=s[j];
        s[j]=temp;
        return s;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2,3],[4,0,5]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3],[5,4,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[4,1,2],[5,0,3]]\n
// @lcpr case=end

 */

