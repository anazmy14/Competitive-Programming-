#include<iostream> 
#include <vector> 
#include <string>
#include <map>
#include <algorithm> 
#include <deque> 
#include <set>
#include <cmath>
#define MKP make_pair
#define ull unsigned long long
using namespace std;
 
 
 
ull gcd(ull a, ull b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
 
ull lcm(ull a, ull b)
{
    return (a*b)/gcd(a, b);
}
 
 
 
ull nCr(ull n, ull r)
{
 
    ull p = 1, k = 1;
 
 
    if (n - r < r)
        r = n - r;
 
    if (r != 0) {
        while (r) {
            p *= n;
            k *= r;
 
            ull m = gcd(p, k);
 
 
            p /= m;
            k /= m;
 
            n--;
            r--;
        }
 
    }
 
    else
        p = 1;
 
    return p ;
}
 
ull power ( ull b , ull p ) {  
	
	if (!p) 
		return 1 ;
	if ( p%2)
		return b * power (b , p-1 ) ;
	
	return power(b , p/2) * power(b , p/2) ;   
}

 
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


		ull k, x =1 , y=1 , p1 = 10 , p2= 0  ; cin >>  k ; 
		string s = "codeforces" ;
		while ( power(x , p1) * power(y, p2) < k ) {
									
			if ( !p1 ) {
				x++ ;
				p1++ ;	p2-- ;
			}
			else if (!p2) {
				y++ ;
				p2++ ; 	p1-- ;
			}
			
			else if ( x <= y ) {
				p1 -- ;
				p2 ++ ;
			}
 
			else if ( y  < x ) {
				p2 -- ;
				p1 ++ ;
			} 		
 
		}
	 
		for ( int i = 0 ; i < 10 ; i++ ) {
			if ( i < p1 ) 
				cout << string(x , s[i] ) ;
			else 
				cout << string (y , s[i] ) ;
		}
 
 
 
 
 
 return 0 ; 
}