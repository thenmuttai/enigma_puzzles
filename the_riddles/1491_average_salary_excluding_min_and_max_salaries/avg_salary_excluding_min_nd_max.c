// problem : https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary
// time complexity  -> O(N)
// space complexity -> O(1)
double average(int* salary, int salarySize) {
  double avg = salary[0];
  int max = salary[0], min = salary[0];

  for (int i = 1; i < salarySize; i++) {
    // if value is smaller, then update the min
    if (salary[i] < min) min = salary[i];

    // if value is larger, then update the max
    if (salary[i] > max) max = salary[i];

    avg += salary[i];
  }

  avg -= (min + max);

  return avg / (salarySize -2);
}
