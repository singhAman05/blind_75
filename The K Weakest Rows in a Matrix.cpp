/*
  In this question we will store sum and corresponding row in a priority queue
  then we will print the first K numbers inoutput
  sum will increment when we encounter "1"
  sum will decrease when we will encounter "0"
*/

//TC O(N);
//SC O(K);
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int i=0;i<mat.size();i++){
            int sum = 0;
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]) sum++;
                else sum--;
            }
            pq.push({sum,i});
        }
        vector<int> ans;
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
