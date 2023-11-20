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
	vector<int> v;
	int j = 1;
	for(int i=0;i<57;i++){
		v.pb(j);
		j*=2;
	}
	int mini= INT_MAX;
	for(int i=0;i<v.sz;i++){
		// kya krna chaiye?? -> number aur v[i] ka first element match kro
		// -> mil gya toh okay -> nhi mila to operation ++, next pr jao, 
		// agar number khatam ho jaye -> toh jitna bhi number bacha h usko add kr do (operation)

		vector<int> a, b;
		int aa = v[i];
		int bb = n;
		while(aa!=0){
			a.pb(aa%10);
			aa=aa/10;
		}
		while(bb!=0){
			b.pb(bb%10);
			bb=bb/10;
		}
		reverse(all(a));
		reverse(all(b));
		int cnt = 0;
		int j=0,l=0;

		while(l<a.sz&&j<b.sz){
			if(a[l]==b[j]){
				j++;
				l++;
			}else{
				cnt++;
				j++;
			}
		}
		if(j<b.sz){
			cnt+=(b.sz-j);
		}
		if(l<a.sz){
			cnt+=(a.sz-l);
		}
		mini = min(mini, cnt);
	}
	cout<<mini<<endl;

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