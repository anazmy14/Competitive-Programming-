#include<iostream> 
#include <vector> 
#include <string>
#include <map>
#include <algorithm> 
#include <deque>
#include<queue> 
#include <set>
#include <cmath>
#define MKP make_pair
#define ull unsigned long long
#define ll long long
using namespace std;
 
 
 
ull gcd(ull a, ull b)
{
    if (a == 0)
        return b;
	if (b == 0 ) 
		return a ;
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
 
long long power (long long b , long long p , long long m ) {  
	
	if (!p) 
		return 1 ;
	if ( p%2)
		return (b * power (b , p-1 , m ))%m ;
	
	ull  x = power(b , p/2 , m ) ;   
 
	return (x * x)%m ;   
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

int n ; 
bool valid[1025] ;

bool ok( int x , vector<int> v){
	for ( int i = 0 ; i < n  ; i++ ) {
		if( !valid [v[i] ^ x] )
			return 0 ;
	}
	return 1 ;
}
 
 
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int t; cin >> t ;
 
	while(t--){
		bool b = 1 ; 
		int a = 1000000 ;
		cin >> n ;
		vector<int> v(n) ;
		for( int i =0 ; i < 1025; i++ ) valid[i] = 0 ; 
		for( int i=0; i < n ; i++){
			cin >> v[i] ;
			valid[v[i]]=1;
		}

		for ( int i =1 ; i < n ;i++ ){
			int x = v[0] ^ v[i] ;
			if (ok(x , v)) {
				b = 0 ;
				a = min(a ,x );

			}

		}

		if(b) cout <<-1 << endl ;
		else 
			cout << a<< endl ;
		
	
 
 
	}
 
 
 
 return 0 ; 
}