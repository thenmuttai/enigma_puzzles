// problem : https://leetcode.com/problems/length-of-last-word
// time complexity  -> O(N)   ; N is the size of string
// space complexity -> O(1)
int lengthOfLastWord(char* s) {
  int wrd_len = 0, prev_wrd_len = 0;

   while (*s != '\0') {
    // it may be a start of new word or end of a word
    if (*s == ' ') {
      if (wrd_len) prev_wrd_len = wrd_len;
      wrd_len = 0;
    }
    else 
      wrd_len++;

    s++;
  }

  // if the sentence don't end with blank space, then
  // wrd_len will have the last word length else
  // prev_wrd_len will have the last word length
  return (wrd_len != 0 ? wrd_len : prev_wrd_len);
}
