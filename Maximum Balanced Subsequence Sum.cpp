/*
  In this question we will do the variants of LIS technique to solve this
*/
// this will give TLE but soln is right
class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        long long int n = nums.size();
        vector<long long int> dp(n);
        for(int i=0;i<n;i++) dp[i] = nums[i];
        int ans = 0;
        long long mx = INT_MIN;
        for(int i=0;i<n;i++){
            mx = max(mx,(long long int)nums[i]);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]-nums[j] >= i-j){
                    long long int sum = dp[j]+nums[i];
                    dp[i] = max(dp[i],sum);
                    mx = max(dp[i],mx);
                }
            }
        }

        return mx;
    }
};



// Aproach 2 -> patience sorting

// we will do patience sorting
class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size();
        map<int, long long> mp;

        long long ans = INT_MIN;
        
        for(int i = 0; i < n; i++){
            auto it = mp.upper_bound(nums[i]-i); //Find the element just greater than nums[i]-i;

            long long cur_ans = nums[i];

            if(it != mp.begin()) {
                it--;
                cur_ans += (*it).second;
            }
            mp[nums[i]-i] = max(mp[nums[i]-i], cur_ans);

            it = mp.upper_bound(nums[i]-i);

            while(it != mp.end() && (*it).second <= cur_ans) {
                 mp.erase(it++);
            }

            ans = max(ans, cur_ans);
        }

        return ans;
    }
};
