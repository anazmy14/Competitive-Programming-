#include<iostream> 
#include <vector> 
#include <string>
#include <map>
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

void find (vector<int> &v , string s) {
    string x = "";
	for ( int i =0 ; i < s.length(); i++){
        if ( (s[i] < '0' || s[i] > '9') && s[i] != '-'  ){
			v.push_back(stoi(x)) ;
            x = "";
            continue;
        }
   }

	v.push_back( stoi(x) ); 

}



int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n , z = 0; cin >> n ;
	vector<int>v(n+1) ; 
    map<pair <bool ,int> , int> m ; 

	for ( int i =0 , x ; i < n; i++ ){
		cin >> x ;
		v[x] = i ;
	}

	for ( int i =0,x ; i < n ; i++) {
		cin >> x ;
		int p = v[x] ;
		if ( p > i ) { 
			z = max ( ++m[ MKP(0 , p-i ) ] , z ) ; 
			z = max ( ++m[ MKP(1 , i + (n-p) ) ], z )  ;
		}

		else {
			z = max (++m[ MKP ( 0 , (n-i) +p  )] , z ) ;
			z = max (++m[ MKP ( 1 , i-p ) ] , z );   
		}

	}
	cout << z ;



	


 return 0 ;
}
