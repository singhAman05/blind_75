/*
  In this question we will use the trick that for zero we will add -1 in our sum
  and from here ew will use method of finding sub array with sum = "0"
*/

// TC O(N)
// SC O(N)
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int ans = 0;
        int sum = 0;
        for(int i=0;i<n;i++){
            if(nums[i])sum++;
            else sum--;
            if(sum==0) ans = max(ans,i+1);
            if(mp.count(sum)){
                ans = max(ans,i-mp[sum]);
                continue;
            }
            mp[sum] = i;
        }
        return ans;
    }
};
