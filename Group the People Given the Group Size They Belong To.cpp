class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& gs) {
        unordered_map<int,vector<int>> mp;
        int n = gs.size();
        for(int i=0;i<n;i++){
            mp[gs[i]].push_back(i);
        }
        vector<vector<int>> ans;
        for(auto &it : mp){
            vector<int> res;
            int tmp = it.first;
            auto vec = it.second;
            int size = vec.size();
            for(int i=1;i<=size;i++){
                res.push_back(vec[i-1]);
                if(res.size()%tmp == 0){
                    ans.push_back(res);
                    res.clear();
                }
            }
        }
        return ans;
    }
};
