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
	
    int t; cin >> t ;
	while ( t--) {
		int n , m , s = 0 ; cin >> n >> m ;
		vector<int> v(n+m , 0) , z(n+m , 0) ;
		m-- ; n-- ;
		
		for ( int i =0 ; i <= n ;i ++ ) {
			for ( int j =0,x ; j <= m; j++ ) {
				cin >> x ;
				int p = n-i ; 
				p += (m-j) ;
				p = min( p , i+j) ;
				x ? v[p]++ : z[p]++ ;
			}
		}

		for ( int i = 0; i < n +m ; i++ ) {
			if ( (n+m+1)%2 && i == (n+m+1)/2) 
				continue ; 
			s += min ( v[i] , z[i]) ;
		}

		cout << s << endl ;
	
	}
	

 return 0 ; 
}
