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
 


struct op {
	int x, y ; 
	ull d ;
};
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n, m , k ; cin >> n >> m >> k ;
	vector<ull> v(n) , p(n , 0) ;
	for ( int i=0 ; i < n ; i++ ) cin >> v[i] ;
	vector<op>o(m) ;
	vector<ull> z(m , 0 ) ;
	for ( int i=0; i < m ; i++ ) 
		cin >> o[i].x >> o[i].y >> o[i].d;
	
	while(k--) {
		int x , y ; cin >> x >> y ;
		x-- ; y--; 
		z[x]++ ;
		if ( y < m-1) 
			z[y+1]-- ;		
	}

	for ( int i=0 ;i < m ; i++ ) {
		if (i) 
			z[i] += z[i-1] ;

		o[i].d *= z[i] ;
		p[o[i].x-1] += o[i].d ; 

		if ( o[i].y < n ) 
			p[o[i].y] -= o[i].d ; 				
	}
 	v[0] +=  p[0] ; 
	for ( int i =1 ; i < n; i++ ) {
		p[i] += p[i-1]; 
	    v[i] += p[i] ;
	}

	for ( ull x: v) 
		cout << x << " " ;
 	
 
	
 
 return 0 ;
}