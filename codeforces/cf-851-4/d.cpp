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

// dunno what went wrong :-(((
void solve1() {
	int n,m;
	cin>>n>>m;
	if(m>n){
		cout<<"NO"<<endl;
		return;
	}
	if(m==n){
		cout<<"YES"<<endl;
		return;
	}
	map<int,int> n1,m1;
	int temp_n=n;
	int temp_m=m;
	// cout<<n<<" "<<m<<":"<<endl;
	for(int i=2;i*i<=temp_n;i++){
		if(n%i==0){
			while(n%i==0){
				n1[i]++;
				n=n/i;
			}
		}
	}
	if(n!=1){
		n1[n]++;
		n=n/n;
	}

	for(int i=2;i*i<=temp_m;i++){
		if(m%i==0){
			while(m%i==0){
				m1[i]++;
				m=m/i;
			}
		}
	}
	if(m!=1){
		m1[m]++;
		m=m/m;
	}
	
	// for(auto x: n1){
	// 	cout<<x.ff<<" "<<x.ss<<endl;
	// }
	// cout<<endl;
	// for(auto x: m1){
	// 	cout<<x.ff<<" "<<x.ss<<endl;
	// }
	// cout<<"--------------"<<endl;

	for(auto x: m1){
		int f= x.ff;
		int s=x.ss;
		if(n1.find(f)!=n1.end()){
			n1[f]=max(n1[f]-m1[f],0LL);
			m1[f]=max(m1[f]-n1[f],0LL);
		}
	}


	for(auto x: m1){
		if(x.ff!=2&&x.ss>0){
			cout<<"NO"<<endl;
			return;
		}
	}
	for(auto x: n1){
		if(x.ff!=3&&x.ss>0){
			cout<<"NO"<<endl;
			return;
		}
	}

	cout<<"YES"<<endl;
}

bool dfs(int n,int m){
	if(n==m) return true;
	if(m>n || n%3) return false;
	return dfs(n/3,m)||dfs(2*n/3,m); 
}

void solve() {
	int n,m;
	cin>>n>>m;
	if(dfs(n,m)) cout<<"YES";
	else cout<<"NO";
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