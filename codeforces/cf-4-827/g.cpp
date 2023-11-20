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

// struct node {
// 	node* children[2];
// 	int idx;
// 	bool vis;
// 	node(){
// 		// this.val = val;
// 		for(int i=0;i<2;i++){
// 			this->children[i]=NULL;
// 		}
// 		this->idx = -1;
// 		this->vis = false;
// 	}
// };

// void insert(int n, node* root, int idx){
// 	vector<int> v;
// 	for(int i=0;i<32;i++){
// 		v.pb(n%2);
// 		n=n/2;
// 	}
// 	reverse(all(v));

// 	for(int i=0;i<32;i++){
// 		root->children[v[i]] = new node();
// 		root = root->children[v[i]];
// 	}
// 	root->idx = idx;
// }


// int find(int n, node *root){
// 	vector<int> v;
// 	for(int i=0;i<32;i++){
// 		v.pb(n%2);
// 		n=n/2;
// 	}
// 	reverse(all(v));

// 	int j=0;
// 	while(j<32&&v[j]==0){
// 		j++;
// 	}

// 	for(int i=j;i<32;i++){
// 		v[i] = !v[i];
// 	}



	

// 	loopbug(v, 0, 32);
// 	for(int i=0;i<32;i++){
// 		if(root->children[v[i]]!=NULL){
// 			varbug(v[i]);
// 			varbug(i);
// 			root = root->children[v[i]];
// 			root->vis = true;
// 		}else if(root->children[!v[i]] !=NULL){
// 			root=root->children[!v[i]];
// 		}
// 	}
// 	return root->idx;
// }

void solve() {
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}

	int i=0;
	int x =0;
	vector<int> ans;
	vector<int> vis(n,0);
	for(i=0;i<32&&i<n;i++){
		int max_idx = -1;
		int temp_x = x;
		int max_x = x;
		for(int j=0;j<n;j++){
			if(!vis[j]&&(temp_x|v[j])>=max_x){
				max_x = (temp_x|v[j]);
				max_idx = j;
			}
		}
		// varbug(max_x);
		vis[max_idx] = 1;
		x = (x|v[max_idx]);
		ans.pb(v[max_idx]);
	}
	for(int i=0;i<n;i++){
		if(!vis[i]){
			ans.pb(v[i]);
		}
	}
	for(int i=0;i<n;i++){
		cout<<ans[i]<<" ";
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