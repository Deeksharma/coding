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
	string s;
	cin>>s;
	int arr[26], cnt[26];
	memset(arr, 0, sizeof(arr));
	memset(cnt, 0, sizeof(cnt));
	int n = s.size();
	for(int i=1;i<=n;i++){
		int z = s[i-1] - 'a';
		arr[z] = max(arr[z], i);
		cnt[z]++;
	}
	vector<pair<int, int> > v;
	for(int i=0;i<26;i++){
		if(arr[i]!=0){
			v.push_back(make_pair(arr[i],i));
		}
	}
	// my_str.erase(remove(my_str.begin(), my_str.end(), 'A'), my_str.end()); //remove A from string 
	// The std::remove algorithm in C++ doesn't actually remove elements from the container. Instead, it rearranges the elements, moving all the elements that match the specified value to the end of the range and returning an iterator pointing to the new end. The actual removal of elements is typically done using the erase member function.
	sort(all(v));
	reverse(all(v));
	string t = "";
	map<int, int> l;
	int len = 0;
	for(int i=0;i<v.size();i++){
		t += 'a' + v[i].ss;
		int k = v.size() - i;
		if(cnt[v[i].ss]%k!=0){
			cout<<-1<<endl;
			return;
		}
		l[v[i].ss] = cnt[v[i].ss]/k;
		len += cnt[v[i].ss]/k;
	}

	reverse(all(t));
	string g = s.substr(0, len);
	string f = g;

	string g_dash = "";
	for(int i=0;i<t.size();i++){
		g_dash += f;
		f.erase(remove(f.begin(), f.end(), t[i]), f.end());
	}
	if(g_dash != s){
		cout<<-1<<endl;
		return;
	}

	cout<<g<<" "<<t<<endl;


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