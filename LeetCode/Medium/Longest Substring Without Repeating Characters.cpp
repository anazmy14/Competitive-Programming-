class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = -1  ,  c = 0 , mx = 0 ;
        map<char , int>  m ;
        for ( int i = 0 ; i < s.length() ; i++) {
            if ( m.find(s[i]) != m.end() && m[s[i]] > l  ) {
                mx = max( c , mx ) ;
                c =  i-m[s[i]] ;
                l = m[s[i]] ;
                m [s[i]] = i ;                
                continue; 
            }
            c ++;             
            m [s[i]] = i ;
        }
        mx  = max( mx , c) ;
        
        return mx ;        
    }
};