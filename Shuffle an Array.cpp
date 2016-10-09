/* review again */
class Solution {
public:
    vector<int> v;
    Solution(vector<int> nums) {
        v = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return v;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> shuffled = v;
        for(int i = 0; i < shuffled.size(); i++) {
            int a = rand() %(i+1);
            swap(shuffled[a], shuffled[i]);
        }
        return shuffled;
    }
};
 
//version2
class Solution {
    vector<int> v;
public:
    Solution(vector<int> nums) {
        v = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return v;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> t = v;
        for(int i = t.size()-1; i >= 0; i--) {
            int j = rand()%(i+1);
            swap(t[i], t[j]);
        }
        return t;
    }
};

