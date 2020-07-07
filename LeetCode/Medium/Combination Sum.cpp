class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& c , int t) {
        vector<vector<int>> z ;
        vector<int>v; 
        int s = 0; 
        solve(c,t,v,s,z);
        
        return z;
    }
    
  void solve ( vector<int> c , int t,  vector<int> v , int s , vector<vector<int>> &z  ){
      if ( s == t) {
          z.push_back(v) ;
          return;
       }
      
      for ( int i =0 ; i < c.size(); i++){
          if ( s + c[i] > t ) continue ;
          if (v.size() && v.back() > c[i] ) continue;
          v.push_back(c[i]) ;
          s += c[i] ;
          solve(c,t,v,s,z) ;
          v.pop_back(); 
          s -= c[i];
          
      }
      
  }  
    
};