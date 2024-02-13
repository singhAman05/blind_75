/*
  In this question we will just sheck the string by storing it in a temporary string and reversing it
  If we encounter it a palindrome then we will return the palindrome
*/

//TC O(N)
//SC O(1)
class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        string tmp;
        for(auto &it : words){
            tmp = it;
            reverse(tmp.begin(),tmp.end());
            if(tmp==it) return it;
        }
        return "";
    }
};
