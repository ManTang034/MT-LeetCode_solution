/*
 * @lc app=leetcode.cn id=990 lang=cpp
 * @lcpr version=30111
 *
 * [990] 等式方程的可满足性
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
    bool equationsPossible(vector<string>& equations) {
        UF uf(26);
        for(string eq:equations){
            if(eq[1]=='='){
                char x=eq[0];
                char y=eq[3];
                uf._union(x-'a',y-'a');
            }
        }
        for(string eq:equations){
            if(eq[1]=='!'){
                char x=eq[0];
                char y=eq[3];
                if(uf.isConnected(x-'a',y-'a')){
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// b"\na"]\n
// @lcpr case=end

// @lcpr case=start
// a"\nb"]\n
// @lcpr case=end

// @lcpr case=start
// b"\nc"\nc"]\n
// @lcpr case=end

// @lcpr case=start
// b"\nc"\na"]\n
// @lcpr case=end

// @lcpr case=start
// c"\nd"\nz"]\n
// @lcpr case=end

 */

