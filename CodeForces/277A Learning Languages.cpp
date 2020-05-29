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
 
 
 
struct disjoint {
	vector<int> rank ;
	vector<int> parent ;
 
	disjoint (int m) {
		for( int i= 0; i < m+1 ; i++ ) {
			rank.push_back(0) ;
			parent.push_back(i) ;
		}
	}
 
	int find ( int x) {
		if ( parent[x] != x ) 
			return parent[x] = find( parent [x])  ;
		return x ;
	}
 
	void link ( int x , int y) {
		x = find(x) , y  = find (y) ;
		if ( x == y ) 
			return ;
		if ( rank [y] > rank[x] ) 
			swap(x ,y) ;
		if ( rank[y] == rank[x] ) 
			rank[x]++ ;
		parent[y] =  x ;
	}
 
};
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n , m , c = 0 ;
	cin >> n >> m ;
	disjoint st (m) ;
	unordered_set<int> s , z ;
	for ( int i = 0 ; i < n ; i++ ) {
		int k , x = 0 ; cin >> k ;
		if (!k) c++ ;
		while (k--) {
			int l ; cin >> l ; 
			z.insert(l) ;
			if (x) 
				st.link( l , x ) ;
			x = l ;			
		}
	}
 
	for ( int i =1 ; i <= m ; i++ ) {
		int p = st.find (i) ;
		if ( z.find( p ) != z.end() )
			s.insert(p) ;
	}
	if ( s.size() )
		c += (s.size()-1) ;  
	
	cout << c ;
    
	return 0 ;
 
}