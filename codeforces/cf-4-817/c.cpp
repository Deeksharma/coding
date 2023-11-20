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
	set<string> a,b,c;
	for(int i=0;i<n;i++){
		string x;
		cin>>x;
		a.insert(x);
	}
	for(int i=0;i<n;i++){
		string x;
		cin>>x;
		b.insert(x);
	}
	for(int i=0;i<n;i++){
		string x;
		cin>>x;
		c.insert(x);
	}

	int ans_a=0, ans_b=0, ans_c=0;
	for(auto x: a){
		bool in_b = b.find(x)!=b.end();
		bool in_c = c.find(x)!=c.end();
		if(in_b&&in_c){
			ans_a+=0;
		}else if(in_b || in_c){
			ans_a+=1;
		}else{
			ans_a+=3;
		}
	}
	for(auto x: b){
		bool in_a = a.find(x)!=a.end();
		bool in_c = c.find(x)!=c.end();
		if(in_a&&in_c){
			ans_b+=0;
		}else if(in_a || in_c){
			ans_b+=1;
		}else{
			ans_b+=3;
		}

	}
	for(auto x: c){
		bool in_b = b.find(x)!=b.end();
		bool in_a = a.find(x)!=a.end();
		if(in_b&&in_a){
			ans_c+=0;
		}else if(in_a || in_b){
			ans_c+=1;
		}else{
			ans_c+=3;
		}

	}
	cout<<ans_a<<" "<<ans_b<<" "<<ans_c<<endl;
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