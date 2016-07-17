class MedianFinder {
    vector<int> maxHeap, minHeap;
    
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        auto cmp = [](const int &a, const int &b){
            return a > b;
        };
        if(maxHeap.size() == 0 || maxHeap[0] >= num) {
            maxHeap.push_back(num);
            push_heap(maxHeap.begin(), maxHeap.end());
        } else {
            minHeap.push_back(num);
            push_heap(minHeap.begin(), minHeap.end(), cmp);
        }
        
        if(maxHeap.size() > minHeap.size()+1) {
            minHeap.push_back(maxHeap[0]);
            push_heap(minHeap.begin(), minHeap.end(), cmp);
            pop_heap(maxHeap.begin(), maxHeap.end());
            maxHeap.pop_back();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push_back(minHeap[0]);
            push_heap(maxHeap.begin(), maxHeap.end());
            pop_heap(minHeap.begin(), minHeap.end(), cmp);
            minHeap.pop_back();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        int n = maxHeap.size()+minHeap.size();
        if(n%2 == 0) return (maxHeap[0]+minHeap[0])/2.0;
        else return maxHeap[0];
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
