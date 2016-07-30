class SnakeGame {
  set<pair<int, int>> s;
  deque<pair<int, int>> d;
  int w, h, idx;
  vector<pair<int, int>> food_;
public:
  /** Initialize your data structure here.
  @param width - screen width
  @param height - screen height
  @param food - A list of food positions
  E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
  SnakeGame(int width, int height, vector<pair<int, int>> food) {
    food_ = food;
    w = width; h = height;
    idx = 0;
    d.push_front({0, 0});
    s.insert(make_pair(0, 0));
  }

  /** Moves the snake.
  @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down
  @return The game's score after the move. Return -1 if game over.
  Game over when snake crosses the screen boundary or bites its body. */
  int move(string direction) {
    auto p = d.front();
    
    if(direction == "U") p.first--;
    else if(direction == "L") p.second--;
    else if(direction == "R") p.second++;
    else if(direction == "D") p.first++;
    
    if(p.first < 0 || p.first >= h || p.second < 0 || p.second >= w || s.find(p) != s.end())
      return -1;
    d.push_front(p);
    s.insert(p);
    if(idx >= food_.size() || p != food_[idx]) {
      s.erase(d.back());
      d.pop_back();
    }
    else idx++;
    return d.size()-1;
  }
};
