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

void find (vector<int> &v , string s) {
    string x = "";

    for ( int i =0 ; i < s.length(); i++){
        if (s[i] < '0' || s[i] > '9'  ){
            v.push_back(stoi(x)) ;
            x = "";
            continue;
        }
        x += s[i] ;
    }

}



int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t ; cin >> t ;
    while(t--){
        int n , m ; cin >> n >> m ;
        set<int> c , r ;
        for ( int i=0 ; i <n ; i++){
            for ( int j=0 , x; j<m; j++  ){
                cin >> x ;
                if (x) {
                    c.insert(j) ;
                    r.insert(i) ;
                }
            }
        }

        int x = m - c.size() <  n - r.size() ?  m-c.size() : n - r.size() ;

        if(x%2)
            cout << "Ashish" ;
        else
            cout << "Vivek" ;
        cout << endl ;

    }


 return 0 ;
}
