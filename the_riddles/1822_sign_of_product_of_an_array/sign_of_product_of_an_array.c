// problem: https://leetcode.com/problems/sign-of-the-product-of-an-array/
// time complexity  ->
// space complexity ->
int arraySign(int* nums, int numsSize) {
  int neg_val = 1;

  for (int i = 0; i < numsSize; i++) {
    if (nums[i] == 0) return 0;
    if (nums[i] < 0) neg_val *= -1;
  }

  return neg_val;    
}
