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


struct disgoint {
	vector<int> rank;
	vector<int> parent ;
	disgoint(int n) {
		for ( int i = 0 ; i <= n ; i++ ) {
			parent.push_back(i) ;
			rank.push_back(0) ;
		}
	}

	int find ( int x ) {
		if( parent[x] != x ) 
			parent [x] = find(parent[x]) ;   
		return parent[x] ;
	}

	bool link (int x, int y) {
		int py = find(y) , px = find(x) ;
		if ( py == px )
			return 0 ;
		if ( rank[px] < rank[py] )
			swap(px ,py) ;
		if ( rank[px] == rank[py] ) rank[px]++ ;
		
		parent [py] = parent [px] ; 
		return 1; 
	}

};

	struct edge {
		int x,y , w, i ;
		bool d;
		edge() {d = 0;}

		bool operator < (const edge & e) const {
		return w > e.w;
	}
	};

	int n , m;
	vector<edge> getMst  (vector < edge> v , int &cost  ) {
		disgoint st(n)  ;
		vector  <edge> mst ; 
		priority_queue<edge>  q ;
		cost = 0 ;
		for ( int i = 0; i < m ; i++) {
			if (!v[i].d ) q.push(v[i]) ;
		}
	
		while(!q.empty() ){
			edge e  = q.top() ; q.pop() ;
			if( e.d ) continue ; 
			if  (st.link ( e.x , e.y ) ) {
				cost += e.w ;
				mst.push_back(e) ;
			}
		}
		

		return mst ;
	}


 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t ;

	while(t--){
		cout << t ;
		}

	return 0 ;
    
}