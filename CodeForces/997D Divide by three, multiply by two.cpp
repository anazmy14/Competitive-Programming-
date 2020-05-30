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
 
	int gcd(int a, int b)
	{
		if (a == 0)
			return b;
		return gcd(b % a, a);
	}
 
	int lcm(int a, int b)
	{
		return (a*b)/gcd(a, b);
	}
 
	int fact(int n) {
		if (n == 0 || n == 1)
			return 1;
		else
			return n * fact(n - 1);
	}
 
 
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
 
		for ( pair < ull , int > x : v )
			cout << x.second << " "; 
 
	
 
 
 
 
		return 0 ;
 
	}