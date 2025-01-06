// problem: https://leetcode.com/problems/add-two-numbers
// time complexity  -> O(N + M)         ; N, M - no of nodes in both the numbers
// space complexity -> O( max(M, N) )   ; Max no of nodes of either M or N
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
  struct ListNode *head = malloc(sizeof(struct ListNode));
  struct ListNode *node = head;
  int carry = 0;

  while (l1 || l2 || carry) {
    int sum = 0;

    if (l1) {
      sum += l1->val;
      l1 = l1->next;
    }

    if (l2) {
      sum += l2->val;
      l2 = l2->next;
    }

    // check if we have a carry
    if (carry) {
      sum += carry;
      carry = 0;
    }

    // split the sum, if it's a two digit number
    if (sum > 9) {
      carry = sum / 10;
      sum %= 10;
    }

    // create a node and chaining it
    node->val = sum;
    node->next = NULL;
    
    // if there are left over node or carry, then creat a new
    // node and chain it
    if (l1 || l2 || carry) {
      struct ListNode *new_node = malloc(sizeof(struct ListNode));
      node->next = new_node;
    }

    node = node->next;
  }

  return head;    
}
