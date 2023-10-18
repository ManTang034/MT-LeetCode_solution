/*
 * @lc app=leetcode.cn id=86 lang=cpp
 * @lcpr version=30102
 *
 * [86] 分隔链表
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
    ListNode *partition(ListNode *head, int x)
    {
        // 存放小于x的链表的虚拟头节点
        ListNode *dummy1 = new ListNode(-1), *p1 = dummy1;
        // 存放大于等于x的链表的虚拟头节点
        ListNode *dummy2 = new ListNode(-1), *p2 = dummy2;
        // p负责遍历原链表
        ListNode *p = head;
        while (p != nullptr)
        {
            if (p->val >= x)
            {
                p2->next = p;
                p2 = p2->next;
            }
            else
            {
                p1->next = p;
                p1 = p1->next;
            }
            // 不能直接让p指针前进，断开原链表中每个节点的next指针
            ListNode *tmp = p->next;
            p->next = nullptr;
            p = tmp;
        }
        // 连接两个链表
        p1->next = dummy2->next;
        return dummy1->next;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,4,3,2,5,2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [2,1]\n2\n
// @lcpr case=end

 */
