class Solution {
public:
    double myPow(double x ,  int n) {
        
        if ( n == 0 )
            return 1 ;
        if(n&1)
            return pow(x,1 ) * myPow(x,n-1) ;
        
        if(n == 2 || n == -2 )
            return pow(x,n) ;
        
        double z = myPow(x ,n/2); 
        
        return z *z ;
    }
    
    
   
};