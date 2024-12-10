// problem: https://leetcode.com/problems/find-the-difference/
// time complexity  -> O(M + N)      ; M, N - length of string s and t respectively
// space complecity -> O(1)

char findTheDifference(char* s, char* t) {
  // int array to keep track of letters freq in word
  int sfreq[26] = {0};
  int tfreq[26] = {0};

  // update the frequency
  while (*s || *t) {
    if (*s) {
      sfreq[*s - 'a'] += 1;
      s++;
    }

    if (*t) {
      tfreq[*t  - 'a'] += 1;
      t++;
    }
  }

  // finding the odd letter out
  for (int alp = 0; alp < 26; alp++) {
    if (sfreq[alp] != tfreq[alp]) 
      return 'a' + alp;
  }
}


// Simpler Approach (but same time and space complexity)
char findTheDifference(char* s, char* t) {
  int odd_one = 0;

  while (*s || *t) {
    odd_one += *t;
    t++;

    // this condition is to prevent overflow condition
    // where len of t is always 1 + len(s)
    if (*s) {
      odd_one -= *s;
      s++;
    }
  }
  return odd_one;
}
