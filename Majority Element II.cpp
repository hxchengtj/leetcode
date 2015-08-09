class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int a = 0, an = 0, b = 1, bn = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(a == nums[i])
                an++;
            else if(b == nums[i])
                bn++;
            else if(an == 0) {
                a = nums[i];
                an = 1;
            }
            else if(bn == 0) {
                b = nums[i];
                bn = 1;
            }
            else {
                an--;
                bn--;
            }
        }
        vector<int> v;
        int aa = 0, bb = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == a)
                aa++;
            else if(nums[i] == b)
                bb++;
        }
        if(aa > nums.size()/3)
            v.push_back(a);
        if(bb > nums.size()/3)
            v.push_back(b);
        return v;
    }

};

//redo
vector<int> majorityElement(vector<int>& nums) {
  int num1 = 0, num2 = -1, count1 = 0, count2 = 0;
  for(auto a:nums) {
    if(num1 == a) count1++;
    else if(num2 == a) count2++;
    else if(count1 == 0) {
      num1 = a;
      count1++;
    } else if(count2 == 0) {
      num2 = a;
      count2++;
    } else {
      count1--;
      count2--;
    }
  }
  count1 = 0; count2 = 0;
  for(auto a:nums) {
    if(a == num1) count1++;
    else if(a == num2) count2++;
  }
  vector<int> ans;
  if(count1 > nums.size()/3) ans.push_back(num1);
  if(count2 > nums.size()/3) ans.push_back(num2);
  return ans;
}

