/*
  In this question we will just count the number of zeros and product of all the numbers except "0"
  we will use the check if the number is zero and count of (zeros-1) still greater than zero so the ans will be one
  if the number is not zeros we will ceck if the count is greter than zero or not
*/

// TC O(2*n)
// SC O(1)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        long long pr = 1;
        int cnt = 0;
        vector<int> ans(n);
        for(auto it : nums){
            if(it==0){
                cnt++;
                continue;
            }
            pr*=it;
        }

        for(int i=0;i<n;i++){
            int x = nums[i];
            if(x==0){
                if(cnt-1>0) ans[i]=0;
                else ans[i] = pr;
            }
            else{
                if(cnt>0) ans[i]=0;
                else ans[i] = pr/x;
            }
        }

        return ans;
    }
};
