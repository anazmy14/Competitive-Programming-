class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& v) {
        int n = v.size() ;
        vector<vector<int>> z ;
        unordered_map<int , int> s; 
        sort(v.begin() , v.end()) ;
        for( int i=0; i<n ; i++ ) s [v[i]]= i ;
        
        for ( int i=0; i <n ; i++) {
            if (i && v[i] == v[i-1] ) continue; 
            
            for ( int j = i+1 ; j <n ;j++) {
                int x = v[i] + v[j] ;
                x *=-1; 
                if (s.find(x) != s.end() && s[x] > j) 
                    z.push_back({v[i] , v[j] , x}) ;

                j = s[v[j]] ;
             
            }
        }
      
        
        return z ;
        
    }
};