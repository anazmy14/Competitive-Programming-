class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& v) {
        bool col[9][10] = {{0}}, row[9][10] ={{0}} , box[3][3][10] ={{0}} ;
        
        for(int i=0; i < 9 ; i++) {
            for( int j =0 ; j < 9; j++) {
                if (v[i][j] == '.') continue;
                int x = v[i][j]-'0' ; 
               if (row[i][x]  || col[j][x]  )  
                   return 0    ;        
                row[i][x] = col[j][x] = 1;
                
                if ( box[i/3][j/3][x] ) return 0 ;
                box[i/3][j/3][x] = 1;
           }
        }
        
        return 1 ;
        
    }
};