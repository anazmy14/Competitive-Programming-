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
	long long  n , k , s ; cin >> n >> k ;
	vector<long long>v(n) , z;

	for ( int i =0 ;i <n ;i++) {
		cin >> v[i] ;
	}
	s = v.back() - v.front() ;
	
	for ( int i =0 ; i <n-1 ; i++ ) {
		z.push_back(v[i] - v[i+1]) ;
	}
	sort(z.begin() , z.end() );

	for ( int i = 0 ; i < k-1 ;i++)  
		s += z[i] ;

	cout << s ;




 return 0 ;
}
