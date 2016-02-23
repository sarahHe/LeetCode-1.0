class Solution {
public:
    int compareVersion(string version1, string version2) {
        while (version1 != version2) { // key point
            int i = version1.find_first_of('.'),
                j = version2.find_first_of('.');
            
            int d1 = stoi(version1.substr(0, i)),
                d2 = stoi(version2.substr(0, j));
            if (d1 > d2)
                return 1;
            else if (d2 > d1)
                return -1;

            version1 = i > -1 ? version1.substr(i+1) : "0"; // key point
            version2 = j > -1 ? version2.substr(j+1) : "0";
        }
        return 0;
    }
};
