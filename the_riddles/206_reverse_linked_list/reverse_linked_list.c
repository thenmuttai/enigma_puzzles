// problem:
// time complexity  -> O(N)
// space complexity -> O(1)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
  struct ListNode *curr = head;

  struct ListNode *curr_nxt_mem = NULL, *nxt;

  while (curr) {
    // record the next node's address
    nxt = curr->next;

    // reverse the current node's next address
    curr->next = curr_nxt_mem;

    // get location of curr node to update the next node's next member    
    curr_nxt_mem = curr;

    // update Node to continue the iteration
    curr = nxt;
  }

  return curr_nxt_mem;
}
