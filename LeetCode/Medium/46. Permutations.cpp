class Solution {
public:
    vector<vector<int>>z ;
    vector<int> v ;
    unordered_map<int, bool>  m ;

    vector<vector<int>> permute(vector<int>& nums) {
        
        solve(nums) ;
        return z; 
        
    }
    
    void solve(vector<int> nums) {
        if( v.size() == nums.size())
            return z.push_back(v) ;
        
        for(int i=0 ; i < nums.size(); i++){
            if(m.find(nums[i]) != m.end() )
                continue ;
            v.push_back(nums[i]) ;
            m[nums[i]] = 1; 
            solve(nums) ;
            v.pop_back() ;
            m.erase(nums[i]) ;
        }
       
    }
    
    
    
};