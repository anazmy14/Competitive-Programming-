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


int p[3] , q[3] , r[3] ;


 ull price  (ull n)  {
	 ull s = 0 ;
	 for ( int i = 0; i< 3; i++ ){
		 if (q[i] < r[i]*n ) 
			 s += (r[i]*n - q[i]) * p[i] ;
	 }
	 return s; 
 }



int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	string s  ; cin >>s  ;
	
	ull m ; 
	for (char x : s ) {
		if ( x == 'B') r[0] ++;
		else if ( x == 'S' ) r[1]++ ;
		else r[2] ++ ;	
	}

	for ( int i =0 ; i < 3; i++ ) cin >> q[i] ;
	for ( int i=0; i <3; i++ ) cin >> p[i] ;
	cin >> m ;

	ull l = 0 , h = 10e12 , mid , c ;

	while (l <= h)
	{
		mid = (l+h)/2 ;
		ull x = price (mid) ;
		if ( x == m ) {
			c = mid ;
			break; 
		}
		 if ( x > m ) 
			 h = mid-1 ;
		 else {
			 c = mid ;
			 l = mid+1 ;
		 }
		
	}


	 cout << c ;
	return 0 ;
 
}