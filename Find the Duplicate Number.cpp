/*
  In this question we will use the jumping thorugh the index and making them negative
  if the index if already negative then that number is repeated
*/

//TC O(N)
//SC O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            int x = abs(nums[i]);
            if(nums[x]<0) return x;
            nums[x] = -1 * nums[x];
        }
        return -1;
    }
};
