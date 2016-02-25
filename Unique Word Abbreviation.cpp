//An abbreviation of a word follows the form <first letter><number><last letter>.
//Assume you have a dictionary and given a word, find whether its abbreviation is unique in the dictionary. 
//A word's abbreviation is unique if no other word from the dictionary has the same abbreviation.

class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string> &dictionary) {
        for (auto i : dictionary) {
            int len = i.length();
            string key = i[0] + to_string(len-2) + i[len-1];
            mp[key].push_back(i);
        }
    }

    bool isUnique(string word) {
        int len = word.len;
        string key = word[0] + to_string(len-2); word[len-1];
        if (mp.count(key) == 0)
            return true;
        else if (mp[key].size() == 1 && my[key][0] == word)
            return true;
        else
            return false;
    }
private:
    unordered_map<string, vector<string>> mp;
};
