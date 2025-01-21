// problem: https://leetcode.com/problems/roman-to-integer/
// time complexity  -> O(N)
// space complexity -> O(1)
int get_decimal(char sym) {
  switch (sym) {
    case 'I': return 1;
    case 'V': return 5;
    case 'X': return 10;
    case 'L': return 50;
    case 'C': return 100;
    case 'D': return 500;
    case 'M': return 1000;
    default: return 0;
  }
}



int romanToInt(char* s) {
  int val = 0;

  for (int i = 0; i < strlen(s); i++) {
    int curr = get_decimal(s[i]);
    int nxt = get_decimal(s[i + 1]);

    // roman system follows increment of values from RHS -> LHS
    // if symbols value is lower, then substract it

    // if the current value is less than the next value, the
    // need to substract it out else increment the val

    if (curr < nxt) val -= curr;
    else val += curr;
  }

  return val;
}
