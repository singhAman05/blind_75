/*
  In this question we will just tarverse the whole string and count the range till all characters are same and equals to one
  then we will add that range SUBARRAYS in the ans
*/


// TC O(N)
// SC O(1)
class Solution {
public:
    int numSub(string s) {
        int n = s.size();
        int ans = 0;
        int mod = 1e9+7;
        int l=0,r=0;
        while(r<n){
            while(s[r]==s[l])r++;
            long long x = r-l;
            if(s[l]=='1') ans = (ans%mod + (((x+1)*x)/2)%mod)%mod;
            l=r;
        }
        return ans;
    }
};
