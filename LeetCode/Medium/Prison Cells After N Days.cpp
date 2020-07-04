class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& v, int n) {
        string s(8,'0'), z  ; 
        map<string , int> st ;
        for ( int i=0 ; i< 8 ; i++) s[i] = v[i]? '1' : '0' ;
        int cnt = 0 ;
        while ( st.size() < n) {
           z = s ;
          z[0] = z.back() = '0' ;
          cnt++ ;
          for ( int i = 1; i < 7 ;i++)
             z[i] = s[i-1] == s[i+1] ? '1' : '0' ;
             if ( st.find(z) != st.end() ) {
                 cnt -= st[z] ;
                 n -= st[z] ;
                 break ;     
             }
             st[z] = cnt ;
             s = z;           
             
        }
        
                
        int c = n%cnt ;
        while(c--) {
               s = z ;
        for ( int i = 1; i<7 ;i++){
              z[i] = s[i-1] == s[i+1] ?  '1' : '0'    ;     
            }
        }
       
        
       
        
       for ( int i=0 ; i<8; i++) v[i] = z[i] == '1'? 1 : 0 ;

        
        
        
        return v ;
    }
};