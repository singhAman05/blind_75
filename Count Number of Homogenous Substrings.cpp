/*
  In this questionwe will do the two pointer approach and and soter athe sub arrays as our ans
*/

// TC O(N)
// sc O(1)
class Solution {
public:
    int countHomogenous(string s) {
        int n = s.size();
        int mod = 1e9+7;
        int l=0,r=0;
        int ans = 0;
        while(r<n){
            while(s[r]==s[l]) r++;
            long long x = r-l;
            ans = (ans%mod + ((x*(x+1))/2)%mod)%mod;
            l=r;
        }
        return ans;
    }
};
