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

	int t ; cin  >> t ;
	while (t--) {

		int n , l = 10000000 ; cin >> n ; 
		vector<int> v(n+1 , 0 ) ; 
		ull s = 0 ;

		for ( int i =0, x ; i < n ; i++ ) {
			cin >> x ;
			v[x] ++ ;
		}

		sort( v.begin() , v.end() ) ;

		for ( int i = n ; i > 0 ; i--) {
			int x = min ( v[i] , l ) ;
			s += x ;
			l = x - 1 ; 
			if(l <= 0)
				break;

		}

		cout << s <<endl  ;

	
		
	}
 
 
 
 return 0 ; 
}