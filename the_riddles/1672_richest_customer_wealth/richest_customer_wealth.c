// problem : https://leetcode.com/problems/richest-customer-wealth
// time complexity  -> O(N)
// space complexity -> O(1)
int maximumWealth(int** accounts, int accountsSize, int* accountsColSize) {
  int max_wealth = 0;

  for (int account = 0; account < accountsSize; account++) {
    int tmp_wealth = 0;

    // summing up all the money for a customer from all the banks
    for (int bank = 0; bank < *accountsColSize; bank++)
      tmp_wealth += accounts[account][bank];
    
    max_wealth = tmp_wealth > max_wealth ? tmp_wealth : max_wealth;
  }

  return max_wealth;    
}
