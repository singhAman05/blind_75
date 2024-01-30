/*
  In this question we will just remaove those intervals which lie inside one ranges 
*/

// TC O(N) + O(nlogn)
// SC O(1)
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        int ans = 0;
        int tmp = intervals[0][1];
        for(int i=1;i<n;i++){
            if(tmp>intervals[i][0]){
                tmp = min(tmp,intervals[i][1]);
                ans++;
                continue;
            }
            tmp = intervals[i][1];
        }
        return ans;
    }
};
