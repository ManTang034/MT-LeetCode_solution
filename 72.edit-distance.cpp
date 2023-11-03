/*
 * @lc app=leetcode.cn id=72 lang=cpp
 * @lcpr version=30102
 *
 * [72] 编辑距离
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
private:
    //备忘录
    vector<vector<int>>memo;
    int dp(string s1,int i,string s2,int j){
        //base case
        if(i==-1) return j+1;
        if(j==-1) return i+1;
        //查备忘录，避免重复子问题
        if(memo[i][j]!=-1){
            return memo[i][j];
        }
        //状态转移，结果存入备忘录
        if(s1[i]==s2[j]){
            memo[i][j]=dp(s1,i-1,s2,j-1);
        }else{
            memo[i][j]=Min(
                dp(s1,i-1,s2,j)+1,
                dp(s1,i,s2,j-1)+1,
                dp(s1,i-1,s2,j-1)+1
            );
        }
        return memo[i][j];
    }
public:
    int minDistance(string word1, string word2) {
        int m=word1.length(),n=word2.length();
        //初始化备忘录
        memo=vector<vector<int>>(m,vector<int>(n,-1));
        return dp(word1,m-1,word2,n-1);
    }
    
    int Min(int a,int b,int c){
        return min(min(a,b),c);
    }
};
// @lc code=end



/*
// @lcpr case=start
// "horse"\n"ros"\n
// @lcpr case=end

// @lcpr case=start
// "intention"\n"execution"\n
// @lcpr case=end

 */

