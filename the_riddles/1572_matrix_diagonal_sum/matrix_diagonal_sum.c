// problem : https://leetcode.com/problems/matrix-diagonal-sum
// time complexity  -> O(N)
// space complexity -> O(1)
int diagonalSum(int** mat, int matSize, int* matColSize) {
  int diagonal_sum = 0;

  for (int m = 0, n = matSize-1; m < matSize; m++, n--) {
    // calulate the primary diagonal sum
    diagonal_sum += mat[m][m];

    // calculate the secondary diagonal sum
    diagonal_sum += mat[m][n];
  }

  // if the length of matrix is odd, then the middle
  // diagonal element is added twice. substract it out
  if (matSize % 2) diagonal_sum -= mat[matSize/2][matSize/2];

  return diagonal_sum;    
}
