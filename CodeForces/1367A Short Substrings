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
 
 
 
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int t ; cin >> t ;
	while ( t--) {
		string a = "" , b ; cin >> b ;
		a += b[0] ;
		for ( int i =1 ; i < b.length()-1 ; i+=2 ){	
			a += b[i] ;
		}
		a += b.back() ;
 
		cout << a << endl ;
	
	
	}
 
 
 
 
 return 0 ; 
}