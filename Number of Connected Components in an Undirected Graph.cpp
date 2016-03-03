
int findRep(vector<int>& rep, int n) {
    while (n != rep[n]) {
        rep[n] = rep[rep[n]];
        n = rep[n];
    }
    return n;
}

int countComponents(int n, vector<pair<int, int>>& edges) {
    vector<int> rep(n, 0);
    
    //initialization
    for (int i = 0; i < n; i++)
        rep[i] = i;
    
    //Union
    for (int i = 0; i < edges.size(); i++) {
        int rep1 = findRep(rep, edges[i].first);
        int rep2 = findRep(rep, edges[i].second);
        rep[rep1] = rep2;
    }
    
    // Count
    int count = 0;
    for (int i = 0; i < rep.size(); i++) {
        if (rep[i] == i)
            count++;
    }
    return count;
}
