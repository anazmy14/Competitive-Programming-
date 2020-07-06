class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        queue<pair <string , pair <int,int> >> q ;
        q.push({"" , {0 ,0 }} ) ;        
        while(!q.empty()){
            string s = q.front().first ;
            int x = q.front().second.first ,  y ; 
            y= q.front().second.second ;
            q.pop() ;
            
            if(s.length() == n*2){
                v.push_back(s) ;
                continue ;
            }
            
            if(x > y)
                q.push({ s+')' , {x , y+1}}) ;
            if (x < n) 
                q.push( {s+'(' , {x+1, y }} ) ;            
            
        }
        
        return v; 
        
    }
};