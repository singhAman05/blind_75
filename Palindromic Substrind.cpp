/*
  In this question we will check for left and right for every character that what should be the max palindromic substring we can get
  
*/


class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            int l=i;
            int r=i;
            while(l>=0 && r<n && s[l]==s[r]) {ans++;l--;r++;}
            l=i;r=i+1;
            while(l>=0 && r<n && s[l]==s[r]) {ans++;l--;r++;}
        }
        return ans;
    }
};
