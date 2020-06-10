#include<iostream> 
#include <vector> 
#include <string>
#include <map>
#include <algorithm> 
#include <deque> 
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
	long long n , k , m , s  , d , c = 1 ; cin >> n >> k ;
	vector<long long> v(n);
	for( int i=0; i <n ;i++ )
		cin >> v[i] ;
	sort(v.begin() , v.end());
	m = n/2 ;
	s = v[m];

	for ( int i =m ; i < n-1 ; i++ ) {
		d = v[i+1] - v[i] ;
		if ( k >= d*c ) 
			k -= d*c ;
		else 
			break ;
		s = v[i+1] ;
		c ++ ;
	}
    
	 
	cout << s + k/c ;


 return 0 ;
}
