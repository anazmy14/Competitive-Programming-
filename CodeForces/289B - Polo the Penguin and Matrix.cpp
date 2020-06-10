#include<iostream> 
#include <vector> 
#include <string>
#include <map>
#include <algorithm> 
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
	int n , m , mid, d , z = -1 ; cin >> n >> m >> d ; 
	ull s = 0 ;
	vector<int> v;

	for( int i =0,x; i<n*m; i++){ 
			cin >> x ;
			if( z != -1 && x%d != z ) {				
				cout << -1 ; return 0 ;		
			}
			z = x %d ;
			v.push_back(x) ;
	}
	sort (v.begin() , v.end() );
	mid = v[(n*m)/2] ;

	for ( int i = 0; i <n*m ;i++ ) {
		s +=  abs (v[i] - mid)/d ;	 
	}

	cout <<s ;





 return 0 ;
}
