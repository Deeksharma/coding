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

// TLE
// vector<vector<int> > dp(2023);
// vector<vector<int> > vis(2023);
// map<int,pair<int,int> > m;
// void prep(){
// 	int k=1;
// 	for(int i=0;i<2023;i++){
// 		for(int j=0;j<=i;j++){
// 			pair<int,int> p;
// 			p.ff = i;
// 			p.ss = j;
// 			m[k] = p;
// 			dp[i].pb(k++);
// 			vis[i].pb(0);
// 		}
// 	}
// }
// void reset(){
// 	for(int i=0;i<2023;i++){
// 		for(int j=0;j<=i;j++){
// 			vis[i][j]=0;
// 		}
// 	}
// }

// int dfs(int x, int y){
// 	if(x<0||y<0) return 0LL;
// 	if(y>=dp[x].size()) return 0LL;
// 	if(vis[x][y]==1) return 0LL;
// 	vis[x][y]=1;

// 	int ans= dp[x][y]*dp[x][y] + dfs(x-1,y) + dfs(x-1, y-1);
// 	return ans;
// }

// void solve1() {
// 	reset();
// 	int n;
// 	cin>>n;
// 	pair<int,int> p = m[n];
// 	int x = p.ff;
// 	int y =p.ss;
// 	cout<<dfs(x,y)<<endl;
// }

int arr[2023][2023];
int dp[2023][2023];
map<int,pair<int,int> > m;

void prep(){
	int k=1;
	for(int i=0;i<2023;i++){
		for(int j=0;j<=i;j++){
			m[k]= make_pair(i-j,j);
			arr[i-j][j]=k++;
		}
	}

	dp[0][0] = 1;
	for(int i=1;i<2023;i++){
		dp[0][i]= arr[0][i]*arr[0][i] + dp[0][i-1];
	}
	for(int i=1;i<2023;i++){
		dp[i][0]= arr[i][0]*arr[i][0] + dp[i-1][0];
	}
	for(int i=1;i<2023;i++){
		for(int j=1;j<2023;j++){
			dp[i][j] = arr[i][j]*arr[i][j] - dp[i-1][j-1] + dp[i-1][j] + dp[i][j-1];
		}
	}
}

void solve() {
	int n;
	cin>>n;
	pair<int,int> p = m[n];
	int x = p.ff;
	int y =p.ss;
	cout<<dp[x][y]<<endl;
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
	prep();
	double time1 = (double)clock() / CLOCKS_PER_SEC;
	while (t--) solve();


	double time2 = (double)clock() / CLOCKS_PER_SEC;
	cerr << "time taken : " << time2 - time1 << " secs" << endl;
}