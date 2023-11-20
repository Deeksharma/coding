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
	vector<int> arr(n);
	for(int i=0;i<n;i++) cin>>arr[i];

	vector<int> left_one(n,0);
	vector<int> right_zero(n,0);

	for(int i=1;i<n;i++){
		if(arr[i-1]==1){
			left_one[i] = left_one[i-1] +1;
		}else{
			left_one[i] = left_one[i-1];
		}
	}

	for(int i=n-2;i>=0;i--){
		if(arr[i+1]==0){
			right_zero[i] = right_zero[i+1] +1;
		}else{
			right_zero[i] = right_zero[i+1];
		}
	}

	int maxi = INT_MIN;
	int max_idx = -1;
	vector<int> v;
	for(int i=0;i<n;i++){
		if(arr[i]==0){
			if(maxi<(-left_one[i]+right_zero[i])){
				maxi = (-left_one[i]+right_zero[i]);
				max_idx = i;
			}
			v.pb((-left_one[i]+right_zero[i]));

			// varbug((left_zero[i]-right_one[i]));
		}else{
			if(maxi<(left_one[i]-right_zero[i])){
				maxi = (left_one[i]-right_zero[i]);
				max_idx = i;
			}
			// varbug(-left_zero[i]+right_one[i]);
			v.pb((left_one[i]-right_zero[i]));

		}
	}

	// loopbug(v, 0, n);
	int ans =0;

	for(int i=0;i<n;i++){
		if(arr[i]==0){
			ans += left_one[i];
		}
	}

	// cout<<ans<<endl;
	// varbug(maxi);
	// varbug(max_idx);

	if(maxi>0){
		ans+=maxi;
	}
	cout<<ans<<endl;
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