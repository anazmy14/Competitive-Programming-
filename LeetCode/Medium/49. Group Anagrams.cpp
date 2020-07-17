class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> v ;
        map<string , int > m ;
        for( string s : strs){
            string key = s; 
            sort(key.begin() , key.end() ) ;
            if(m.find(key) == m.end()){
                v.push_back({s}) ;
                m[key] = m.size() ;
            }
            
            else 
                v[m[key]].push_back(s) ;            
            
        }
        
        
        return v ;
    }
};