#include<iostream> 
#include <vector> 
#include <string>
#include <map>
#include <algorithm> 
#include <deque> 
#include <set>
#include <cmath>
#define MKP make_pair
#define ull unsigned long long
using namespace std;
 
 
 
ull gcd(ull a, ull b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
 
ull lcm(ull a, ull b)
{
    return (a*b)/gcd(a, b);
}
 
 
 
ull nCr(ull n, ull r)
{
 
    ull p = 1, k = 1;
 
 
    if (n - r < r)
        r = n - r;
 
    if (r != 0) {
        while (r) {
            p *= n;
            k *= r;
 
            ull m = gcd(p, k);
 
 
            p /= m;
            k /= m;
 
            n--;
            r--;
        }
 
    }
 
    else
        p = 1;
 
    return p ;
}
 
ull power ( ull b , ull p ) {  
	
	if (!p) 
		return 1 ;
	if ( p%2)
		return b * power (b , p-1 ) ;
	
	return power(b , p/2) * power(b , p/2) ;   
}
 
struct dsu {
	int n ;
	vector<int> rank ;
	vector<int> parent ;
	vector<int> sz ; 
	dsu ( int x) {
		n = x ;
		for ( int i= 0 ; i <= n ; i++ ) {
			parent.push_back(i) ;
			rank.push_back(1) ;
			sz.push_back(1) ;
		}
	}
 
	int find (int x) {
		if ( parent[x] == x )
			return x ;
		return parent[x] = find ( parent[x] ) ;
	}
 
	void link ( int x , int y ) {
		int px = find(x) , py = find(y) ;
		if ( px == py ) 
			return ;
		
		if ( rank[px] > rank[py] ) {
			parent[py] = px ; 
			sz[px] += sz[py];
		}
		else if ( rank [py] > rank [px] ) {
			parent[px] = py ;
			sz[py] += sz[px] ;
		}
 
		else {
			rank[px]++ ;
			sz[px] += sz[py] ;
			parent[py]= px ;
		}
	}
 
 
 
};


 
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	string s , z = "" ; cin >> s ;
	vector<int>v ;
	int c =	1 ;
	s.push_back(' ') ;

	for ( int i = 1 ; i < s.length() ; i++ ) {
		if ( s[i] == s[i-1] && i < s.length()-1){
		   c++ ;
		   continue ;
		}

		if (s[i] == s[i-1] ) c++ ;
			 
		if ( c > 1 )
				 v.push_back(2) ;
        else 
				 v.push_back(1);
			 z += s[i-1] ;	
			 c = 1 ;
		
	}

	
   
	for ( int i = 1 ; i < v.size() ; i++ ) {
		if ( v[i] == 2 && v[i-1] == 2 ) {
			v[i] = 1 ;
		}
	}


	for ( int i = 0 ; i < z.length() ; i++ ) 
		for (int j = 0 ; j < v[i] ; j++ )
			cout << z[i] ;
		
	
		 
 
 return 0 ; 
}