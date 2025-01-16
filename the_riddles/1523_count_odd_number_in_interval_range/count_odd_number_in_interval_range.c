// problem: https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/
// time complexity  -> O(1)
// space complexity -> O(1)
int countOdds(int low, int high) {
  int range = high - low + 1;

  // if range is even, then no of even numbers == no of odd numbers
  // if range is odd, then solution depents on parity of high and low
  //                   ie. either it's odd or even

  // if range is odd and both high & low are odd parity
  if ((range % 2) && (high % 2) && (low % 2))
    return (range / 2) + 1;
  
  return range / 2;
}
