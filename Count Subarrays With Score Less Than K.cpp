/*
  In this question we will just simply take a sum variable to store the sum from traversing left to right and then we will check if it is greater than 
  the K after multiplying it with its length then we will just simply delete it from begin 
*/

// TC O(N)
// SC O(1)
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long ans = 0;
        long long res = 0;
        for(int l=0,r=0;r<n;r++){
            res+=nums[r];
            while(l<r && res*(r-l+1)>=k){
                res-=nums[l++];
            }
            if(res<k) ans+=(r-l+1);
        }
        return ans;
    }
};
