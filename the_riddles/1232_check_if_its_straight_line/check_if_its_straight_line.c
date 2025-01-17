// problem : https://leetcode.com/problems/check-if-it-is-a-straight-line
// time complexity  -> O(N)
// space complexity -> O(1)
bool checkStraightLine(int** coordinates, int coordinatesSize, int* coordinatesColSize) {
  // only two points given
  if (coordinatesSize == 2) return true;

  // slope m = dy / dx
  // dy = y1 - y0,  dx = x1 - x0
  int dy = coordinates[1][1] - coordinates[0][1];
  int dx = coordinates[1][0] - coordinates[0][0];

  // for a line to be a stright line, slope b/w first two points should
  // match with the slope of all other points
  // y - y0 / x - x0 = dy / dx
  // dx (y - y0) = dy (x - x0)
  for (int coord = 2; coord < coordinatesSize; coord++) {
    int lhs = dx * (coordinates[coord][1] - coordinates[0][1]);
    int rhs = dy * (coordinates[coord][0] - coordinates[0][0]);

    if (lhs != rhs) return false;
  }

  return true;
}
