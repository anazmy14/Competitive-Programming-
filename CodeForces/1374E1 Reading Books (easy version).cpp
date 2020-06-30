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
 
 
 
void printPrimeFactors(int n) {
	int c =0 ;
   while (n%2 == 0){
      cout<<"2\t";
      n = n/2;
	  c++ ;
   }
   for (int i = 3; i <= sqrt(n); i = i+2){
      while (n%i == 0){
         cout<<i<<"\t";
         n = n/i;
      }
   }
   if (n > 2)
   cout<<n<<"\t";
}
 
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int n, k , c1 = 0 , c2=0; cin >> n >> k ;
	ll s = 0;
	deque<int> x , y , z ;

	for ( int i = 0,t,a,b; i < n; i++) {
		cin >> t >> a >> b ;
		if (a&&b) 
			z.push_back(t)  ;
		else if(b) 
			y.push_back(t), c2++ , s+=t  ;
		else if(a)
			x.push_back(t) , c1++ , s+=t;
		
	
	}

	sort( x.begin() , x.end() ) ;
	sort( y.begin() , y.end() ); 
	sort( z.begin() , z.end() )  ; 

	while(c1 > k ) c1-- , s-= x.back() , x.pop_back()   ;

	while (c2 > k) c2--, s-= y.back() , y.pop_back();
	

	while(z.size()) {
		if (c1  >= k && c2 >= k ) {
			int h = x.size() ? x.back() : 0 ; 
			int l = y.size() ? y.back() : 0 ;

			if ( z.front() < h+l ) {
				s -= h , s -= l ;
				s += z.front() ;
				if ( h) 
					x.pop_back(); 
				if (l) 
				 y.pop_back() ;
				z.pop_front() ;				
			}
			else 
				break ;
		}

		else if ( c1 < k && c2 < k ) {
			c1++ , c2++ ;
			s += z.front() ; 
			z.pop_front() ;
		}

		else if ( c1 < k ) {
			s += z.front() ;
			z.pop_front() ;
			if(y.size() ){
    			s -= y.back() ;
				y.pop_back() ;
			}
			c1++ ;
		}

		else if ( c2 < k ) {
			s += z.front() ;
			z.pop_front();
			if ( x.size() ){
				s -= x.back() ;
				x.pop_back();
			}
			c2++;
		}

	}
	

	if ( c1 >= k && c2 >= k ) 
		cout << s  ;
	else 
		cout << -1; 





 
 
 return 0 ; 
}