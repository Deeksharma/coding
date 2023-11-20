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
	vector<string> v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	int ans=0;
	for(int i=0;i<n/2;i++){
		int x = i;
		int y = n-i-1;

		string a="", b="", c="", d="";
		for(int j=x;j<=y;j++){
			a+=v[x][j];
			c+=v[j][y];
		}

		for(int j=y;j>=x;j--){
			b+=v[j][x];
			d+=v[y][j];
		}

		// varbug(a);
		// varbug(b);
		// varbug(c);
		// varbug(d);
		
		
		string s="";

		for(int j=0;j<a.size();j++){
			char largest = 'a';
			if(a[j]>largest){
				largest=a[j];
			}
			if(b[j]>largest){
				largest=b[j];
			}
			if(c[j]>largest){
				largest=c[j];
			}
			if(d[j]>largest){
				largest=d[j];
			}
			s+=largest;
		}
		// varbug(s);

		for(int j=x, k=0;j<=y;j++, k++){
			ans+=abs(v[x][j]-s[k]);
			v[x][j]=s[k];
		}


		for(int j=x,k=0;j<=y;j++,k++){
			ans+=abs(v[j][y]-s[k]);
			v[j][y]=s[k];
		}


		for(int j=y,k=0;j>=x;j--,k++){
			ans+=abs(v[j][x]-s[k]);
			v[j][x]=s[k];
		}

		for(int j=y,k=0;j>=x;j--,k++){
			ans+=abs(v[y][j]-s[k]);
			v[y][j]=s[k];
		}

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