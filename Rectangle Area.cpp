// Find the total area covered by two rectilinear rectangles in a 2D plane.

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int left = max(A,E);
        int right = min(G, C);
        int bottom = max(F, B);
        int top = min(D, H);
        
        // if overlap
        int overlap = 0;
        if(right > left && top > bottom)
             overlap = (right - left) * (top - bottom);
             
        return (C-A) * (D-B) + (G-E)*(H-F) - overlap;
    }
};
