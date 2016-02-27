vector<string> processString(const vector<string>& vec, int n, int total) {
    vector<string> ret;
    for (string s : vec) {
        if (n != total) { // a number can't start with a 0
            ret.push_back("0" + s + "0");
        }
        ret.push_back("1" + s + "1");
        ret.push_back("8" + s + "8");
        ret.push_back("6" + s + "9");
        ret.push_back("9" + s + "6");
    }
    return ret;
}

vector<string> findImp(int n, int total) {
    if (n == 0) { return vector<string> { "" }; }
    if (n == 1) { return vector<string> { "1", "8", "0" }; }
    return processString(findImp(n - 2, total), n, total); //!!!
}

vector<string> findStrobogrammatic(int n) {
    return findImp(n, n);
}


//iterative solution
vector<string> findStrobogrammatic(int n) { 
        vector<string> strobos;
        if (n & 1) strobos = {"0", "1", "8"};
        else strobos = {""};
        vector<string> bases = {"00", "11", "88", "69", "96"};
        int m = bases.size(); 
        while (n > 1) {
            n -= 2;
            vector<string> temp;
            for (string strobo : strobos)
                for (int i = (n < 2 ? 1 : 0); i < m; i++)
                    temp.push_back(bases[i].substr(0, 1) + strobo + bases[i].substr(1));
            swap(temp, strobos);
        }
        return strobos;
    }
