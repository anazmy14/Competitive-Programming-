class Solution {
public:
     vector<vector<int>> z ;
    vector<vector<int>> subsets(vector<int>& nums) {
        
        solve(0 ,nums ,{}) ;
        return z ;
                
    }
    
    
    void solve(int p , vector<int>v , vector<int> sub ) {
        if (p >= v.size()) {
            z.push_back(sub) ;
            return ;
        }
        
        solve(p+1 , v ,sub) ;
        sub.push_back(v[p]) ;
        solve(p+1,v,sub) ;        
    }
    
};