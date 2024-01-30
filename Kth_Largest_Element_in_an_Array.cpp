/*
  In this question we have not sorted the array instead we have taken a priority queue of K size
  This queue will store the K largest elemt and at the back of the queue we will have the Kth largest element
*/

// TC O(N)
// SC O(K)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int i=0;i<nums.size();i++) pq.push(nums[i]);
        while(k!=1){
            pq.pop();
            k--;
        }
        return pq.top();
    }
};
