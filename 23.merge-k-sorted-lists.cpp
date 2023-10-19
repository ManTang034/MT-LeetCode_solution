/*
 * @lc app=leetcode.cn id=23 lang=cpp
 * @lcpr version=30102
 *
 * [23] 合并 K 个升序链表
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
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.empty())
            return nullptr;
        // 虚拟头节点
        ListNode *dummy = new ListNode(-1), *p = dummy;
        // 优先级队列，最小堆
        priority_queue<ListNode *, vector<ListNode *>, function<bool(ListNode *, ListNode *)>> pq(
            [](ListNode *a, ListNode *b)
            { return a->val > b->val; });
        //将k个链表的头节点加入最小堆
        for(auto head:lists){
            if(head!=nullptr){
                pq.push(head);
            }
        }
        while(!pq.empty()){
            //获取最小节点，接到结果链表中
            ListNode*node=pq.top();
            pq.pop();
            p->next=node;
            if(node->next!=nullptr){
                pq.push(node->next);
            }
            //p指针不断前进
            p=p->next;
        }
        return dummy->next;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[1,4,5],[1,3,4],[2,6]]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [[]]\n
// @lcpr case=end

 */
