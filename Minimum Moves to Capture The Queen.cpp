/*
  In this question I have just only use the maths and max number of moves to kill the queen is 2 because rook can do it in 2 steps
  Now the question boils down for 1 step what if rook is between bishop path or bishop is between rooks path
  so here are the consition
*/


class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        if(a==e || b==f){
            // this is only basic math formula i have used
            if(a==e && a==c && ((d-b)*(d-f)<0)) return 2;
            if(b==f && b==d && ((c-a)*(c-e)<0)) return 2;
            return 1;
        }
        if(abs(c-e)==abs(d-f)){
            if(abs(c-a)==abs(d-b)){
                if((b-d)*(b-f)<0) return 2;
                return 1;
            }
            return 1;
        }
        return 2; 
    }
};
