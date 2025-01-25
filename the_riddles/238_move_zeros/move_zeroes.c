// problem: https://leetcode.com/problems/move-zeroes/description
// time complexity  -> O(N)
// space complexity -> O(1)
void moveZeroes(int* nums, int numsSize) {
  int zero_ptr = 0;

  for (int i = 0; i < numsSize; i++) {
    if (nums[i] != 0) {
      // swap the elements with non_zero index at the nums array
      int tmp = nums[i];
      nums[i] = nums[zero_ptr];
      nums[zero_ptr] = tmp;

      zero_ptr++;
    }
  }
}
