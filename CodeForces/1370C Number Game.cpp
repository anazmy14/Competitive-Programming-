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

void d ( ull &x ) {
	int p = 0 ;
	for ( int i = 3 ; i <= sqrt(x) ; i+=2 ) {
		if ( x % i ==  0 ) {
			p = i ;
		}
	}

	if ( p) {
		x = x/ p ;
		return ;
	}

	x =  x-1 ;
}

 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	

	int t; cin >> t ;
	while( t--){
		ull  n , c = 1 , ev = 0,  od = 0; cin >> n ; 
		bool  b = 0 ;
		string s[2] = { "FastestFinger" , "Ashishgup"} ;
		
		if( n == 1 ) {
			cout << s[0] << endl  ; continue ;
		}
		if ( n == 2 )  {
			cout << s[1] << endl  ; continue ;
		}
		if ( n%2 ){ 
			cout << s[1] << endl ; continue; 
		}
		ev = n ;

		for ( int i = 2 ; i*i <= n ; i++ ) {
			if ( n % i != 0 )
				continue ;
			ull x = n/i , y = i  ;  
			if ( x%2 == 0 && y%2 == 0 ) continue;   

			if ( y%2) swap(x , y ) ;  

			if ( x > od ) {
				od = x ;
				ev = y ;
			}
		
		}

		for ( int i = 3 ; i*i <= od ; i+=2 ) {
			if ( od % i == 0 ) {
				b = 1 ;
				break ;
			}
		}

		if (!od )  
			cout << s[0]   ;
		else if ( od && ev > 2 ) 
			cout << s[1]  ;
		else if (b)
			cout << s[1] ;
		else  
			cout << s[0] ; 
		
		cout << endl ;
 
 
	}
 
	
		 
 
 return 0 ; 
}