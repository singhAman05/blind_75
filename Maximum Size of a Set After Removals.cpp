/*
  In this questioni have took 3 sets and remove the common elemts frome ac two sets and return the min ans
*/


class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1,s2,common;
        int n = nums1.size();
        for(auto it : nums1) s1.insert(it);
        for(auto it : nums2){ 
            s2.insert(it);
            if(s1.find(it)!=s1.end())common.insert(it);
        }
        
        int n1 = s1.size();
        int n2 = s2.size();
        int cs = common.size();
        
        return min(min(n1-cs,n/2) + min(n2-cs,n/2) + cs, n);
    }
};
