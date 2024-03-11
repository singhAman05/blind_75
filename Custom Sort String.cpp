/*
  In this question we will hash the string 
  then we will iterate the order string and add the character if it is present in the hash map the number of times it appeared in S string
  then we will put those character in ans string which remained in the map 
*/


// TC O(N+M)
// SC O(1)
class Solution {
public:
    string customSortString(string order, string s) {
        int n = s.size();
        int m = order.size();
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        string ans;int j=0;
        for(int i=0;i<m;i++){
            if(mp.count(order[i])){
                int len = mp[order[i]];
                while(len--){
                    ans+=order[i];
                }
                mp.erase(order[i]);
            }
        }

        for(auto it : mp){
            char ch = it.first;
            int len = it.second;
            while(len--){
                ans+=ch;
            }
        }
        return ans;
    }
};
