// problem : https://leetcode.com/problems/lemonade-change/
// time complexity  -> O(N)
// space complexity -> O(1)
bool lemonadeChange(int* bills, int billsSize) {
  int bill5 = 0, bill10 = 0;

  for (int queue = 0; queue < billsSize; queue++) {
    if (bills[queue] == 5) bill5++;
    else if (bills[queue] == 10) {
      bill5--;
      bill10++;
    }
    else if (bills[queue] == 20) {
      if (bill10) {
        bill10--;
        bill5--;
      }
      else
        bill5 -= 3;
    }

    // if any bill count get lower than 0, then we are
    // out of bills to return the balance amount
    if (bill5 < 0 || bill10 < 0) return false;
  }

  return true;    
}
