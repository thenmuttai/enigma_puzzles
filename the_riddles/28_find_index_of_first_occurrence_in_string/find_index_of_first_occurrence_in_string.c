// problem: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
// time complexity  -> O(M * N)    ; M, N - length of haystack and needle respectively
// space complecity -> O(1)
int strStr(char* haystack, char* needle) {
  // pointer-pointer arithments works only if both points to same array
  // so we are creating temprory pointer to haystact and needle
  char *hay = haystack;
  char *nee = needle;

  while (*hay) {
    if (*hay == *nee) {
      // update the needle and haystack
      hay++;
      nee++;

      // if end of needle is reached, then we got a match
      // so return the index of start using the pointer-pointer arithmetics
      if (!*nee) return hay - strlen(needle) - haystack;

      continue;
    }

    // if 'nee' is moved, then 'hay' should also moves. Reset the positions
    if ((nee - needle) != 0) {
      // reset 'hay' back to the current positon of 'nee'
      hay -= (nee - needle);

      // reset the 'nee' back to start
      nee = needle;
    }

    hay++;
  }

  return -1; 
}
