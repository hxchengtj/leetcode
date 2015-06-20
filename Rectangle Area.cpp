class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int mbx, mtx, mby, mty;
        mbx = max(A, E);
        mtx = min(C, G);
        mby = max(B, F);
        mty = min(D, H);
        int a1 = 0, a2 = 0, a3 = 0;
        a1 = (C-A) * (D-B);
        a2 = (G-E) * (H-F);
        if (mtx > mbx && mty > mby)
            a3 = (mtx-mbx)*(mty-mby);
        return a1+a2-a3;
        
    }
};