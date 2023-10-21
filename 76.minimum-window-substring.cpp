/*
 * @lc app=leetcode.cn id=76 lang=cpp
 * @lcpr version=30102
 *
 * [76] 最小覆盖子串
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
    string minWindow(string s, string t) {
        unordered_map<char,int>need,window;
        for(char c:t){
            need[c]++;
        }

        int left=0,right=0;
        int valid=0;
        //记录最小覆盖子串的起始索引及长度
        int start=0,len=INT_MAX;
        while(right<s.size()){
            //c移入窗口的字符
            char c=s[right];
            //扩大窗口
            right++;
            //进行窗口内数据的一系列更新
            if(need.count(c)){
                window[c]++;
                if(window[c]==need[c]){
                    valid++;
                }
            }

            //判断左侧窗口是否要收缩
            while(valid==need.size()){
                //更新最小覆盖子串
                if(right-left<len){
                    start=left;
                    len=right-left;
                }
                //d移出窗口的字符
                char d=s[left];
                //缩小窗口
                left++;
                //进行窗口内数据的一系列更新
                if(need.count(d)){
                    if(window[d]==need[d]){
                        valid--;
                    }
                    window[d]--;
                }
            }
        }
        return len==INT_MAX ? "":s.substr(start,len);
    }
};
// @lc code=end



/*
// @lcpr case=start
// "ADOBECODEBANC"\n"ABC"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n"a"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n"aa"\n
// @lcpr case=end

 */

