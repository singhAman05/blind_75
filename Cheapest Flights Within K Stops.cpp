/* 
  In this question we will simply jusst run BFS and store the minimum MOUNT OF COST req to reach DESTINATION from the SOURCE
*/


class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];

        for(auto it : flights){
            adj[it[0]].push_back({it[1],it[2]});
        }

        vector<int> price(n,INT_MAX);

        queue<pair<int,int>> q;
        price[src] = 0;
        q.push({src,0});
        while(!q.empty()){
            if(k==-1) break;
            int si = q.size();
            while(si--){
                int node = q.front().first;
                int cur_price = q.front().second;
                q.pop();
                for(auto it : adj[node]){
                    int cost = it.second;
                    int adj_node = it.first;
                    if(cur_price + cost < price[adj_node]){
                        price[adj_node] = cur_price + cost;
                        q.push({adj_node,price[adj_node]});
                    }
                }
            }
            k--;
        }
        for(int i=0;i<n;i++) cout<<price[i]<<" ";
        if(price[dst] == INT_MAX) return -1;
        return price[dst];
    }
};
