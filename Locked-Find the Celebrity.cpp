//untest
class Solution {
public:
  int findCelebrity(int n) {
    int i = 0, j = n-1;
    while(i < j) {
      if(knows(i, j)) i++;
      else j--;
    }
    for(int k = 0; k < n; k++)
      if(k != i && (knows(i, k) || !knows(k, i))) return -1;
    return i;
  }
};
