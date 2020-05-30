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
 
int v[3] = {2,3,5} ;
 
 
vector<int> solve ( long long n ){
	vector<int>a(6,0) ; 
	for ( int i = 0 ; i < 3 ; i++ ) {
		while ( n%v[i] == 0 ) {
			a[ v[i] ]++ ;
			n /= v[i] ;
		}
	}
	return a ;
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	long long x , y , c = 0  ; cin >> x >> y ;
	vector<int> a = solve(x) ,  b = solve(y) ;
 
	for ( int i=2; i < 6 ; i++ ){
		if ( a[i] > b[i] ) {
			x /= pow ( i , (a[i] - b[i]) ) ; 
			c += a[i] - b[i] ;
		}
		else if ( b[i] > a[i] ) {
			y /= pow( i , (b[i] - a[i]));
			c += b[i] - a[i] ;
		}
	} 
 
 
    if ( x==y ) 
		cout << c ;
	else
	    cout << -1 ; 
 
 
	return 0 ;
 
}