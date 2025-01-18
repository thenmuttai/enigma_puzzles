// problem: https://leetcode.com/problems/robot-return-to-origin
// time complexity  -> O(N)
// space complexity -> O(1)
bool judgeCircle(char* moves) {
  int vertical = 0, horizontal = 0;

  for (int i = 0; i < strlen(moves); i++) {
    if (moves[i] == 'U') vertical++;
    else if (moves[i] == 'D') vertical--;
    else if (moves[i] == 'R') horizontal++;
    else if (moves[i] == 'L') horizontal--;
  }

  return (vertical == 0 && horizontal == 0);    
}
