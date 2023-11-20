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

vector<vector<pair<int,int> > > g;

void solve() {
	int n,a,b;
	cin>>n>>a>>b;

	g.clear();
	g.resize(n+1);


	for(int i=0;i<n-1;i++){
		int u, v, w;
		cin>>u>>v>>w;
		g[v].pb(mp(u,w));
		g[u].pb(mp(v,w));
	}

	queue<pair<int,int> > q;
	map<int,int> m;
	vector<int> vis(n+1, 0);
	q.push(mp(b,0));
	vis[b] = 1;
	while(!q.empty()){

		pii p = q.front();
		q.pop();
		// varbug(p.ff);

		for(auto x: g[p.ff]){
			if(!vis[x.ff]){
				int xor_val = x.ss^p.ss;
				// varbug(xor_val);
				if(x.ff == a && xor_val==0){
					cout<<"YES"<<endl;
					return;
				}
				m[xor_val] = 1;
				vis[x.ff] = 1;
				q.push(mp(x.ff, xor_val));
			}
		}
	}

	vis.clear();
	vis.resize(n+1, 0);

	q.push(mp(a, 0));
	vis[a] =1;
	vis[b] = 1;
	while(!q.empty()){
		pii p = q.front();
		q.pop();

		for(auto x: g[p.ff]){
			if(!vis[x.ff]){
				int xor_val = x.ss^p.ss;

				if(m[xor_val]){
					cout<<"YES"<<endl;
					return;
				}

				vis[x.ff] = 1;
				q.push(mp(x.ff, xor_val));
			}
		}
	}

	if(m[0]){
		cout<<"YES"<<endl;
		return;
	}

	cout<<"NO"<<endl;
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