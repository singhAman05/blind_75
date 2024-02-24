/*
  In this solution i tried simple BFS but it gives TLE for large test cases
*/


class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<pair<int,int>> adj[n];
        for(auto it : meetings){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});

        }
        set<int> ans;
        ans.insert(0);
        ans.insert(firstPerson);
        queue<pair<int,int>> q;
        vector<int> vis(n);
        for(auto it : adj[firstPerson]){
            vis[it.first] = 1;
            q.push({it.first, it.second});
            ans.insert(it.first);
        }
        for(auto it : adj[0]){
            vis[it.first] = 1;
            q.push({it.first, it.second});
            ans.insert(it.first);
        }

        while(!q.empty()){
            int si = q.size();
            while(si--){
                int node = q.front().first;
                int time = q.front().second;
                vis[node] = 1;
                q.pop();
                for(auto it : adj[node]){
                    if(vis[it.first]==0)
                    {if(time <= it.second){
                        ans.insert(it.first);
                        q.push({it.first, it.second});
                    }}
                    else{
                        if(time < it.second){
                        ans.insert(it.first);
                        q.push({it.first, it.second});
                    }
                    }
                }
            }
        }
        vector<int> st(ans.begin(),ans.end());

        return st;
    }
};
