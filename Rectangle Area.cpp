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

//redo
int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
  int x1, y1, x2, y2;
  x1 = max(A, E); y1 = max(B, F);
  x2 = min(C, G); y2 = min(D, H);
  int ans = 0;
  if(x1 < x2 && y1 < y2) ans = -(x2-x1)*(y2-y1);
  ans += (C-A)*(D-B)+(H-F)*(G-E);
  return ans;
}

