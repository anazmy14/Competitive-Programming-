#include<iostream> 
#include <vector> 
#include <string>
#include <map>
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
	long long n , m = 0 ; 
	map<int , long long > mp ; 
	cin >> n ; vector<int> v(n) ;
	for ( int i =0 ; i <n ; i++ ) {
		cin >> v[i] ;
	    mp[v[i] - i ] += v[i] ;    
		if ( mp [v[i] - i ]  > m ) 
			m = mp[v[i]-i] ;
	}
	

	cout << m ;

 return 0 ;
}
