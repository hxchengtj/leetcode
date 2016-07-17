class Iterator {
    struct Data;
  Data* data;
public:
  Iterator(const vector<int>& nums);
  Iterator(const Iterator& iter);
  virtual ~Iterator();
  // Returns the next element in the iteration.
  int next();
  // Returns true if the iteration has more elements.
  bool hasNext() const;
};


class PeekingIterator : public Iterator {
    int peek_val;
    bool has_next;
public:
  PeekingIterator(const vector<int>& nums) : Iterator(nums) {
      // Initialize any member here.
      // **DO NOT** save a copy of nums and manipulate it directly.
      // You should only use the Iterator interface methods.
      has_next = Iterator::hasNext();
      if(has_next) peek_val = Iterator::next();
  }

    // Returns the next element in the iteration without advancing the iterator.
  int peek() {
        return peek_val;
  }

  // hasNext() and next() should behave the same as in the Iterator interface.
  // Override them if needed.
  int next() {
      int ret = peek_val;
      has_next = Iterator::hasNext();
      if(has_next) peek_val = Iterator::next();
      return ret;
  }

  bool hasNext() const {
      return has_next;
  }
};
