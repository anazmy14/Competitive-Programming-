#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <unordered_set>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <list>
#include <set>
#include<map>
#include <queue>
#include <stdio.h>
#include "cstring"
#include<cmath>
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

int log2 (ull x , ull y ){
	int c = 0 ; 
	while ( y < x ) {
		y *= 2 ;
		c++; 
	}
	if (x != y )
		c = -1 ; 
	return c; 
}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t ; cin >> t ;
	
	
	
	while( t-- ) {
		ull a , b , x , l , c = 0 ; cin >> a >> b ;
		if (b > a ) swap(a,b) ;
				
		l = log2( a, b) ;
		if ( l == -1 ) {
			cout << -1 << endl ; 
			continue ;
		}
		for ( int i =3 ; i >0 ; i-- ) {
			if (!(l/i) )
				continue ;
			c += l/i ;
			l =l%i ;
		}
		
			cout << c << endl ;
	}


 
 return 0 ;
}