/*
  In this quesion I have used two strings to not get TLE
  one is used as the bit and another one is used as a flipped bit
*/

// TC O(N)
// SC OC(2*N)
class Bitset {
public:
    string bit;
    string bit2;
    int cnt = 0;
    Bitset(int size) {
        bit.resize(size,'0');
        bit2.resize(size,'1');
        cout<<bit<<endl;
    }
    
    void fix(int inx) {
        if(bit[inx]=='0'){
            bit[inx] = '1';
            cnt++;
        }
        bit2[inx] = '0';
    }
    
    void unfix(int inx) {
        if(bit[inx]=='1'){
            bit[inx] = '0';
            cnt--;
        }
        bit2[inx] = '1';
    }
    
    void flip() {
        string tmp = bit;
        bit = bit2;
        bit2 = tmp;
        cnt = bit.size()-cnt;
    }
    
    bool all() {
        if(cnt==bit.size()) return 1;
        return 0;
    }
    
    bool one() {
        if(cnt>0) return 1;
        return 0;
    }
    
    int count() {
        return cnt;
    }
    
    string toString() {
        return bit;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */
