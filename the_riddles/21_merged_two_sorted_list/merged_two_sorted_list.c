// problem : https://leetcode.com/problems/merge-two-sorted-lists/
// time complexitiy  -> O(N + M)   ; N - size of list1, M - size of list2
// space complexity ->O(1)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
  // ListNode's head which holds the merged sorted linked list
  struct ListNode *res = malloc(sizeof(struct ListNode));
  res->next = NULL;

  // reference to denote the head of res ListNode
  struct ListNode *head = res;

  while (list1 && list2) {
    // if one node's value is smaller than other node list, make the 
    // node to tbe the part of the res and update the 'res' reference
    // to point to the next node

    if (list1->val < list2->val) {
      res->next = list1;
      list1 = list1->next;
    }
    else {
      res->next = list2;
      list2 = list2->next;
    }
    res = res->next;
  }

  // if there were any left over elements, then append it to
  // the final LinkedList 'res'
  if (list1)
    res->next = list1;
  else
    res->next = list2;

  return head->next;
}
