// problem : 
// time complexity  -> O(N log(N))    ; complexity for sorting
// space complexity -> O(1)
int comp(const void* a,const void* b) {
      return *(int*)a - *(int*)b;
}

int largestPerimeter(int* nums, int numsSize) {
  int max_perimeter = 0;

  // sort the array
  qsort(nums, numsSize, sizeof(int), comp);

  for (int i = 2; i < numsSize; i++) {
    // check if the pair form a triange, if so then update the perimeter
    if (nums[i-2] + nums[i-1] > nums[i])
      max_perimeter = nums[i-2] + nums[i-1] + nums[i];
  }
  return max_perimeter;    
}
