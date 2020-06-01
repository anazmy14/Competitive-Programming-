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
 
char change ( char c ) {
	if ( c >= 'a' ) 
		return 'A' + (c -'a') ;
	return 'a' + (c-'A') ;
}

 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	string s , t ; cin >> s >> t ;
	int y = 0 , w = 0 ;
	map< char , int> m ;
	queue<char> q; 
	for ( int i=0 ; i < t.length() ; i++ )
		m[t[i]] ++ ;

	for ( int i = 0 ; i< s.length() ; i++ ){
		if ( m[s[i]] ) {
			m[s[i]]-- ;
			y++ ;
			continue;
		}
		q.push(s[i]) ;
	}

	while (!q.empty() ){
		char c = change(q.front() );
		q.pop() ;
		if ( m[c] )  {
			m[c]-- ;
			w++ ;
		}

	}



	cout << y << " "<< w << endl ;
 
	
 
 return 0 ;
}