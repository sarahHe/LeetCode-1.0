vector<int> twoSum(vector<int> &numbers, int target) {
  vector<int> res;
  int l = 0, r = numbers.size();
  while (l < r) {
    int sum = numbers[l] + numbers[r];
    if (sum == target) { 
      res = {l, r};
      return res;
      }
    else if (sum < targe)
      l++;
    else r--;
  }
  return res;
}
