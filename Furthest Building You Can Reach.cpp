/*
  This question can be the classic DP question so I have discussed all the three approach here
  In this question I have used LAZY GREEDY so do check this approach
*/

// <---------- Aproach 1 -------------->
// TLE [simple recusrion]
class Solution {
public:
    int n;
    int solve(vector<int>& heights, int bricks, int ladders, int ind){
        // if we are at last building return
        if(ind==n-1) return ind;

        // If we are at heights greater than equal to  next building height we will go without any reduction
        if(heights[ind]>=heights[ind+1]){
            return solve(heights,bricks,ladders,ind+1);
        }

        // we will set the cur ans to current index that till here we can come if we cannot go further
        int br=ind,lad=ind;

        // checking the condition to be satisfied first
        if((heights[ind+1]-heights[ind]) <= bricks) br = solve(heights,bricks-(heights[ind+1]-heights[ind]),ladders,ind+1);
        if(ladders>0) lad = solve(heights,bricks,ladders-1,ind+1);

        // returning the maximum ans
        return max({br,lad});
    }
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        n = heights.size();
        return solve(heights,bricks,ladders,0);
    }
};


// <-------------Approach 2----------------->
// memory limit exceeded
// recursion + memization

class Solution {
public:
    int n;
    int dp[100001][1000000001];
    int solve(vector<int>& heights, int bricks, int ladders, int ind){
        if(ind==n-1) return dp[bricks][ladders] = ind;
        if(dp[bricks][ladders]!=-1) return dp[bricks][ladders];

        if(heights[ind]>=heights[ind+1]){
            return solve(heights,bricks,ladders,ind+1);
        }
        int br=ind,lad=ind;
        if((heights[ind+1]-heights[ind]) <= bricks) br = solve(heights,bricks-(heights[ind+1]-heights[ind]),ladders,ind+1);
        if(ladders>0) lad = solve(heights,bricks,ladders-1,ind+1);

        return  dp[bricks][ladders] = max({br,lad});
    }
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        n = heights.size();
        memset(dp,-1,sizeof(dp));
        return solve(heights,bricks,ladders,0);
    }
};
