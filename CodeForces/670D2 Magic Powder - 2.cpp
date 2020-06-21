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

int n ; 
vector<ull> a , b ;

bool ok (ull x, ull k ) {

	for ( int i =0 ; i < n ; i++ ) {
		ull z = a[i]*x ; 
		if ( b[i] >= z ) 
			continue ;

		if ( z - b[i] <= k )
			k -= (z - b[i]) ;
		else
			return 0 ;	
		
	}

	return 1 ;
}


 
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	ull  k , c =0 ;  cin >> n >> k ; 
	
	for (int i = 0,x; i < n; i++)
		cin >> x , a.push_back(x) ;
	for ( int i = 0,x ; i < n ; i++ ) 
		cin >> x , b.push_back(x) ;


	ull h = 1e10 , l = 0 ;

	while ( l <= h ) {
		 ull mid = (l+h)/2 ;

		if ( ok(mid , k) ) {
			l = mid+1 ;
			c = mid ;
		}
		else 
			h = mid-1 ;
	}



	cout << c ;
	


		 
 
 return 0 ; 
}