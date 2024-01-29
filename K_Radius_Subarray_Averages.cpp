/*
  In this question we will use the concept of Sliding Window as we will have the window size of {K+1} and we will slide it through the array.
  first find sum of all the number upto {2*K} and then start traversing from K upto which { K+cur_ind > size}
*/

// TC O(N)
// SC O(1)
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        long long n = nums.size();
        vector<int> ans(n,-1);
        
        // handling exceptions
        if(k==0) return nums;

        // if {K+1} is greater than n all number have average of -1
        if(ceil((double)n/(double)2) <= k) return ans;

        long long sum = 0;

        //finding sum upto initial K terms 
        for(int i=0;i<2*k;i++){
            sum+=nums[i];
        }

        for(int i=k;i<n;i++){
            //if we exceed the range of {K+1} we will break
            if(i+k>=n) break;

            //adding last term
            sum+=nums[i+k];
            long long div = (2*k)+1;
            long long avg = sum/div;
            ans[i] = avg;

            //subtracting the last term as we will slide the window by one
            sum-=nums[i-k];
        }

        return ans;
    }
};
