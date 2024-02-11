/*
  This is a classic DP problem in which we have to explore all the ways for both the robots
  the catch is when we are at the same cell we have just take CHERRY only one time
*/


class Solution {
public:
    int n,m;
    int dp[71][71][71];
    int solve(vector<vector<int>>& grid, int ind, int col1, int col2){
        if(ind>=n) return 0;
        if(dp[ind][col1][col2]!=-1) return dp[ind][col1][col2];


        // handling the catch
        int cherry = grid[ind][col1];
        if(col1!=col2) cherry+=grid[ind][col2];

        int ans = 0;

      //exploring all the ways for both the robots
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                int new_col1 = col1+i;
                int new_col2 = col2+j;

                if(new_col1>=0 && new_col1<m && new_col2>=0 && new_col2<m){

                  // storing the maximum sum that we can get for a cell
                    ans = max(ans, solve(grid,ind+1,new_col1, new_col2));
                }
            }
        }

        // return ans
        return dp[ind][col1][col2] = cherry+ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(grid,0,0,m-1);
    }
};
