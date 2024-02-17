/*
  In this question 
*/


class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        long long pr = 0;
        long long ans = 0;
        int l=0;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            if(mp[nums[i]]>=2) pr+=mp[nums[i]]-1;
            if(pr>=k){
                while(l<=i && pr>=k){
                    ans+=n-i;
                    mp[nums[l]]--;
                    pr-=mp[nums[l]];
                    if(mp[nums[l]]==0) mp.erase(nums[l]);
                    l++;
                }
            }
        }
        return ans;
    }
};
