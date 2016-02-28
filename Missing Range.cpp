//Given a sorted integer array where the range of elements are [0, 99] inclusive, return its missing ranges.
//For example, given [0, 1, 3, 50, 75], return [“2”, “4->49”, “51->74”, “76->99”]

string get_range(int a, int b) {
    if (a == b) return to_string(a);
    else return to_string(a) + "->" + to_string(b);
}

vector<string> findMissingRanges(vector<int> vals, int start, int end) {
    vector<string> res;
    int pre = start - 1; //pre and cur denotes something like nums[i-1] and nums[i]
    for (int i = 0; i <= nums.size(); i++) {
        int cur = (i == nums.size()) ? end+1 : nums[i];
        if (cur - pre >= 2) {
            res.push_back(get_range(pre+1, cur-1));
        }
        pre = cur;
    }
    return res;
}
