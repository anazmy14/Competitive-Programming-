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
 
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int t ; cin >> t ;
	while ( t--) {
		int k, n , c = 0 , l = 0 ; cin >> n >> k ;
		string s ; cin >> s ;
		for ( int i =0 ; i < n ; i++ ) {
			if( !i ) {
				if ( s[i] == '0' ) 
					c++ ;
				continue ;
			}
			if ( s[i] == '0' && i - l > k ) {
				c++ ;
				l = i ;
			}
			else if (  s[i] == '1' && i - l <= k ) {
				c--; 
				l = i ;
			}
			else if ( s[i] == '1' )
				l = i ; 	
		}
 
		cout << c << endl ;
 
	
	}
 
 
 
 
 return 0 ; 
}