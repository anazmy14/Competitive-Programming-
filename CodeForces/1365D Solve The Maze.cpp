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



int n , m ;
int dx[] = { 0, -1, 1, 0  } ;
int dy[] = { -1 , 0 , 0 , 1 };

bool valid ( int x, int y ) {
	return x >=0 && y >= 0 && x < n && y <m ;  
}

void dfs (  bool &b , int x , int y ,vector<vector<char>>&v , vector<vector<bool>> &vis ) {

	if (!valid(x,y) || v[x][y] == '#' || vis[x][y] ) 
		return ;
	if ( v[x][y] == 'B') 
		  b = 0 ;
	vis[x][y] = 1 ;
	v[x][y] = '1' ;
	for ( int i = 0; i < 4  ;i++ ) {
     		dfs ( b , x + dx[i] , y + dy[i] , v , vis) ;		
	}
	return  ;
}

 void block (int x , int y, vector<vector<char>> &v ) {
	for ( int i = 0 ; i < 4  ; i++ ) {
		if ( !valid(x+dx[i] , y+dy[i]) ) continue ; 
		int px =  x+dx[i] , py = y+dy[i] ;
		 			
		if ( v[px][py] == '.' )
			v[px][py] = '#' ;	
			
	}
}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t; cin >> t ;
	while (t--) {
		bool b = 1 ;
		cin >> n >> m  ; 
		vector<vector <char>>v(n) ;
		vector<vector<bool>> vis(n); 

		for ( int i = 0 ; i <n ; i++ ){
			for( int j =0; j < m; j++ ){
				char x ; cin >> x ;
				v[i].push_back(x) ;
				vis[i].push_back(0)  ;
			}
		}

		for( int i=0; i < n; i++) {
			for (int j =0 ; j <m ; j++) {
				if ( v[i][j] == 'B' ) 
					block(i ,j ,v) ;
			}
		}

		 dfs ( b , n-1 , m-1 , v , vis) ;
		//cout << v[0][1] << '*';

		for ( int i =0 ; i <n ;i++ ) {
			for( int j =0 ; j <m ; j++ ) {
				if( v[i][j] == 'G')
					b = 0 ;
			}
		}

	   b? cout << "Yes" : cout << "No"; 
	   cout << endl ;  
	   
	}


 return 0 ;
}
