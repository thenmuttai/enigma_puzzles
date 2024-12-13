// problem: https://leetcode.com/problems/valid-anagram/
// time complexity  -> O(N)   ; N - len of string s
// space complexity -> O(1)
bool isAnagram(char* s, char* t) {
  int freq[26] = {0};

  // if char s and t are not of same length
  if (strlen(s) != strlen(t)) return false;

  // increse the frequencies for s and decrease it for t
  for (int i = 0; i < strlen(s); i++) {
    freq[s[i] - 'a']++;
    freq[t[i] - 'a']--;
  }

  // check if all values are zero
  for (int i = 0; i < 26; i++) {
    if (freq[i] != 0) return false;
  }

  return true;    
}
