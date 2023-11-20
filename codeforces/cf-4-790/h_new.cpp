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

// line from a to b -> a ke aage se kitna kine h jo b ya b ke piche jaa rha h
void solve() {
	int n;
	cin>>n;
	vector<int> v(n);
	loop(i,0,n) cin>>v[i];

	int ans=0;
	for(int i=0;i<n;i++){
		for(int j= i+1;j<n;j++){
			if(v[j]<=v[i]) ans++; // iske aage aisa kitna number h jo iske baarabar ya isse chota h // this is nothing but inversion count :-)))// damn
		}
	}
	cout<<ans<<endl;
}

// 1 3 2 5

vector<int> v;
int ans;

void merge(int l1, int r1, int l2, int r2){
	int l11=l1;
	int r11=r1;
	int l22=l2;
	int r22=r2;
	vector<int> temp;
	while(l1<=r1&&l2<=r2){
		if(v[l1]<v[l2]){
			temp.pb(v[l1]);
			l1++;
		}else{
			temp.pb(v[l2]);
			l2++;
			ans+=(r1-l1+1); // for all these nubers v[l2] is smaller - so inversion count for all these
		}
	}

	while(l1<=r1){
		temp.pb(v[l1]);
		l1++;
	}

	while(l2<=r2){
		temp.pb(v[l2]);
		l2++;
	}

	int temp_idx = 0;

	for(int i=l11;i<=r11;i++){
		v[i]=temp[temp_idx];
		temp_idx++;
	}

	for(int i=l22;i<=r22;i++){
		v[i]=temp[temp_idx];
		temp_idx++;
	}

	// loopbug(temp,0,temp.sz);
	// loopbug(v,0,v.sz);

}

void merge_sort(int l, int r){

	if(l>=r) return;
	// varbug(l);
	// varbug(r);
	int mid = (l+r)/2;
	merge_sort(l,mid);
	merge_sort(mid+1,r);

	// cout<<"before calling merge"<<endl;
	// varbug(l);
	// varbug(mid);
	// varbug(r);
	merge(l,mid,mid+1,r);
}

void solve_2(){
	int n;
	cin>>n;
	// vector<int> v(n);
	v.clear();
	v.resize(n);
	ans=0;
	loop(i,0,n) cin>>v[i];

	merge_sort(0,n-1);
	// loopbug(v,0,n);
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
	while (t--) solve_2();


	double time2 = (double)clock() / CLOCKS_PER_SEC;
	cerr << "time taken : " << time2 - time1 << " secs" << endl;
}