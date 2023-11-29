/*
 * @lc app=leetcode.cn id=207 lang=cpp
 * @lcpr version=30111
 *
 * [207] 课程表
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
    //记录一次递归堆栈中的节点
    vector<bool>onPath;
    //记录遍历过的节点，防止走回头路
    vector<bool>visited;
    //记录图中是否有环
    bool hasCycle=false;

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //建图，有向边代表被依赖关系
        vector<list<int>>graph=buildGraph(numCourses,prerequisites);
        //构建入度数组
        vector<int>indegree(numCourses,0);
        for(auto edge:prerequisites){
            int from=edge[1],to=edge[0];
            //节点to的入度加一
            indegree[to]++;
        }

        //根据入度初始化队列中的节点
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                //节点i没有入度，即没有依赖的节点
                //可以作为拓扑排序的起点，加入队列
                q.push(i);
            }
        }

        //记录遍历的节点个数
        int count=0;
        //开始执行BFS循环
        while(!q.empty()){
            //弹出节点cur，并将它指向的节点的入度减一
            int cur=q.front();
            q.pop();
            count++;
            for(int next:graph[cur]){
                indegree[next]--;
                if(indegree[next]==0){
                    //如果入度变为0，说明next依赖的节点都已被遍历
                    q.push(next);
                }
            }
        }

        //如果所有节点都被遍历过，说明不成环
        return count==numCourses;
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
// 2\n[[1,0],[0,1]]\n
// @lcpr case=end

 */

