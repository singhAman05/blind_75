/*
  In this question DP will give you TLE so we have used SLIDING MAXIMUM TECHNIQUE technique
*/


class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(nums);
        int maxR = ans[0];
        deque<int> dq;

        for(int i=0;i<n;i++){
            while(!dq.empty() && dq.front() < i-k) dq.pop_front();

            if(!dq.empty()){
                ans[i] = max(ans[i], nums[i] + ans[dq.front()]);
            }

            while(!dq.empty() && ans[i] >= ans[dq.back()]) dq.pop_back();

            dq.push_back(i);

            maxR = max(maxR,ans[i]);
        }

        // int sum = accumulate(ans.begin(),ans.end(),0);
        // int mx = *max_element(ans.begin(),ans.end());

        return maxR;
    }
};
