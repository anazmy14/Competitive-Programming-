class Solution {
public:
    int threeSumClosest(vector<int>& v, int t) {
        int a , z = 1000000 , n = v.size()  ;
        sort(v.begin() , v.end()) ;
        for ( int i =0 ; i < n ; i++ ) {
           int l = i+1 , r =n-1 ,x,d ; 
           
            while ( l < r ) {
               x = v[i] + v[l] + v[r] ;
                if (abs(x-t) < z )
                   a = x , z = abs(x-t); 
               x > t ?  r-- : l++ ;
            }
            
        }
        
        return  a ; 
        
    }
};