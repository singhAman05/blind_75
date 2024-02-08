/*
  Int this question we will just use the formula { An = A + (n-1)*d } for calculation od common diff and check the
  all possible numbres that can possible in range
*/


class Solution {
public:
    bool check(vector<int> arr){
        int n = arr.size();
        int mi = INT_MAX;
        int mx = INT_MIN;
        unordered_set<int> st;

        for(auto it : arr){
            mi = min(mi,it);
            mx = max(mx,it);
            st.insert(it);
        }

        if((mx-mi) % (n-1) != 0)
            return false;
        
        int diff = (mx-mi)/(n-1);
        int curr = mi + diff;

        while(curr<mx){
            if(st.find(curr)==st.end()) return false;
            curr = curr+diff;
        }

        return true;
    }

    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = l.size();
        vector<bool> ans;

        for(int i=0;i<n;i++){
            vector<int> arr(nums.begin()+l[i],nums.begin()+r[i]+1);

            ans.push_back(check(arr));
        }
        return ans;
    }
};
