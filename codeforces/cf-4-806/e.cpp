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


void rotate90Clockwise(vector<string> &a,int n)
{
 
    // Traverse each cycle
    for (int i = 0; i < n / 2; i++) {
        for (int j = i; j < n - i - 1; j++) {
 
            // Swap elements of each cycle
            // in clockwise direction
            int temp = a[i][j];
            a[i][j] = a[n - 1 - j][i];
            a[n - 1 - j][i] = a[n - 1 - i][n - 1 - j];
            a[n - 1 - i][n - 1 - j] = a[j][n - 1 - i];
            a[j][n - 1 - i] = temp;
        }
    }
}

void solve() {
	int n;
	cin>>n;
	vector<string> s(n);
	// vector<vector<int> > v;
	map<string, vector<int> > v;
	for(int i=0;i<n;i++){
		cin>>s[i];
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			v[to_string(i)+"#"+to_string(j)].push_back(s[i][j]-'0');
		}
	}

	rotate90Clockwise(s, n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			v[to_string(i)+"#"+to_string(j)].push_back(s[i][j]-'0');
		}
	}
	rotate90Clockwise(s, n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			v[to_string(i)+"#"+to_string(j)].push_back(s[i][j]-'0');
		}
	}
	rotate90Clockwise(s, n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			v[to_string(i)+"#"+to_string(j)].push_back(s[i][j]-'0');
		}
	}

	int ans=0;

	for(auto x: v){

		int num_0=0, num_1=0;
		for(int j=0;j<x.ss.size();j++){
			if(x.ss[j]==0) num_0++;
			else num_1++;
		}
		if(num_1>=num_0){
			ans+=num_0;
		}else{
			ans+=num_1;
		}
	}

	cout<<ans/4<<endl;


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