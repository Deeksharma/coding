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

void solve2() {
	int n;
	cin>>n;
	string s;
	cin>>s;

	int i=0;int j=n-1;

	vector<int> ans;

	int sum = 0LL;
	for(int i=0;i<n;i++){
		if(s[i]=='L') sum+=i;
		else sum+=n-i-1;
	}

	for(int i=0;i<n/2;i++){
		if(s[i]=='L'){
			ans.pb(-i+n-i-1);
		}
	}
	for(int i=n/2;i<n;i++){
		if(s[i]=='R'){
			ans.pb(i-(n-i-1));
		}
	}

	sort(all(ans));

	if(ans.size()==0){
		for(int i=0;i<n;i++){
			cout<<sum<<" ";
		}
	}else{
		vector<int> g;
		for(int i=0;i<ans.sz;i++){
			sum+=ans[i];
			g.push_back(sum);
		}
		int x = g[g.size()-1];
		while(g.size()!=n){
			g.push_back(x);
		}
		for(int i=0;i<n;i++){
			cout<<g[i]<<" ";
		}
	}
	cout<<endl;

}

void solve() {
	int n;
	cin>>n;
	string s;
	cin>>s;

	int i=0;int j=n-1;

	vector<int> ans;

	int sum = 0LL;
	for(int i=0;i<n;i++){
		if(s[i]=='L') sum+=i;
		else sum+=n-i-1;
	}
		// varbug(sum);

	if(n%2){
		s[n/2] = 'L';
	}
	while(i<n/2&&j>=n/2){
		int i_contibution = 0;
		int j_contribution = 0;
		while(i<n/2&&s[i]=='R'){
			i++;
		}
		while(j>=n/2&&s[j]=='L'){
			j--;
		}

		if(j<n/2 || i>=n/2) break;

		i_contibution = n-i-1-i;
		j_contribution = j-(n-j-1);

		if(i_contibution>j_contribution){
			i++;
			sum+=i_contibution;
			ans.pb(sum);
		}else{
			j--;
			sum+=j_contribution;
			ans.pb(sum);
		}		
	}
	while(i<n/2){
		if(s[i]=='L'){
			sum+=n-i-1-i;
			ans.pb(sum);
		}
		i++;
	}
	while(j>=n/2){
		if(s[j]=='R'){
			sum+=j-(n-j-1);
			ans.pb(sum);
		}
		j--;
	}

	if(ans.size()==0){
		for(int i=0;i<n;i++){
			cout<<sum<<" ";
		}
	}else{
		int x = ans[ans.size()-1];
		while(ans.size()!=n){
			ans.pb(x);
		}
		for(int i=0;i<n;i++){
			cout<<ans[i]<<" ";
		}
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