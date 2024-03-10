/*
  In this question the trick is we willtraverse backward as overirng is there
  we will amintain two sets ROW and COL which will store row index and col index
  then we will take tow integers remain_row and remaining_col and add the ans accordingly
*/


//TC O(queries.size())
//SC O(2*N)
class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        set<int> row,col;
        long long sum = 0;
        int row_rem = n,col_rem = n;
        int m = queries.size();
        for(int i=m-1;i>=0;i--){
            int type = queries[i][0];
            int ind = queries[i][1];
            int val = queries[i][2];

            if(type){
                if(col.count(ind)) continue;
                sum += (val*col_rem);row_rem--;
                col.insert(ind);
            }
            else{
                if(row.count(ind)) continue;
                sum += (val*row_rem);col_rem--;
                row.insert(ind);
            }
        }

        return sum;
    }
};
