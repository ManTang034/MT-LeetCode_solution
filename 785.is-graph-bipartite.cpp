/*
 * @lc app=leetcode.cn id=785 lang=cpp
 * @lcpr version=30111
 *
 * [785] 判断二分图
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
    //记录图是否符合二分图性质
    bool ok=true;
    //记录图中节点的颜色，false和true代表两种不同颜色
    vector<bool>color;
    //记录图中节点是否被访问过
    vector<bool>visited;

    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        color.resize(n);
        visited.resize(n);
        //因为图不一定是联通的，可能存在多个子图
        //所以要把每个节点都作为起点进行一次遍历
        //如果发现任何一个子图不是二分图，整幅图都不算是二分图
        for(int v=0;v<n;v++){
            if(!visited[v]){
                traverse(graph,v);
            }
        }
        return ok;
    }

    //DFS遍历框架
    void traverse(vector<vector<int>>&graph,int v){
        //如果已经确定不是二分图，直接结束
        if(!ok) return;

        visited[v]=true;
        for(int w:graph[v]){
            if(!visited[w]){
                //相邻节点w没有被访问过
                //那么应该给节点w涂上和节点v不同的颜色
                color[w]=!color[v];
                //继续遍历w
                traverse(graph,w);
            }else{
                //相邻节点w已经被访问过
                //根据节点v和w的颜色判断是否是二分图
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
// [[1,2,3],[0,2],[0,1,3],[0,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,3],[0,2],[1,3],[0,2]]\n
// @lcpr case=end

 */

