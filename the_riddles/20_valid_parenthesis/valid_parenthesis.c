// problem : https://leetcode.com/problems/valid-parentheses
// time complexity  -> O(N)
// space complexity -> O(1)
typedef struct {
  char *items;
  int top;
} stack;

stack* stack_init(int size) {
  stack *s = malloc(sizeof(stack));
  s->items = malloc(size * sizeof(char));
  s->top = -1;
  return s;
}

bool is_stack_empty(stack *s) {
  return (s->top == -1);
}

bool spush(stack *s, char element) {
  s->top++;
  s->items[s->top] = element;
  return true;
}

char spop(stack *s) {
  if (is_stack_empty(s)) return ' ';

  return s->items[s->top--];
}



// PROBLEM 
bool isValid(char* s) {
  int size_of_stack = strlen(s);

  // create a new stack
  stack *ss = stack_init(size_of_stack);

  for (int i = 0; i < size_of_stack; i++) {
    // if it was opening parentheses, then add it to the stack
    if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
      spush(ss, s[i]);
      continue;
    }

    // if it was closing parentheses, pop the last element form stack
    // the poped element should be the pair of the current parentheses
    char open = spop(ss);

    if (s[i] == ')' && open != '(') return false;
    if (s[i] == ']' && open != '[') return false;
    if (s[i] == '}' && open != '{') return false;
  }

  // at the end, the stack must be empty
  if (!is_stack_empty(ss)) return false;

  return true;    
}
