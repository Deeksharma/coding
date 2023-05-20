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
vector<int> v;
int k;
int sum = 0;

int dp(int k, int i, int j){
	// cout<<k<<" "<<i<<" "<<j<<endl;
	if(k == 0) return sum;
	if(i>=j) return INT_MIN;
	int ans= max(dp(k-1, i+2, j)-v[i]-v[i+1], dp(k-1, i,j-1)-v[j]);
	return ans;
}

void solve() {
	v.clear();
	sum = 0;
	int n;
	cin>>n>>k;
	v.resize(n,0);
	for(int i=0;i<n;i++){
		cin>>v[i];
	} 
	sort(all(v));
	for(int i=1;i<n;i++){
		v[i] += v[i-1];
	}
	// for(int i=0;i<n;i++) sum+=v[i];
	// cout<<dp(k, 0, n-1)<<endl;
	// i moves 2 wale k-i moves 
	int ans = LLONG_MIN;
	for(int i=0;i<=k;i++){
		int l=i*2;
		int m= n- k+i;
		// varbug(v[m-1] - (l-1<0?0:v[l-1]));
		ans= max(ans, v[m-1] - (l-1<0?0:v[l-1]));
	}
	cout<<ans<<endl;
}




int32_t main() {
	io;

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif


	int t = 1;
	cin >> t;
	double time1 = (double)clock() / CLOCKS_PER_SEC;
	while (t--) solve();


	double time2 = (double)clock() / CLOCKS_PER_SEC;
	cerr << "time taken : " << time2 - time1 << " secs" << endl;
}