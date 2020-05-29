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
	int n , c = 0; cin >> n; 
	string s , z="RGB" ; cin >> s ;

	for ( int i =0 ; i< n-1 ; i++ ){
		if ( s[i] != s[i+1] ) 
			continue ;
		c++ ;
		if ( i == n-2 )  {
			if ( s[i] == 'R' || s[i] == 'G' ) s[i+1] = 'B' ;
			if ( s[i] == 'R' || s[i] == 'B' ) s[i+1] = 'G' ; 
			continue; 
		}
		for ( char x : z ) {		
			if( x != s[i] && x != s[i+2] ) {
				s[i+1] = x ;
				break ;
			}
		}

	}


	cout << c << endl << s ;

 
 
 
 
 
	return 0 ;
 
}