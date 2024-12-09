// problem: https://leetcode.com/problems/merge-strings-alternately/description/
// time complexity  -> O(M + N)       ; M - len of word1, N - len of word2
// space complexity -> O(M + N)

char * mergeAlternately(char * word1, char * word2){
  int w1_len = strlen(word1);
  int w2_len = strlen(word2);

  // memory allocation of merged string (+1 for null character)
  char *merged = malloc( (w1_len + w2_len + 1) * sizeof(char));
  int mer_idx = 0, idx1 = 0, idx2 = 0;

  // combain string alternatively
  while (idx1 < w1_len || idx2 < w2_len) {
    if (idx1 < w1_len)
      merged[mer_idx++] = word1[idx1++];
    if (idx2 < w2_len)
      merged[mer_idx++] = word2[idx2++];
  }

  // adding the null character
  merged[mer_idx] = '\0';

  return merged;
}
