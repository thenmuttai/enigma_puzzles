// problem: https://leetcode.com/problems/to-lower-case
// time complexity  -> O(N)
// space complexity -> O(1)
char* toLowerCase(char* s) {
  int diff = 'a' - 'A';

  for (int i = 0; i < strlen(s); i++) {
    // check if the letter is a upper case
    if (s[i] >= 'A' && s[i] <= 'Z')
      s[i] += diff;
  }

  return s;
}
