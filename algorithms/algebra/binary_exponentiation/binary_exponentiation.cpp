#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define ss second
#define ff first
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define mii map<int,int>
#define si set <int>
#define vi vector <int>
#define vpi vector <pii>
#define vpp vector <pair<int, pii>>
#define mpi map <pii, int>
#define spi set <pii>
#define double long double
#define que_max priority_queue <int>
#define que_min priority_queue <int, vi, greater<int>>

#define loop(i, l, r) for(int i = l;i < r ; i++)
#define rev(i, n, x) for(int i = n; i >= x; i--)

#define mod 1000000007
#define pi 3.14159265359

#define sz size()
#define all(v) v.begin(),v.end()
#define endl "\n"

#define io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

// printing values
#define print(a) for(auto x : a) cout << x << " "; cout << endl
#define printpair(a) for(auto x : a) cout << x.ff << " " << x.ss << endl
#define printloop(a,x,y) for(int i = x; i < y; i++) cout<< a[i]<< " "; cout << endl

// debugging
#define cloop(i,x,y) for(int i=(x);i<(y);++i)
#define varbug(a) cout << #a << " = " << a << endl;
#define loopbug(a, x, y) { cout << #a << ": "; cloop(i, x, y) cout << a[i] << ' '; cout << endl; }

const int N = 200005;

int dir4[4][2] = {{1, 0}, { -1, 0}, {0, -1}, {0, 1}};
int dir8[8][2] = {{1, 0}, { -1, 0}, {0, -1}, {0, 1}, {1, 1}, { -1, 1}, {1, -1}, { -1, -1}};

int power(int a, int b) {
	if (b == 0) return 1;
	if (b % 2) return (a * (power((a * a) % mod, b / 2) % mod)) % mod;
	else return power((a * a) % mod, b / 2) % mod;
}

/*
TC - O(log(n))

can be applied on any arithmentic operation with associative property - x.(y.z) = (x.y).z - add, multiplication, modulo of add and multiplication

the number n has exactly ceil(log2(n)) + 1 digits in base 2 complexity is log2(n)

*/

//-------------------------------------------------------------------------------------------------------------

// compute a^b
int bin_pow(int a, int b){
	if(b==0) return 1;

	int res = bin_pow(a, b/2);
	if(b%2){
		return res * res * a;
	}
	else{
		return res*res;
	}
}

int bin_pow2(int a, int b){
	if(b==0) return 1;
	if(b%2) return a*bin_pow2(a*a, b/2);
	else return bin_pow2(a*a, b/2);
}


// without recursion
int bin_pow3(int a, int b){
	int res =1;
	while(b>0){
		if(b&1){
			res = res*a;
		}
		a = a*a;
		b >>= 1;
	}
	return res;
}

//-------------------------------------------------------------------------------------------------------------


void solve() {
	cout<< bin_pow(5,5)<<endl;
	cout<< bin_pow2(5,5)<<endl;
	cout<< bin_pow3(5,5)<<endl;

}

int32_t main() {
	io;

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif


	int t = 1;
	//cin >> t;
	double time1 = (double)clock() / CLOCKS_PER_SEC;
	while (t--) solve();


	double time2 = (double)clock() / CLOCKS_PER_SEC;
	cerr << "time taken : " << time2 - time1 << " secs" << endl;
}