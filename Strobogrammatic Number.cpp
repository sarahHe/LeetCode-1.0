/A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
//Write a function to determine if a number is strobogrammatic. The number is represented as a string.
//For example, the numbers "69", "88", and "818" are all strobogrammatic.

bool isStrobogrammatic(string num) {
    unordered_map<int, int> mp;
    int n = num.length(); 
    for (int l = 0, r = n - 1; l <= r; l++, r--)
        if (mp.count(num[l]) > 0 ||  
            mp.count(num[r]) > 0|| 
            mp[num[l]] != num[r])
            return false;
    return true;
}
