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


/*
   In this solution we will just kee track of maximum element in a deque and popout if it reaches out of bound
*/

// TCO(N)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;

        deque<int> dq;
        for(int i=0;i<n;i++){

            // poping out those element which are out of the window
            while(!dq.empty() && dq.front()<=i-k) dq.pop_front();
            
            // poping out the elements which are smaller than the current element
            while(!dq.empty() && nums[i] > nums[dq.back()]) dq.pop_back();

            // pushing the current index
            dq.push_back(i);

            // adding front element in window
            if(i-k+1 >= 0){
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};
