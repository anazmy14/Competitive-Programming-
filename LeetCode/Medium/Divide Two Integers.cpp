class Solution {
public:
    int divide(long long x, long long d) {
        int sign = ( (x < 0) ^ (d < 0 ) ) ? -1 : 1;
        if( x == INT_MIN &&  d == -1  )
            return INT_MAX ;
        
        x = abs(x) ; 
        d = abs(d) ;
        long long p = 1 , c = 0 , y  = d , z = 1  ;             
        
        
        while (1) {
           if (y << 1 <= x)
               y = y << 1 ;
           else
                break ;      
            z = z << 1 ;
           
        }
        
        if (z >  1) {
            x -= y ;
            c +=  z ;
        }
      
        while( x >= d ){
            x -= d ;
            c++; 
        }        
        
        
        return c*sign ;
                
    }
};