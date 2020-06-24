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


vector<int> sieve (int n) {
	vector<int> v(n+1 , 1 ) ;

	for ( int i = 2; i <= n ; i++ ) {
		if ( !v[i] ) continue ;
		for ( int j = i+i ; j <= n  ; j+=i ) 
			 v[j] = 0 ;
	}

	return v ;

}

int  nine ( ull x ) {
	int c = 0 ;
	while(x) {
		if ( x%10 == 9 ) 
			c++ ;
		else 
			return c; 
		x /=10;  
	}  
	return c; 
}


 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	long long  n , d , a  ; cin >> n>> d ;
    a = n ;

	for ( int i =1 ; i < 19 ; i++ ) {
		long long x = stoll (string( i , '9' )) , y, m ;
		y = n - x ; 
		m =  pow( 10 , i ) ; 
		x += (y/m)*m ; 

		if ( x <= n && n-x <= d ) 
			a = x ;
		else 
			break ;
	}

	cout <<  a ;

 return 0 ; 
}