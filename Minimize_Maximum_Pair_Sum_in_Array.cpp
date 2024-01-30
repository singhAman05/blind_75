/*
  In this question we have to take the maximum of the minimum pair sum
  Minimum sum can be obtained by adding smallies number with largest number and second smallest number with second largest number and so on
  now after that take maximum of that
*/


class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int i=0,j=n-1;
        int ans = INT_MIN;
        while(i<j){
            ans = max(ans,nums[i++]+nums[j--]);
        }
        return ans;
    }
};
