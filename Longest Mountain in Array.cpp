/*
  In this question I have just calculated the mountain for every numer in array and store the maximum number in our ans;
*/

// TC O(N*N)
// SC O(1)
class Solution {
public:
    int longestMountain(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            int l=i,r=i;
            while(l>0 && nums[l]>nums[l-1]) l--;
            while(r<n-1 && nums[r]>nums[r+1]) r++;
            cout<<l<<" "<<r;
            if(l!=i && r!=i)ans = max(ans,r-l+1);
        }
        return ans>=3?ans:0;
    }
};
