class Logger {
public:
  Logger() {}
    
  bool shouldPrintMessage(int timestamp, string message) {
    if(m.find(message) == m.end() || m[message] +10 <= timestamp) {
      m[message] = timestamp;
      return true;
    }
    return false;
  }
private:
    unordered_map<string, int> m;
};
