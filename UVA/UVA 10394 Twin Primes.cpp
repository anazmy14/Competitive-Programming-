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
vector< pair<int ,int> > v ;

void getPrimes() {
	int n = 20000009 ;
	isPrime.resize(n+1 , 1 ) ;
	for ( int i = 2 ; i*i <= n; i++ ) {
		if ( !isPrime[i] ) continue ;
		for ( int j = i+i ; j <= n ; j+=i )
			isPrime[j] = 0;   
	}

	for ( int i = 2 ; i < n-2 ; i++ ) { 
		if ( isPrime[i] && isPrime [i+2] )  {
			v.push_back( MKP( i , i+2 ) ) ;
		}
	}

}






int main () {
   // ios_base::sync_with_stdio(false);
   // cin.tie(NULL);
    int n ;
	getPrimes();
	 while(scanf("%d",&n)==1)
    {
		int x = n-1 ;
		printf("(%d, %d)\n",v[x].first,v[x].second);
		//cout << '(' << p[x] << "," << " " << p[x+1] << ')';
	}


	return 0 ;
 
}