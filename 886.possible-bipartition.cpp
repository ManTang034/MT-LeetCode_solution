/*
 * @lc app=leetcode.cn id=886 lang=cpp
 * @lcpr version=30111
 *
 * [886] 可能的二分法
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
    bool ok=true;
    vector<bool>color;
    vector<bool>visited;

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        //图的节点编号从1开始
        color.resize(n+1);
        visited.resize(n+1);
        //转化成邻接表表示图结构
        vector<vector<int>>graph=buildGraph(n,dislikes);

        for(int v=1;v<=n;v++){
            if(!visited[v]){
                traverse(graph,v);
            }
        }
        return ok;
    }

    //建图函数
    vector<vector<int>>buildGraph(int n,vector<vector<int>>&dislikes){
        //图的节点编号为1..n
        vector<vector<int>>graph(n+1);
        for(int i=1;i<=n;i++){
            graph[i]={};
        }
        for(auto edge:dislikes){
            int v=edge[1];
            int w=edge[0];
            //无向图相当于双向图
            graph[v].push_back(w);
            graph[w].push_back(v);
        }
        return graph;
    }

    void traverse(vector<vector<int>>&graph,int v){
        if(!ok) return;
        visited[v]=true;
        for(int w:graph[v]){
            if(!visited[w]){
                color[w]=!color[v];
                traverse(graph,w);
            }else{
                if(color[w]==color[v]){
                    ok=false;
                    return;
                }
            }
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// 4\n[[1,2],[1,3],[2,4]]\n
// @lcpr case=end

// @lcpr case=start
// 3\n[[1,2],[1,3],[2,3]]\n
// @lcpr case=end

// @lcpr case=start
// 5\n[[1,2],[2,3],[3,4],[4,5],[1,5]]\n
// @lcpr case=end

 */

