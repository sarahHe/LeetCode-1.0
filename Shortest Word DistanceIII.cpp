//word1 and word2 can be equal
int shortestWordDistance(vector<string>& words, string word1, string word2) {
    int distance = INT_MAX;
    int idx1 = -1, idx2 = -1;
    for (int i = 0; i < words.size(); i++) {
        if (words[i] == word1 && words[i] == word2) {
            if (idx1 > idx2)
                idx2 = i;
            else
                idx1 = i;
        }
        else if (words[i] == word1)
            idx1 = i;
        else if (words[i] == word2)
            idx2 = i;
        distance = min(distance, abs(idx1 - idx2));
    }
    return distance;
}
