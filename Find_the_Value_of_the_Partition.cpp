/*
  In this question we will just take the consecutive pair sum and find the minimum of that 
  Because we have to make only two partions so we will try every possible consecutive way
*/

// TC O(nlogn)
// sc O(1)
class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int ans = INT_MAX;
        for(int i=0;i<n-1;i++){
            ans = min(ans,nums[i+1]-nums[i]);
        }
        return ans;
    }
};
