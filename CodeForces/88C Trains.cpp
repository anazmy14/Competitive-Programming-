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
  



int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ull  a,b, x, y , l   ; 
	cin >> a >> b ; 
	l =  lcm(a,b)-1 ;

	x = l /a ; y = l/b ;
	x < y ? x++ :  y++ ;


	if (x > y)
		cout << "Dasha" ;
	else if(x < y) 
		cout << "Masha" ;
	else 
		cout << "Equal";

 
 return 0 ;
}