class Solution {
public:
    string x = "";
    string reverseWords(string s) {
        solve(0 , s) ;        
        return x ;        
    }
    
    void solve(int p , string s ) {
        if(p >= s.length() )
            return ;
        string z = "";
        while (p < s.length() && s[p] != ' ') {
            z += s[p] ;
            p++; 
       }      
       
        
       solve(p+1 , s) ;
       if (z.length() && x.length()  )
            x += " " ;
       x += z ;         
        
    }
    
};