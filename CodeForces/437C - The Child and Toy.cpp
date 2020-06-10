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
	int n , m ; cin >> n >> m ; 
	ull s = 0 ;
	vector<int> v(n+1) ;
	for( int i=0 ;i < n;i++) {
		cin >> v[i+1] ; 
	}

	while(m--) {
		int x , y ; cin >> x >> y ;
		s += min (v[x] , v[y]) ;	
	}

	cout << s ;



 return 0 ;
}
