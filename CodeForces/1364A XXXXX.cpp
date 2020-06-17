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
 
char find ( int n ,  map<char, int > &m ) {
	for ( int i = 25 ; i >= 0 ; i-- ){
		if ( m['a'+i] >= n ) {
			m ['a' + i] = 0 ;
			return 'a' + i ;
		}
	}
}
 
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int t ; cin >> t ;
	while ( t--) {
		ull x , s = 0 ;
		bool k = 0 ;
		int n , mn ;
		cin >> n >> x ;
		mn = n ;
 
 
		for ( int i =0,z ; i<n; i++ ){
			cin >> z ;
			s += z ;
			if ( z % x ) {
				k = 1 ;
				mn = min( i+1 , mn ) ;
				mn = min (n-i , mn) ; 
			}
		}
 
		if ( s%x ) 
			cout << n ;
		else if (!k) 
			cout << -1 ;
		else 
			cout << n - mn ;
		cout << endl ;
	
	}
 
 
 
 
 return 0 ; 
}