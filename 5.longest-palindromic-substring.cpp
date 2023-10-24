/*
 * @lc app=leetcode.cn id=5 lang=cpp
 * @lcpr version=30102
 *
 * [5] 最长回文子串
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
class Solution
{
public:
    /*如果回文串的长度为奇数，则它有一个中心字符；如果回文串的长度为偶数，则有两个中心字符，解决该问题的核心是从中心向两端扩散的双指针技巧*/
    string longestPalindrome(string s)
    {
        string res = "";
        for (int i = 0; i < s.size(); i++)
        {
            // 以s[i]为中心的最长回文子串
            string s1 = palindrome(s, i, i);
            // 以s[i]和s[i+1]为中心的最长回文子串
            string s2 = palindrome(s, i, i + 1);
            res = res.size() > s1.size() ? res : s1;
            res = res.size() > s2.size() ? res : s2;
        }
        return res;
    }

    // 在s中寻找以s[l]和s[r]为中心的最长回文串
    string palindrome(string s, int l, int r)
    {
        // 防止索引越界
        while (l >= 0 && r < s.size() && s[l] == s[r])
        {
            // 双指针，向两边展开
            l--;
            r++;
        }
        return s.substr(l + 1, r - l - 1);
    }
};
// @lc code=end

/*
// @lcpr case=start
// "babad"\n
// @lcpr case=end

// @lcpr case=start
// "cbbd"\n
// @lcpr case=end

 */
