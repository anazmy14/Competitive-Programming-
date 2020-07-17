class Solution {
public:
    vector<int> topKFrequent(vector<int>& v, int k) {
        unordered_map<int ,int> m ;
        unordered_map<int , unordered_set<int> > m2 ;
        vector<int> z ;
        int n = v.size() ;
        
        for( int i = 0 ; i < n ; i++) {
            int f =  m[v[i]]++ ;
            m2[f].insert(v[i]) ;
            if(f > 1 )
              m2[f-1].erase(m2[f-1].find(v[i])) ;
        }
        
        while( n--) {
            for(int x : m2[n] ){
                if(!k)
                    break ;
                z.push_back(x) ;
                k--; 
            }
        }
        
      return z ;
        
        
    }
};