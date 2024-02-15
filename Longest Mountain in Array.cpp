/*
  In this question I have just calculated the mountain for every numer in array and store the maximum number in our ans;
*/

// TC O(N*N)
// SC O(1)
class Solution {
public:
    int longestMountain(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            int l=i,r=i;
            while(l>0 && nums[l]>nums[l-1]) l--;
            while(r<n-1 && nums[r]>nums[r+1]) r++;
            cout<<l<<" "<<r;
            if(l!=i && r!=i)ans = max(ans,r-l+1);
        }
        return ans>=3?ans:0;
    }
};


//TC O(N)
class Solution {
public:
        int longestMountain(vector<int> A) {
        int N = A.size(), res = 0;
        vector<int> up(N, 0), down(N, 0);
        for (int i = N - 2; i >= 0; --i) if (A[i] > A[i + 1]) down[i] = down[i + 1] + 1;
        for (int i = 0; i < N; ++i) {
            if (i > 0 && A[i] > A[i - 1]) up[i] = up[i - 1] + 1;
            if (up[i] && down[i]) res = max(res, up[i] + down[i] + 1);
        }
        return res;
    }
};
