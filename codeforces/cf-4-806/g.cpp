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

// int dp_store[100005][32];
// int n, k;
// vector<int> arr(100005);
// int dp(int idx, int bad_keys){
// 	if(idx==n) return 0;
// 	if(bad_keys>=31) return 0;

// 	if(dp_store[idx][bad_keys]!=LLONG_MIN) return dp_store[idx][bad_keys];

// 	int x = dp(idx+1, bad_keys+1) + arr[idx]/pow(2, bad_keys+1); // used bad key
// 	int y = dp(idx+1, bad_keys)+ arr[idx]/power(2, bad_keys) -k; // used good key

// 	return dp_store[idx][bad_keys] = max(x, y);
// }

// dp[i][j] = till ith element we will use j bad keys, euther use it at ith idx or use it before
// dp[i][j] = dp[i-1][j]+arr[i]/power(2,j)-k, dp[i-1][j-1]+arr[i]/power(2,j)
void solve(){
	int n,k;
	cin>>n>>k;
	int dp[n+1][40];
	memset(dp, 0LL, sizeof(dp));
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}


	for(int i=0;i<n;i++){
		dp[i+1][0] = dp[i][0] + arr[i] -k;
		for(int j=0;j<=min(32LL, i+1);j++){
				dp[i+1][j+1] = max(dp[i][j+1]+(arr[i]>>(j+1))-k, dp[i][j]+(arr[i]>>(j+1)));
		}
	}

	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<33;j++){
	// 			cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	// i dont know why 
	// Because of their definition "dp[i][j] means at ith element we use exactly j bad keys".
	 // Note that we can definitely use more than 33 bad keys,
	  // but it won't matter because after 33 bad keys all elements to the right will be 0.
	 // So, considering dp[i][j] for i < n is equivalent of handling all cases where a[k] becomes 0 for all k > i (note ai >= 0).
	  //  If the definition was "at most j bad keys", then we could just answer max over j of dp[n][j], but the transition would be different.
	
	// dp[i][j] mein agar j = 32 h toh aage wala saara 0 ho jayega, isiliye woh be ek possible answer h 
	// maan lo ki i=34 h aur ispr max 29 bad keys use kr chuke h, ab iske aage wala sab 0 ho gya agar kyki sab 2^29 se chota h toh yeh ek possible answer h
	int ans = LLONG_MIN;
	for(int j=1;j<n+1;j++){
		for(int i=0;i<33;i++){
			ans = max(ans, dp[j][i]);
		}
	}

	cout<<ans<<endl;
}


// void solve() {
// 	cin>>n>>k;
	
// 	for(int i=0;i<100005;i++){
// 		for(int j=0;j<32;j++){
// 			dp_store[i][j] = LLONG_MIN;
// 		}
// 	}
// 	for(int i=0;i<n;i++){
// 		cin>>arr[i];
// 	}

// 	cout<<dp(0,0)<<endl;


// }

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