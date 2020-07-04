class Solution {
public:
    vector<string> letterCombinations(string s) {
        vector<string> v ; 
        queue< pair <string , int > > q;
        int arr [] = {0,3,6,9,12,15,19,22} ;
        q.push({"" , 0}) ;
        while(!q.empty()) {
            
            string x = q.front().first ;
            int l = q.front().second; 
            q.pop() ;
            
            if (l == s.length()){
                if(x.length())
                v.push_back(x) ;
                continue ;
            }
            
            int p = s[l] - '0' , z    ;
            z = p == 7 || p == 9 ? 4 : 3 ;
            
            for (int i = 0 ;  i < z ; i++ ){
                char c = 'a' + arr[p-2] + i ;
                q.push( {x+c , l+1} ) ;
            }
            
        }
        
        
        
        
        return v ;
    }
};