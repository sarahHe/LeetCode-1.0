//Write a function to find the longest common 
//prefix string amongst an array of strings.

//try to reduce the time of comparing
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty())   return "";
        
        int length = strs[0].length();
        for (int i = 0; i < (int)strs.size(); i++) {
            if (strs[i] == "")  return "";
            
            int j = 0;
            for (; j < (int)strs[i].length(); j++) {
                    if (j >= length || strs[i][j] != strs[0][j]) // j>= length
                        break;
            }
            length = j;
        }
        return strs[0].substr(0, length);
    }
};
