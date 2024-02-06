/*
  In this question we will add the minutes of all the garbage in first travesing and place the hooks of index for every 
  truck and then on second traversal we will add the travel time
*/



class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size();
        int m = travel.size();
        int hook1=0,hook2=0,hook3=0;
        int ans = 0;
        for(int i=0;i<n;i++){
            string s = garbage[i];
            ans+=s.size();
            for(auto it : s){

                // plotting the index of last garbage of each tpye
                if(it=='P') hook1=i;
                if(it=='G') hook2=i;
                if(it=='M') hook3=i;
            }
        }

        for(int i=0;i<m;i++){
            //adding it to our ans
            if(i<hook1) ans+=travel[i];
            if(i<hook2) ans+=travel[i];
            if(i<hook3) ans+=travel[i];
        }

        return ans;
    }
};
