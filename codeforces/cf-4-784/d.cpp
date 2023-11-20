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
	string s;
	cin>>s;
	if(n==1){
		if(s=="B"||s=="R"){
			cout<<"NO"<<endl;
			return;
		}else{
			cout<<"YES"<<endl;
			return;
		}
	}

	if(s[n-2]=='W'&& (s[n-1]=='R' || s[n-1]=='B')){
		cout<<"NO"<<endl;
		return;
	}

	if(s[1]=='W'&& (s[0]=='R' || s[0]=='B')){
		cout<<"NO"<<endl;
		return;
	}

	// for(int i=0;i<n-1;i++){
	// 	if(s[i]=='R'|| s[i]=='B'){
	// 		if(s[i-1] == 'W' && s[i+1]=='W'){
	// 			cout<<"NO"<<endl;
	// 			return;
	// 		}
	// 	}
	// }

	// if bwtween 2 ws there is only one typr of ele then it'lll be a NO

	s = "W"+s+"W";
	// varbug(s);

	vector<int> w_index;
	for(int i=0;i<n+2;i++){
		if(s[i]=='W'){
			w_index.pb(i);
		}
	}

	// loopbug(w_index, 0, w_index.sz);
	if(w_index.sz >=2){
		for(int i=0;i<w_index.size()-1;i++){
			if(w_index[i]+1==w_index[i+1]){
				continue;
			}
			char par = s[w_index[i]+1];
			bool b = true;
			for(int j = w_index[i]+1;j<w_index[i+1];j++){
				if(s[j]!=par){
					b=false;
					break;
				}
			}
			if(b){
				cout<<"NO"<<endl;
				return;
			}
		}
	}


	cout<<"YES"<<endl;
	return;

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