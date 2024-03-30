/*
  In this question we will use slinding window and diff upto 2 previous terms
*/


class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n<3) return 0;
        int l=0,r=2;
        long long ans = 0;
        int cnt = 0;
        while(r<n){
            if(nums[r]-nums[r-1] == nums[r-1]-nums[r-2]) cnt++;
            else cnt=0;
            ans+=cnt;
            r++;
        }

        return ans;
    }
};
