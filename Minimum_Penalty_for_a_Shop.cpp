/*
  In this question we will just gather the number of people entring in store 
  Then we will check for every hour how much penalty we are getting from left side and right side of that hour
*/

// TC O(N)
// SC O(1)
class Solution {
public:
    int bestClosingTime(string cus) {
        int n = cus.size();
        int people = 0;
        int noPeople = 0;
        for(int i=0;i<n;i++){
            //counting number of people standing in a queue
            if(cus[i]=='Y') people++;
        }
        
        //to store number of
        int curPeople = 0;
        int ans = people;
        int hour = 0;

        // we will check for every hour that how much penalty we are getting
        for(int i=0;i<n;i++){
            if(cus[i]=='Y') {
                curPeople++;
            }
            else noPeople++;
            
            //checking how much total penalty we are getting each hour and storing it it ans
            if(ans > (people-curPeople+noPeople)){
                ans = (people-curPeople+noPeople);
                hour = i+1;
            }
        }
        return hour;
    }
};
