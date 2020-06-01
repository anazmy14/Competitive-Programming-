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
 
 

 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
 	int t; cin >> t ;
	while(t--) {
		string s ; cin >> s ;
		int n = s.length()+1 , mn = 100000 ;
		vector<int> v(n, 0) ,z(n , 0) ;
 
		for ( int i =0 ; i < n-1 ; i++ ) {
			if ( s[i] == '0') 
				z[i+1] ++ ;
			else 
				v[i+1]++ ;
			v[i+1] += v[i] ;
			z[i+1] += z[i] ;
		}
 
		for ( int i =1 ; i < n; i++ ){
			int x , y ; 
			x = i - (z[i] - z[0]) ;
			x += (n-1-i) - (v.back() - v[i-1]) ;
			
			y = i - (v[i] - v[0] ) ;
			y += (n-1-i) - (z.back() - z[i-1]);
			mn = min (x , mn ) ;
			mn = min (y, mn) ;
		}
 
		cout << mn << endl ;
		
	}
		
 
	
 
 return 0 ;
}