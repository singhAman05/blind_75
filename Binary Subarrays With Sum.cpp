/*
  In this question we will use map approach and sliding window approach
*/


class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int cur_sum = 0;
        int ans = 0;
        mp[cur_sum]++;
        for(int i=0;i<n;i++){
            cur_sum+=nums[i];
            if(mp.count(cur_sum-goal)){
                ans+=mp[cur_sum-goal];
            }
            mp[cur_sum]++;
        }
        return ans;
    }
};
