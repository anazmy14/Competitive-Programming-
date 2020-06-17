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
		int n , c = 0 ; cin >> n; 
		vector<int> v(n),z ; 
		
		for (int i = 0; i < n ; i++ ) 
			cin >> v[i] ;
		int p = v[0] ;
		z.push_back(v[0]) ;
		for ( int i = 1 ; i < n-1 ;i++ ){
			if ( v[i] > p && v[i] < v[i+1] ){
				c ++ ;				 
				continue ;
			}

			else if ( v[i] < p && v[i] > v[i+1] ) {
				c++ ; 
				continue ;
			}

			z.push_back(v[i]);
			p = v[i] ;
		}
		z.push_back(v.back() );


		cout << n-c << endl ;
		for( int x : z ) 
			cout << x << " " ;
		cout << endl ;
	
	}


 
 
 return 0 ; 
}