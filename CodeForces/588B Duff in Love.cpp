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

ull solve (ull n)  {
   ull x = 1 ;
   for ( ull i = 2; i*i <= n ; i++ ) { 
	   if ( n%i) continue ;
	   while ( n%i == 0 ) {
		   n /= i ;
	   }
	   x *= i ;   
   }
   if ( n> 1 ) x*= n; 

   return x; 
}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ull n ;
	cin >> n ;
	cout << solve(n) ; 
 
	return 0 ;
 
}