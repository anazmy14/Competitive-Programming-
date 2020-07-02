class Solution {
public:
    int maxArea(vector<int>& v){
        int l = 0 , r = v.size()-1 ;
        int mx = min(v[l] , v[r]) * (r-l) ;
        while (l < r ){
            if (v[l] < v[r])
                l++; 
            else 
                r--;
            int x =(r-l) * min(v[l] , v[r]);
            mx = max(x , mx) ;
         }
        
        return mx  ;
        
    }
};


/*
   i+x - i * a[i+x] - a[i]  
      
*/