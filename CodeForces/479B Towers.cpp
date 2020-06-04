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
 
 
 
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	int n , k , c = 0, mn =1999999 ;  cin >> n >> k ;
	vector<pair<int ,int>> z;
	vector<int> v(n) ;  
 
	for( int i = 0 ;  i < n ;i++){
		cin >> v[i] ;
	}
 
	while (1 ) {
		int  x = max_element(v.begin() , v.end())  - v.begin();
		int  y = min_element(v.begin() , v.end() ) - v.begin(); 
	 	mn = v[x] - v[y] ; 
 
		if(v[x] - v[y] < 2 || c >= k ) 
			break ;
        v[x] -- ;
		v[y] ++ ; 
		c++; 
		z.push_back(MKP(x+1 , y+1)) ;
 
	}
 
 
 
 
	cout << mn << " " << c << endl ;
 
	for ( pair<int ,int > p : z )
		cout << p.first << " " << p.second << endl ;
 
 
 
 
 return 0 ;
}