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
		int n , x , od = 0 , ev = 0 ; cin >>n>> x; 
		bool k = 0; 
		for ( int i=0, z; i < n; i++ ){
			cin >> z ;
			if ( z%2) od++ ;
			else ev++; 
		}
		for ( int i = 1 ; i <= od; i+=2 ){
			for ( int j = 0 ; j <= ev ; j++ ){
				if ( i+j == x )
					k = 1; 				
			}
		}
 
		if ( k) 
			cout << "Yes" ;
		else 
			cout << "No";
		cout << endl ;
	}
		
 
	
 
 return 0 ;
}
