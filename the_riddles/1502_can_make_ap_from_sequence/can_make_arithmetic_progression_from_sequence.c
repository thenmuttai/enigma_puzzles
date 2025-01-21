// problem: 
// time complexity  -> O(N)
// space complexity -> O(1)
int cmp(void const *a ,void const *b){
    int * x = (int * )a;
    int * y = (int *) b;
    return *x -*y ;
    }

bool canMakeArithmeticProgression(int* arr, int arrSize) {
  // sort the array
  qsort(arr, arrSize, sizeof(int), cmp);

  // get the difference b/w first two elements
  int diff = arr[1] - arr[0];

  // calcualte the diff and it varies, then it's not a AP
  for (int i = 2; i < arrSize; i++) {
    if ((arr[i] - arr[i -1]) != diff) return false;
  }

  return true;
}
