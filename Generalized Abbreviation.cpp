//Write a function to generate the generalized abbreviations of a word.
//
//Example:
//Given word = "word", return the following list (order does not matter):
//
//全选复制放进笔记["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", >"1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]

void generateHelper(vector<string> &res, string word, int start) {
    if (start == word.length())
        return;
    
    int i = 0;
    if (start > 0)
        i = start + 1;
    for (; i < word.length(); i++) {
        for (int len = 1; i+len <= word.length(); len++) {
            string abbr = word.substr(0, i) + to_string(len) + word.substr(i+len);
            res.push_back(abbr);
            generateHelper(res, abbr, i + start + 1);
            
        }
    }
}

vector<string> generateAbbreviations(string word) {
    vector<string> res = {word};
    generateHelper(res, word, 0);
    return res;
}
