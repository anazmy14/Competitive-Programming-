class Solution {
public:
      
    int nthUglyNumber(int n) {
        int arr[] = {2,3,4,5} ;
        priority_queue<long long> q; 
        vector<long long> v ;
        unordered_set<long long> s ;
        q.push(-1) ;
        
        while(1) {
            long long x = q.top() ;
            q.pop() ;
            if (s.find(x) != s.end()) 
                continue ;
            s.insert(x) ;
            v.push_back(-1*x) ;
            if(v.size() >= n ) break ;
            for( int i=0; i< 4;i++)
                q.push(x*arr[i]) ;                      
            
        }
        
        
        return v[n-1];
    }
};