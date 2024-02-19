/*
  In this question we know that if a number if power of two then it will have only one "1" in its binary form 
  so i have just calculated its count of "1" in that number and return the ans accordingly
*/

//TC O(32)
//SC O(1)
class Solution {
public:
    bool isPowerOfTwo(int n) {
        int cnt = 0;
        while(n>0){
            int l = n&1;
            if(l)cnt++;
            n = n>>1;
        }
        return cnt==1;
    }
};
