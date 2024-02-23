/*
  In this question we will do brute force and and optimal approach
*/

// TC O(N*K)
// SC O(1)
// this is just finding maximum number in every possible window of K
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        int r = k-1,l=0;
        vector<int> ans;
        while(r<n){
            int ele = *max_element(nums.begin()+l,nums.begin()+r+1);
            ans.push_back(ele);
            r++;l++;
        }
        return ans;
    }
};
