class Solution {
public:
    void nextPermutation(vector<int>& v) {
        int n = v.size() , mx = INT_MIN , p = n , l   ;
        bool k = 1;
            
        for( int i= n-1 ; i >= 0 ; i-- ) {
            if (v[i] < mx ){
                k = 0 ;
                p = i ;
                break ;
            }   
            mx = max(mx , v[i]) ;                    
        }

        for ( int i= p+1;  i < n; i++ ){
            if(v[i] > v[p] && v[i] <= mx  ){
                mx = v[i] ;   
                l = i ;
            }
        }       
        
        
        
        if(k)
            sort(v.begin() , v.end()) ;
        else {
            swap(v[l] , v[p]) ;
            sort(v.begin()+p+1 , v.end());
        }
    }
};

