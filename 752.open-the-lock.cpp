/*
 * @lc app=leetcode.cn id=752 lang=cpp
 * @lcpr version=30109
 *
 * [752] 打开转盘锁
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
    //将s[j]向上拨动一次
    string plusOne(string s,int j){
        if(s[j]=='9'){
            s[j]='0';
        }else{
            s[j]+=1;
        }
        return s;
    }

    //将s[j]向下拨动一次
    string minusOne(string s,int j){
        if(s[j]=='0'){
            s[j]='9';
        }else{
            s[j]-=1;
        }
        return s;
    }

    int openLock(vector<string>& deadends, string target) {
        //记录需要跳过的死亡密码
        unordered_set<string>deads;
        for(string s:deadends){
            deads.insert(s);
        }
        //记录已经穷举过的密码，防止走回头路
        unordered_set<string>visited;
        queue<string>q;
        //从起点开始进行广度优先搜索
        int step=0;
        q.push("0000");
        visited.insert("0000");

        while(!q.empty()){
            int sz=q.size();
            /*将当前队列中的所有节点向周围扩散*/
            for(int i=0;i<sz;i++){
                string cur=q.front();
                q.pop();

                /*判断是否到达终点*/
                if(deads.count(cur)){
                    continue;
                }
                if(cur==target){
                    return step;
                }

                /*将一个节点的未遍历相邻节点加入队列*/
                for(int j=0;j<4;j++){
                    string up=plusOne(cur,j);
                    if(!visited.count(up)){
                        q.push(up);
                        visited.insert(up);
                    }
                    string down=minusOne(cur,j);
                    if(!visited.count(down)){
                        q.push(down);
                        visited.insert(down);
                    }
                }
            }
            step++;
        }
        return -1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["0201","0101","0102","1212","2002"]\n"0202"\n
// @lcpr case=end

// @lcpr case=start
// ["8888"]\n"0009"\n
// @lcpr case=end

// @lcpr case=start
// ["8887","8889","8878","8898","8788","8988","7888","9888"]\n"8888"\n
// @lcpr case=end

 */

