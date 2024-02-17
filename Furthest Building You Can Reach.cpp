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



// <---------------Approach 3------------------->
//Accepted Approach
//Using Lazy Greedy
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {      
        int n = heights.size();
    
        priority_queue<int> pq;
        
        int i = 0;
        for(;i < n-1;i++) {
            if(heights[i] >= heights[i+1]) {
                continue;
            }
            
            int diff = heights[i+1]-heights[i];
            if(diff <= bricks) {
                bricks -= diff;
                pq.push(diff); //I used diff bricks here (keep track of it)
            } else if(ladders > 0) {
                if(!pq.empty()) {
                    int max_bricks_past = pq.top();
                    if(max_bricks_past > diff) {
                        //it means i unneccasrily used huge bricks in past. Let's get it back
                        bricks += max_bricks_past;
                        pq.pop();
                        pq.push(diff);
                        bricks -= diff;
                    }
                }
                ladders--; //either used in past or present
            } else {
                break;
            }
        }
        return i;
    }
};
