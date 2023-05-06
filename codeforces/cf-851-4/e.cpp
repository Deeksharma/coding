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

void solve() {
	int n,m;
	cin>>n>>m;
	int arr[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
		}
	}
	int vis[n][m];
	memset(vis, 0, n*m*sizeof(int));

	int ans_max = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int ans =0;
			if(vis[i][j]==0&&arr[i][j]>0){
				queue<pair<int,int> > q;
				pair<int,int> temp1;
				temp1.ff = i;
				temp1.ss = j;
				q.push(temp1);
				vis[i][j]=1;
				ans +=arr[i][j];
				while(!q.empty()){
					pair<int,int> p = q.front();
					int x= p.ff;
					int y = p.ss;
					q.pop();
					for(int k=0;k<4;k++){
						int xx = x+dir4[k][0];
						int yy = y+dir4[k][1];
						if(xx>=0&&xx<n&&yy>=0&&yy<m&&vis[xx][yy]!=1&&arr[xx][yy]>0){
							vis[xx][yy]=1;
							ans +=arr[xx][yy];
							pair<int,int> temp2;
							temp2.ff = xx;
							temp2.ss = yy;
							q.push(temp2);
						}
					}
				}
				ans_max= max(ans,ans_max);
			}
		}
	}
	cout<<ans_max<<endl;
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