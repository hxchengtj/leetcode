class PhoneDirectory {
public:
  int maxNum, idx;
  vector<int> freeVec;
  vector<bool> valid;
  /** Initialize your data structure here
      @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
  PhoneDirectory(int maxNumbers) {
    maxNum = maxNumbers;
    idx = 0;
    freeVec.resize(maxNumbers);
    valid.resize(maxNumbers);
    for(int i = 0; i < maxNumbers; i++) {
      freeVec[i] = i;
      valid[i] = true;
    }
  }

  /** Provide a number which is not assigned to anyone.
      @return - Return an available number. Return -1 if none is available. */
  int get() {
    if(idx < maxNum) {
      auto t = freeVec[idx++];
      valid[t] = false;
      return t;
    }
    else return -1;
  }

  /** Check if a number is available or not. */
  bool check(int number) {
    if(number < 0 || number >= maxNum) return false;
    return valid[number];
  }

  /** Recycle or release a number. */
  void release(int number) {
    if(number >= 0 && number < maxNum && !valid[number] ) {
      freeVec[--idx] = number;
      valid[number] = true;
    }
  }
};
