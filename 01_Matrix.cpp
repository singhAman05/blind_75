/*
  Approach 1 we will do the  BFS call for every one and return the minimum number of steps to find a nearest zero
  This approach will give  the TLE
*/

//TC O(n*m) + O(n+m) BFS
//SC O(n*m)
class Solution {
public:
    int n,m;

    //Four diection matrix
    vector<vector<int>> dir = {{-1,0},{0,-1},{1,0},{0,1}};
    int bfs(vector<vector<int>> &mat, int row, int col){
        // visited pair so that to check we dont visit same cell again
        set<pair<int,int>> st;
        st.insert({row,col});

        // queue for BFS
        queue<pair<int,int>> q;
        q.push({row,col});

        // number of steps needed
        int lev = 0;
        while(!q.empty()){
            int si = q.size();
            while(si--){
                auto p = q.front();
                int r = p.first;
                int c = p.second;
                q.pop();
                //returning if we find zero in that cell
                if(mat[r][c]==0) return lev;
                for(auto &it : dir){
                    int nr = r+it[0];
                    int nc = c+it[1];
                    if(nr>=0 && nr<n && nc>=0 && nc<m && st.find({nr,nc})==st.end()){
                        //after checking conditions we will insert in the queue
                        q.push({nr,nc});
                        st.insert({nr,nc});
                    }
                }
            }
            lev++;
        }
        return lev;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        n = mat.size();
        m = mat[0].size();

        //ans matrix
        vector<vector<int>> ans(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]){
                    //BFS call for every "1" we found
                    ans[i][j] = bfs(mat,i,j);
                }
            }
        }
        return ans;
    }
};
