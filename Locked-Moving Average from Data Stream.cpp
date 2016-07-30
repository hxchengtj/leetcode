class MovingAverage {
  int n;
  queue<int> q;
  double sum;
public:
  MovingAverage(int size) {
    n = size;
    sum = 0;
  }
  double next(int val) {
    if(q.size() == n) {
      int t = q.front();
      sum -= t;
      q.pop();
    }
    q.push(val);
    sum += val;
    return sum/q.size();
  }
};

