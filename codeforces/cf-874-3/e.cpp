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

vector<set<int> > g;
vector<int> vis;
int k;
void dfs(int n){
	vis[n] = k;
	for(auto x: g[n]){
		if(!vis[x]){
			dfs(x);
		}
	}
}

bool is_cycle(int n){
	vis[n] = 1;
	int temp = 0;
	for(auto x: g[n]){
		if(vis[x]==0){
			temp = is_cycle(x);
		}else if(vis[x]==1){
			return 1;
		}
		if(temp) return 1;
	}
	vis[n] = 2;
	return 0;
}

void solve() {
	vis.clear();
	g.clear();
	k=0;
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
		v[i]--;
	}
	g.resize(n);
	for(int i=0;i<n;i++){
		g[i].insert(v[i]);
		g[v[i]].insert(i);
	}

	// find all connected components
	vis.resize(n,0);
	for(int i=0;i<n;i++){
		if(!vis[i]){
			k++;
			dfs(i);
		}
	}
	// loopbug(vis, 0, n);

	
	// map<int,vector<int> > m;
	vector<vector<int> > component(k);

	for(int i=0;i<n;i++){
		component[vis[i]-1].pb(i);
	}

	// for(int i=0;i<k;i++){
	// 	for(int j=0;j<component[i].sz;j++){
	// 		cout<<component[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	// cout<<"adj list--"<<endl;

	// for(int i=0;i<n;i++){
	// 	for(auto x: g[i]){
	// 		cout<<x<<" ";
	// 	}
	// 	cout<<endl;
	// }


	int numberOfCycle=0;

	// then find which of then is a cycle
	vis.clear();
	vis.resize(n, 0);

	for(int i=0;i<k;i++){
		bool is_cycle= true;
		for(auto x: component[i]){
			if(g[x].size()!=2){
				is_cycle = false;
				break;
			}
		}
		if(is_cycle) numberOfCycle++;
		// cout<<endl;
		// if(is_cycle(component[i][0])) numberOfCycle++;
	}

	// varbug(numberOfCycle);
		
	int mini = ((k-numberOfCycle>0)?1:0) + numberOfCycle;
	int maxi = k;

	cout<<mini<<" "<<maxi<<endl;


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