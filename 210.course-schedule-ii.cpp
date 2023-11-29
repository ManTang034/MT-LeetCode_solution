/*
 * @lc app=leetcode.cn id=210 lang=cpp
 * @lcpr version=30111
 *
 * [210] 课程表 II
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
    //记录后序遍历结果
    vector<int>postorder;
    //记录是否存在环
    bool hasCycle=false;
    vector<bool>visited,onPath;

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<list<int>>graph=buildGraph(numCourses,prerequisites);
        visited=vector<bool>(numCourses,false);
        onPath=vector<bool>(numCourses,false);
        //遍历图
        for(int i=0;i<numCourses;i++){
            traverse(graph,i);
        }
        //有环图无法进行拓扑排序
        if(hasCycle){
            return{};
        }
        //逆后序遍历结果即为拓扑排序结果
        reverse(postorder.begin(),postorder.end());
        return postorder;
    }

    //图遍历函数
    void traverse(vector<list<int>>&graph, int s){
        if(onPath[s]){
            //发现环
            hasCycle=true;
        }
        if(visited[s]||hasCycle){
            return;
        }
        onPath[s]=true;
        visited[s]=true;
        for(int t:graph[s]){
            traverse(graph,t);
        }
        postorder.push_back(s);
        onPath[s]=false;
    }

    vector<list<int>>buildGraph(int numCourses,vector<vector<int>>& prerequisites){
        //图中共有numsCourses个节点
         vector<list<int>>graph(numCourses);
        for(int i=0;i<numCourses;i++){
            graph[i]=list<int>();
        }
        for(auto&edge:prerequisites){
            int from=edge[1],to=edge[0];
            graph[from].push_back(to);
        }
        return graph;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n[[1,0]]\n
// @lcpr case=end

// @lcpr case=start
// 4\n[[1,0],[2,0],[3,1],[3,2]]\n
// @lcpr case=end

// @lcpr case=start
// 1\n[]\n
// @lcpr case=end

 */

