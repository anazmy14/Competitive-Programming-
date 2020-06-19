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


		int n; cin >> n ; 

		cout << 3*n+4 << endl ;
		cout << 0 << " " << 0 << endl ;
		cout << 0 << " " << 1 <<  endl; 
		
		for ( int i = 1 ; i <= n; i++ ) {
			for( int j = i-1 ; j < i+2; j++ ) 
				cout << i << " " << j  << endl ;  
		}
		cout << n+1 << " " << n << endl ;
		cout << n+1 << " " << n+1 << endl ;
		
 
 
 
 return 0 ; 
}