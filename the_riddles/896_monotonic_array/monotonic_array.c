// problem: https://leetcode.com/problems/monotonic-array/
// time complexity  -> O(N)
// space complexity -> O(1)
bool isMonotonic(int* nums, int numsSize) {
  if (numsSize == 1) return true;

  // check if the initial value is increasing or decreasing
  bool is_increasing;

  // this loop helps to move the pointer until the elements
  // are not equal and check increasing or decreasing
  for (int idx = 1; idx < numsSize; idx++) {
    if (nums[idx - 1] != nums[idx]) {
      is_increasing = nums[idx - 1] <= nums[idx];
      break;
    }
  }

  // validate entire array elements are increasing or decreasing
  if (is_increasing) {
    for (int i = 2; i < numsSize; i++) {
      if (nums[i - 1] > nums[i]) return false;
    }
  }
  else {
    for (int i = 2; i < numsSize; i++) {
      if (nums[i - 1] < nums[i]) return false;
    }
  }

  return true;
}
