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
	int t; cin >> t ;
	while( t--){
		int n , x = 0 , y = 0 ; cin >> n ; 
		vector<int> a , b ;
		vector <pair <int ,int> >v ; 
 
		for ( int i =0 , z; i< 2*n ; i++ )  {
			cin >> z ;
			
			if ( z%2 ) {
				a.push_back(i+1) ;
				x ++ ;
			}
			else {
				b.push_back(i+1) ;
				y++ ;
			}
		}
 
		for ( int i = 0 ; i < a.size()-1 ; i+=2 ) 			
			v.push_back( MKP (a[i] , a[i+1]) ) ;
		for ( int i = 0 ; i < b.size()-1 ; i+=2) 
			v.push_back( MKP ( b[i] , b[i+1]) ) ;
 
		for ( int i =0 ; i < n-1 ; i++ )
			cout << v[i].first << " " << v[i].second  << endl ;
 
		
	}
 
 
 
 
	
		 
 
 return 0 ; 
}