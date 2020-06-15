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

bool solve (pair<ull , ull > x , pair <ull , ull> y ) {
	if ( x.first >= y.first && x.first <= y.second) 
		return 1 ;
	if ( x.second >= y.first && x.second <= y.second ) 
		return 1 ;
	if ( y.first >= x.first && y.first <= x.second) 
		return 1 ;
	if ( y.second >= x.first && y.second <= x.second ) 
		return 1 ;
	
	return  0 ;
}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    int t; cin >>t ;
	while ( t--) {
		ull n,m,x, l , r ; cin >> n >>x >> m  ;
		pair <ull, ull>  p; 
		p = MKP( x , x ) ;
		while ( m--) {
			cin >> l >> r ; 
			if (solve ( p , MKP(l,r)))
				p = MKP( min(p.first , l ) , max ( p.second , r ) ); 
		}

		cout << p.second+1 - p.first << endl ;
	
	}
	

 return 0 ; 
}
