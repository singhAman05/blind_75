/*
  In this question we will just use maths to solve the question
*/


class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<int> ans(n,0);
        if(x>y) swap(x,y);
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                int ind = min({(j-i),abs(x-i)+abs(j-y)+1})-1;
                ans[ind]+=2;
            }
        }
        return ans;
    }
};
