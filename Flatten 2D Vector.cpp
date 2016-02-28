//Implement an iterator to flatten a 2d vector.
//For example,
//Given 2d vector =
[
  [1,2],
  [3],
  [4,5,6]
]
//By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1, 2, 3, 4, 5, 6].

//not tested yet
class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        data = vec2d;
        curRow = 0;
        while (data[curRow].empty()) // skip empty vector, corner case
            curRow++;
        curCol = 0;
    }

    int next() {
        int ele = data[curRow][curCol];
        if (curCol < data[curRow].size() - 1)
            curCol++;
        else {
            if (curRow < data.size() - 1) {
                while (data[curRow].empty()) // skip empty vector, corner case
                    curRow++;
                curCol = 0;
            }
        }
        return ele;
    }

    bool hasNext() {
        return curRow < data.size() && curCol < data[curRow].size();
    }
private:
    vector<vector<int>> data;
    int curRow;
    int curCol;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
