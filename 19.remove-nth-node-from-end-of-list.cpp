/*
 * @lc app=leetcode.cn id=19 lang=cpp
 * @lcpr version=30102
 *
 * [19] 删除链表的倒数第 N 个结点
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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*p1=head;
        ListNode*p2=head;
        for(int i=0;i<n;i++){
            p1=p1->next;
        }
        //判断p1移动n步是不是为空
        if(!p1){
            //如果p1已经到达尾节点，则删除的是头节点
            head=head->next;
            return head;
        }
        while(p1->next){
            p1=p1->next;
            p2=p2->next;
        }
        p2->next=p2->next->next;
        return head;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n1\n
// @lcpr case=end

 */

