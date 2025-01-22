// problem: https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
// time complexity  -> O(N)
// space complexity -> O(N)
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
  if (is_stack_empty(s)) return 0;
  return s->items[s->top--];
}

int evaluate(char oper, int operand1, int operand2) {
  switch (oper) {
    case '+': return (operand1 + operand2);
    case '-': return (operand1 - operand2);
    case '*': return (operand1 * operand2);
    case '/': return (operand1 / operand2);
    default: return 1;
  }
}


// PROBLEM
int evalRPN(char** tokens, int tokensSize) {
  stack *s = stack_init(tokensSize);   // stack to hold the operands

  for (int i = 0; i < tokensSize; i++) {
    // check if the token is an operator or an operand
    if (strcmp(tokens[i], "+") == 0 || strcmp(tokens[i], "-") == 0 || strcmp(tokens[i], "*") == 0 || strcmp(tokens[i], "/") == 0) {
      // it's an operator
      int operand2 = spop(s);
      int operand1 = spop(s);
      int res = evaluate(tokens[i][0], operand1, operand2);
      spush(s, res);
    }
    else {
      // it's an operand
      spush(s, atoi(tokens[i]));
    }
  }

  int result = spop(s);
  free(s->items);
  free(s);
  return result;    
}
