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
	int n;
	cin>>n;

	vector<int> v(n);
	int max_idx = -1;
	int maxi = INT_MIN;
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	if(n==1){
		cout<<v[0]<<endl;
		return;
	}
	for(int i=0;i<n;i++){
		if(maxi<v[i]){
			maxi = v[i];
			max_idx = i;
		}
	}

	if(max_idx==n-1){
		vector<int> ans;
		int i =n-1;
		while(v[i]>v[0]){
			ans.push_back(v[i]);
			i--;
		}
		for(int j=0;j<=i;j++){
			ans.pb(v[j]);
		}
		for(int j=0;j<n;j++){
			cout<<ans[j]<<" ";
		}
		cout<<endl;
		return;
	}

	if(max_idx==0){
		int max_idx2 = -1;
		int maxi2 = INT_MIN;
		for(int i=1;i<n;i++){
			if(maxi2<v[i]){
				maxi2 = v[i];
				max_idx2 = i;
			}
		}
		if(max_idx2 == n-1){
			// then go by above logic
			vector<int> ans;
			for(int i=max_idx2;i<n;i++){
				ans.pb(v[i]);
			}
			for(int i=0;i<max_idx2;i++){
				ans.pb(v[i]);
			}
			for(int j=0;j<n;j++){
				cout<<ans[j]<<" ";
			}
			cout<<endl;
			return;
		}else{
			// go by below logic
			int r= max_idx2-1;
			int l=r;

			while(l-1>=0 && v[0]<v[l-1]){
				l--;
			}
			vector<int> ans;
			for(int i=max_idx2;i<n;i++){
				ans.pb(v[i]);
			}
			for(int i=r;i>=l;i--){
				ans.pb(v[i]);
			}
			for(int i=0;i<l;i++){
				ans.pb(v[i]);
			}
			for(int i=0;i<n;i++){
				cout<<ans[i]<<" ";
			}
			cout<<endl;
			return;
		}
		
	}

	int r= max_idx-1;
	int l=r;

	while(l-1>=0 && v[0]<v[l-1]){
		l--;
	}
	vector<int> ans;
	for(int i=max_idx;i<n;i++){
		ans.pb(v[i]);
	}
	for(int i=r;i>=l;i--){
		ans.pb(v[i]);
	}
	for(int i=0;i<l;i++){
		ans.pb(v[i]);
	}
	for(int i=0;i<n;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;

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