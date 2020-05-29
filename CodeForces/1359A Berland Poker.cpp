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