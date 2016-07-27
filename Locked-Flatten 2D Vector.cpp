class Vector2D {
  vector<vector<int>>::iterator x, end;
  int y;
public:
  Vector2D(vector<vector<int>>& _vec2d) {
    x = _vec2d.begin();
    end = _vec2d.end();
    y = 0;
  }
  int next() {
    return (*x)[y++];
  }
  bool hasNext() {
    while(x != end && y == (*x).size()) {
      x++;
      y = 0;
    }
    return x != end;
  }
};
