// problem: https://leetcode.com/problems/add-two-numbers-ii/
// time complexity  -> O(N + M)
// space complexity -> O(N + M)
#define STACK_SIZE  100

typedef struct {
  int *items;
  int top;
} stack;

stack* stack_init(int size) {
  stack *s = malloc(sizeof(stack));
  s->items = malloc(size * sizeof(int));
  s->top = -1;
  return s;
}

bool is_stack_empty(stack *s) {
  return (s->top == -1);
}

bool spush(stack *s, int element) {
  s->top++;
  s->items[s->top] = element;
  return true;
}

int spop(stack *s) {
  return s->items[s->top--];
}

struct ListNode* node_init() {
  struct ListNode *ll = malloc(sizeof(struct ListNode));
  ll->val = 0;
  ll->next = NULL;

  return ll;
}


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
  // two stacks to hold the elements of each lists
  stack *sl1 = stack_init(STACK_SIZE);
  stack *sl2 = stack_init(STACK_SIZE);

  // copying the elements into stacks
  while (l1 != NULL || l2 != NULL) {
    if (l1 != NULL) {
      spush(sl1, l1->val);
      l1 = l1->next;
    }

    if (l2 != NULL) {
      spush(sl2, l2->val);
      l2 = l2->next;
    }
  }

  // generate a new linked list to hold the results
  struct ListNode *res = node_init();
  int carry = 0;

  while (!is_stack_empty(sl1) || !is_stack_empty(sl2) || carry) {
    int sum = 0;

    if (!is_stack_empty(sl1)) sum += spop(sl1);
    if (!is_stack_empty(sl2)) sum += spop(sl2);

    if (carry) {
      sum += carry;
      carry = 0;
    }

    carry = sum / 10;
    sum %= 10;      

    res->val = sum;

    // if sum are appened one after another then the addition value is reversed
    // so we need to keep track of head and always insert the element before the current
    if (!is_stack_empty(sl1) || !is_stack_empty(sl2) || carry) {
      struct ListNode *n = node_init();
      n->next = res;
      res = n;
    }
  }

  return res;    
}
