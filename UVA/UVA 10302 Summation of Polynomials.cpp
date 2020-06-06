#include<bits/stdc++.h>
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

void find ( ull x ,  vector<ull> &v ,  unordered_map <ull , bool> &m ) {
    if (!x)
        return ;
    ull p = log2(x) , k ;
    k = pow(2,p) ;
    x -= k ;

    if ( m[k] )
        m[k] = 0 ;
    else {
          m[k] = 1 ;
          v.push_back(k) ;
    }


    find(x , v , m);
}



int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
	while (t--) {
        int a , d , x , y ;
        cin >> a >>d ;
        x = (a+d)/2 ;
        y = a - x ;

        if ( x >=0 && y >= 0 && a == x+y && d == x-y )
            cout << x << " " << y ;
        else
            cout << "impossible" ;

        cout << endl ;
	}



 return 0 ;
}
