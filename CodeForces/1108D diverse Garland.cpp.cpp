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
  

	int cnt (ull x ){
		int c = 0 ;
		while( x%3 == 0) {
			c--;
			x/=3 ;
		}
		return c; 
	}

	int main () {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		int n ; cin >> n ;
		vector <pair< int , ull >> v(n);

		for( int i=0; i<n;i++ ) {
			cin >> v[i].second; 
			v[i].first = cnt(v[i].second) ;			
		}

		sort( v.begin() , v.end() );

		for ( pair < int , ull > x : v )
			cout << x.second << " "; 

	




		return 0 ;
 
	}