class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& v, int t) {
        int n= v.size() ;
        sort(v.begin() , v.end()) ;
        vector<vector<int>>z ;
        
        for( int i= 0 ; i < n ; i++) {
            if (i && v[i] == v[i-1] ) continue ;
            for( int j = i+1 ; j <n; j++) {
                if ( v[j] == v[j-1] && j > i+1) continue;
                int l =  j+1 , r =n-1 , x; 
                x = t - (v[i]+v[j]);
                int pl , pr ; 
                while( l < r){
                    int y = v[l] + v[r] ;
                    if( y> x) r-- ;
                    else if ( y < x ) l++ ;
                    else {
                        z.push_back({v[i] , v[j] , v[l] , v[r]}); 
                        pl = l ;
                        pr = r ;
                        while (l < r){
                           l = v[pl] == v[l] ? l+1 : l ;
                           r = v[pr] == v[r] ? r-1 :  r ; 
                           if(v[pl] != v[l] && v[pr] != v[r])
                               break;
                        }
                  
                    }
                    
                }
                    
            }
        }
     

        
     
        return z ;
        
    }
    
};