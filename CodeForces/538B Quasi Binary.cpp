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
    int n  , c = 0 , p = 1 ; cin >> n ;
	vector<int> v ;
	while ( n) {
		int x = n ;
		c =0 ;
		p = 1 ;
		while (x) {
			int m = x%10 ;
			if (m) 
				c += p ;
			x /= 10 ;
			p *= 10 ;
		}
		v.push_back(c) ;
		n -= c ;
	}
 
	cout << v.size() << endl;
 
	for ( int x : v ) {
		cout << x << " " ;
	}
 
 
 
	return 0 ;
 
}