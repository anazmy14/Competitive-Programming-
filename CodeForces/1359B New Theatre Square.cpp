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
    int t ; cin >> t ;
 
	while (  t--) {
		int n , m ,x , y , p  , s =0 ;
		cin >> n >> m >> x >> y ;
		vector< vector<char> > v(n); 
		p = min (2*x , y ) ;
		for ( int i =0 ; i <n ; i++ ){
			for( int j =0 , z ; j <m ;j++ ) {
				char c ;
				cin >> c ;
				v[i].push_back(c) ;
			}
		}
	  
 
		for ( int i =0 ; i <n ; i++ ){
	
			for ( int j = 0; j < m; j++ ){
				if( v[i][j] == '*' ) continue ; 
				if ( j < m-1 && v[i][j+1] == '.' ) {
					s += p ;
					v[i][j+1] = '*' ;
				}
				else 
					s += x; 
			}
 
		}
		cout << s << endl ;
	}
 
 
 
 
 
 
	return 0 ;
 
}