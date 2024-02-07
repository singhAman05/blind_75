/*
 In this question we will just simply create a frequency map and then put that in our maximum priority queue
  then just add that character number of time it appeared in priority queue in our ans string
*/


class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto it : mp){
            pq.push({it.second,it.first});
        }

        string ans = "";
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int si = it.first;
            char ch = it.second;
            while(si--) ans+=ch;
        }
        return ans;
    }
};
