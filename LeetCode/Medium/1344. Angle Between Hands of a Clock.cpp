class Solution {
public:
    double angleClock(int hours , int minutes) {
        
        
        double m = minutes , h = hours; 
        
        double x = minutes * 6;
        double y = (hours *30)%360 ;  
        
        y += (m/60)*30 ;

        return min ( abs(x-y) , 360-abs(x-y) ) ;
        
    }
};


