class Solution {
    public :
    map<int , string> m ;
    vector<int> v ;
    Solution () {
    string s = "IVXLCDM" ;
    int a[] = {1,5,10,50,100,500,1000} ;


    for ( int i =0 ; i < s.length(); i++ ){
        m[a[i]] = s[i] ;
        v.push_back(a[i]) ;
    }
        v.push_back(5000);
     }
   
    string intToRoman(int num) {          
        return solve(num) ;        
    }
    
    string solve(int x ) {
        if (m.find(x) != m.end())
            return string(m[x]) ;
  
        for( int i =0 ; i< 3; i++){
            int p = pow(10, i) ;
            if (x >= 4*p && x < 5*p )
                return solve(5*p-4*p) + solve(5*p) + solve(x-4*p) ;
            if (x >= 9*p && x < 10*p )
                return solve(10*p-9*p) + solve(10*p) + solve(x-9*p) ;                 
        }
        
        if (x < 5)
            return string(x ,'I') ;     
        for ( int i = 2 ;  i < v.size() ; i++){
            if (x < v[i]) 
                return solve(v[i-1] ) + solve( x-v[i-1]) ;            
        }
        return "" ;        
    }
    
};