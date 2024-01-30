/*
In this question we will sort th array as we have to maximize the sum of min(ai, bi)
then we will calculate the sum of minimum numbers that will come in pairs
int this case it will be always that number at which is at (!i&1)
*/


class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int sum = 0;
        for(int i=n-2;i>=0;i-=2) sum+=nums[i];

        return sum;
    }
};
