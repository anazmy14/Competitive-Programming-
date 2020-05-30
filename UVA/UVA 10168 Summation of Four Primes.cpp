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
vector<int> isPrime ; 
vector <int> p ;  
void getPrimes() {
	int n = 10000000 ;
	isPrime.resize(n+1 , 1 ) ;
	for ( int i = 2 ; i*i <= n; i++ ) {
		if ( !isPrime[i] ) continue ;
		for ( int j = i+i ; j <= n ; j+=i )
			isPrime[j] = 0;   
	}

	for ( int i = 2 ; i <= n ; i++ ) { 
		if(isPrime[i]) p.push_back(i);
	}

}

int find (int x) {
	int l = 0 , h = p.size()-1, mid , m = 0 ;

	while (l <= h ) {
		mid = (l+h)/2 ;
		if (p[mid] == x) return x ;
		if ( p[mid] > x )
			h = mid-1 ;
		else {
			m = mid ;
			l = mid+1 ;
		}
	}
	return p[m] ;
}




int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n ;
	getPrimes();

	while ( cin >> n) {
		vector<int> v(4);  
		int x = n,  s= 0 ,  c=6 ; 
		for ( int i =0 ; i< 4 ;i++) {
    		v[i] = find(n-c) ;
			s += v[i] ;
			c -= 2 ;
			n -= v[i] ;
		}
		if ( s!=x) {
			cout << "Impossible." << endl ; continue ;
		}
		for ( int x:v) cout << x << " ";
		cout << endl ;
	}

	return 0 ;
 
}