//An image is represented by a binary matrix with 0 as a white pixel and 1 as a black pixel. 
//The black pixels are connected, i.e., there is only one black region. Pixels are connected horizontally and vertically. 
//Given the location (x, y) of one of the black pixels, return the area of the smallest (axis-aligned) rectangle 
//that encloses all black pixels.
//For example, given the following image:

[
  "0010",
  "0110",
  "0100"
]
//and x = 0, y = 2,
//Return 6.

class Solution {
public:   
    int minArea(vector<vector<char>> iImage, int x, int y) {
        if (iImage.empty() || iImage[0].empty())    return 0;

        int left = searchColumn(),
            right = searchColumn(),
            top = searchRow(),
            bottom = searchRow();
            return (right - left)*(top - bottom);
    } 

    int searchColumn(vector<vector<char>> iImage, int left, int right, bool isLeft){
        while (left <= right) {
            int mid = (left+right)/2;
            int i = 0;
            for (; i < iImage.size(); i++) {
                if (iImage[i][mid] == '1')
                    break;
            }
            if (isLeft) {
                if (i == iImage.size()) 
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            else {
                if (i == iImage.size())
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            
        }
        return isLeft ? left : right;
    }

    int searchRow(vector<vector<char>> iImage, int top, int bottom, bool isTop) {
        while (top <= bottom) {
            int mid = (top+bottom)/2;
            int i = 0;
            for (; i < iImage[0].size(); i++) {
                if (iImage[mid][i] == '1')
                    break;
            }

            if (isTop) {
                if (i == iImage[0].size()) 
                    top = mid + 1;
                else 
                    bottom = mid - 1;
            }
            else {
                if (i == iImage[0].size()) 
                    bottom = mid - 1;
                else
                    top = mid + 1;
            }
        }
        return isTop ? top : bottom;
    }
};
