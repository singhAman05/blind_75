/*
  This is simeple stack question just push the number and pop two number when encounter any operator
  then push the result in the stack
  At the end the top element will tell you the ans of the notation
*/

// TC O(N)
// SC O(N)
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]!="+" && tokens[i]!="-" && tokens[i]!="*" && tokens[i]!="/"){
                st.push(stoi(tokens[i]));
            }
            else if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/"){
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                if(tokens[i]=="+")st.push(y+x);
                else if(tokens[i]=="-")st.push(y-x);
                else if(tokens[i]=="*")st.push(y*x);
                else st.push(y/x);
            }
        }

        return st.top();
    }
};
