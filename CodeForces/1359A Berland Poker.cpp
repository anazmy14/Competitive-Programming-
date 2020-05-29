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
		int n , m , k , h , h2 , c ;
		cin >> n >> m >> k ;
		c = n/k ;
		h = min (c , m ) ;
		m -= h ;
 
		h2 = m/(k-1) ; 
		if ( m % (k-1) ) h2++;
 
		cout << h - h2 << endl ;
	}
 
 
 
 
 
 
	return 0 ;
 
}