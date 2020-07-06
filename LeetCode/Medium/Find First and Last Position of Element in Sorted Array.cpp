class Solution {
public:
    vector<int> searchRange(vector<int>& v, int t) {
        vector<int> z ;
        if(!v.size()) return {-1,-1};
        
        int s = -1 , e=-1 , l = 0 , h = v.size()-1 ;
        
        while(l <= h) {
            int mid =(l+h)/2 ;
            if(v[mid] == t  ) 
                h = mid-1 , s = mid ;
            else if (v[mid] > t )
                h = mid-1 ;
            else
                l = mid+1 ; 
        }
        
        l = 0 , h = v.size()-1;
          while(l <= h) {
            int mid = (l+h)/2 ;
            if(v[mid] == t  ) 
                l = mid+1 , e = mid ;
            else if (v[mid] > t )
                h = mid-1 ;
            else
                l = mid+1 ; 
        }
        
        
        return{s,e} ;
                 
    }
};