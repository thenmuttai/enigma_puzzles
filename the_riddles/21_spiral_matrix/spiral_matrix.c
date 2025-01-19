// problem: 
// time complexity  -> O(M * N)
// space complexity -> O(M * N)
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
  // initialize a 1D array to hold all elements of matrix 2D array
  *returnSize = matrixSize * (*matrixColSize);
  int *res = malloc((*returnSize) * sizeof(int));

  // initialize boundry variables
  int left_b = 0, right_b = *matrixColSize - 1;
  int top_b = 0, bottom_b = matrixSize - 1;

  int rlen = 0;
  while (rlen < (*returnSize)) {
    // top horizontal (row - top_b, col - left to right)
    for (int col = left_b; col <= right_b; col++) 
      res[rlen++] = matrix[top_b][col];

    top_b++;   // shrink the top

    // right vertical (row - right_b, col - top to bottom)
    for (int row = top_b; row <= bottom_b; row++)
      res[rlen++] = matrix[row][right_b];
    
    right_b--;   // shrink the right

    // check if the rlen has crossed the limit and break out
    if (rlen >= (*returnSize)) break;

    // bottom horizontal (row - bottom_b, col - right to left)
    for (int col = right_b; col >= left_b; col--)
      res[rlen++] = matrix[bottom_b][col];
    
    bottom_b--;   // shrink the bottom

    // left vertical (row - bottom to top, col - left_b)
    for (int row = bottom_b; row >= top_b; row--)
      res[rlen++] = matrix[row][left_b];
    
    left_b++;   // shrink the left
  }

  return res;
}
