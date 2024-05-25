
// TC O(N)
// SC O(N)


class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_set<int> st;
        int n = nums.size();
        for(int i=0;i<n-1;i++){
            if(st.find(nums[i]+nums[i+1])!=st.end()) return 1;
            st.insert(nums[i]+nums[i+1]);
        }
        return 0;
    }
};
