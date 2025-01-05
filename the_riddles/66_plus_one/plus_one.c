// problem: https://leetcode.com/problems/plus-one
// time complexity  -> O(N)    ; if we need to increment all the digits of the array
// space complexity -> O(N)    ; if we create a new array with larger size
int* plusOne(int* digits, int digitsSize, int* returnSize) {
  *returnSize = digitsSize;

  // if there were no carry (means last digit is not 9)
  if (digits[digitsSize - 1] != 9) {
    // increment the last digit by 1 and return
    digits[digitsSize - 1]++;
    return digits;
  }

  // if last digit is 9 (chances are larger size array is needed
  // or need to increment multiple digits due to presence of carry)
  int carry = 1;

  for (int idx = digitsSize-1; idx >= 0; idx--) {
    if (digits[idx] == 9 && carry == 1)
      digits[idx] = 0;

    else if (carry == 1) {
      digits[idx]++;
      carry = 0;
    }
  }

  // if carry is not 1, then multiple digits are incremented but no
  // need for larger size array
  if (carry == 0) return digits;

  // else, we need a array of one size larger than digits array
  int *res = malloc((digitsSize + 1) * sizeof(int));

  // copy the contents of digits array into res array starting from position 1
  // since position 0 of res array is to place the carry
  memcpy(res + 1, digits, sizeof(int) * digitsSize);

  // update the initial positon of res array
  res[0] = 1;

  *returnSize = digitsSize + 1;
  return res;
}
