// Source : https://leetcode.com/problems/remove-nth-node-from-end-of-list
// Author : xjliang
// Date   : 2021-02-12

/***************************************************************************************************** 
 *
 * Given the head of a linked list, remove the nth node from the end of the list and return its head.
 * 
 * Follow up: Could you do this in one pass?
 * 
 * Example 1:
 * 
 * Input: head = [1,2,3,4,5], n = 2
 * Output: [1,2,3,5]
 * 
 * Example 2:
 * 
 * Input: head = [1], n = 1
 * Output: []
 * 
 * Example 3:
 * 
 * Input: head = [1,2], n = 1
 * Output: [1]
 * 
 * Constraints:
 * 
 * 	The number of nodes in the list is sz.
 * 	1 <= sz <= 30
 * 	0 <= Node.val <= 100
 * 	1 <= n <= sz
 ******************************************************************************************************/

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
    ListNode dummy_head(-1, head);
    ListNode* fast = &dummy_head;
    ListNode* slow = &dummy_head;
    int count = 0;
    while (count < n + 1) {
      fast = fast->next;
      count++;
    }
    while (fast) {
      fast = fast->next;
      slow = slow->next;
    }
    slow->next = slow->next->next;
    return dummy_head.next;
  }
};
