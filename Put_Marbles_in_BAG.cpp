/*
  This is a standard question which have a very wasy intution but a tricky one to hit for the first time
  you will notivce no matter waht first and the last element will always come into as sum so 
  take consequtive pair sum and sort them then find k-1 from front and k-1 from end then find the diff b/w them
*/


class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();

        if(n==k) return 0;

        vector<long long> ans;
        for(int i=1;i<n;i++){
            ans.push_back(weights[i]+weights[i-1]);
        }

        sort(ans.begin(), ans.end());
        // for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
        
        long long sum1 = 0;
        long long sum2 = 0;
        // cout<<sum1<<" "<<sum2;
        int m = ans.size();
        for(int i=0;i<k-1;i++){
            sum1+=ans[i];
            sum2+=ans[m-1-i];
        }
        return sum2-sum1;
    }
};
