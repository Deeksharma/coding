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

// wrong ans
void solve() {
	int n, c;
	cin>>n>>c;
	vector<int> a(n);
	loop(i,0,n){
		cin>>a[i];
	}

	priority_queue <pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > q0, q1;
	for(int i=0;i<n;i++){
		q0.push(mp(a[i]+i+1, i));
		q1.push(mp(a[i]+n-i, i));
	}
	// this is dp question 
	// dp[i][0] and dp[i][1] types- ??
	// dp[i+1] = min()

	vector<int> vis(n,0);
	int sum = 0;
	int ans = 0;
	pair<int, int> q00 = q0.top();
	q0.pop();
	sum+= q00.ff;
	if(sum<=c){
		ans++;
	}else{
		cout<<0<<endl;
		return;
	}
	vis[q00.ss] = 1;
	while(!q0.empty() && !q1.empty()){
		while(!q0.empty() && vis[q0.top().ss]){
			q0.pop();
		}
		while(!q1.empty() && vis[q1.top().ss]){
			q1.pop();
		}

		pair<int, int> q00 = q0.top();
		pair<int, int> q11 = q1.top();
		varbug(q00.ff);
		varbug(q00.ss);
		varbug(q11.ff);
		varbug(q11.ss);

		if(q00.ff<=q11.ff){
			sum+= q00.ff;
			if(sum<=c){
				ans++;
			}else{
				break;
			}
			vis[q00.ss] = 1;
			q0.pop();
		}else{
			sum+= q11.ff;
			if(sum<=c){
				ans++;
			}else{
				break;
			}
			vis[q11.ss] = 1;
			q1.pop();
		}
	}
	cout<<ans<<endl;
	cout<<"-----------"<<endl;
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