class Solution {
public:
    string convert(string s, int n) {
        string x = "";
        vector<string> v(n, "");  
        int c = 0 ;
        while ( c < s.length() ) {
            for ( int i =0 ; i < n && c < s.length(); i++ ) {
                v[i] += s[c] ;
                c ++ ;
            }
            
            for ( int i = n-2 ; i > 0  && c < s.length(); i-- ) {
                v[i] += s[c] ;
                c ++ ;
            }                   
            
            
        }
        
        for ( int i = 0 ; i < n ; i++ )
            x += v[i]  ;
     
        return x ;
    }
};