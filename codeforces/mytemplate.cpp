#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ss second
#define ff first
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define mii map<int,int>
#define rep(i,l,r) for(i=l;i<r;i++)
#define mod 1000000007
#define all(v) v.begin(),v.end()
#define io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define cloop(i,x,y) for(ll i=(x);i<(y);++i)
#define bug(a) cout << #a << " = " << a << endl;
#define fbug(a, x, y) { cout << #a << ": "; cloop(i, x, y) cout << a[i] << ' '; cout << endl; }
#define sz size()
#define pi            3.14159265359
#define rev(i, n, x) for(long long i = n; i >= x; i--)
const ll N = 200005;

int dir4[4][2] = {{1, 0}, { -1, 0}, {0, -1}, {0, 1}};
int dir8[8][2] = {{1, 0}, { -1, 0}, {0, -1}, {0, 1}, {1, 1}, { -1, 1}, {1, -1}, { -1, -1}};

ll power(ll a, ll b) {
	if (b == 0) return 1;
	if (b % 2) return (a * (power((a * a) % mod, b / 2) % mod)) % mod;
	else return power((a * a) % mod, b / 2) % mod;
}

void solve() {

}

int main() {
	io;

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif

	int t = 1;
	cin >> t;
	double time1 = (double)clock() / CLOCKS_PER_SEC;
	while (t--) {
		cout << t << endl;
	}

	double time2 = (double)clock() / CLOCKS_PER_SEC;
	cerr << "time taken : " << time2 - time1 << " secs" << endl;
}