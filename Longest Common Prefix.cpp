//Write a function to find the longest common 
//prefix string amongst an array of strings.

//try to reduce the time of comparing
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty() || strs[0] == "")  return ""; // edge case ["", ""]
        
        //sort(strs.begin(), strs.end()); //it's also good to sort first
        for (int i = 0; i < strs[0].length(); i++) {
            for (int j = 0; j < strs.size(); j++) {
                if (strs[0][i] != strs[j][i]) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
    
};
