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

//-------------------------------------------------------------------------------------------------------------

const int MAXN = 1000000;

int n, segment_tree[4*MAXN];

vector<int> arr;

// considering 0 based indexing
// sum_from_idx and sum_to_idx both are inclusive
void build(int segment_tree_pos, int sum_from_idx, int sum_to_idx){
	if(sum_from_idx==sum_to_idx){
		segment_tree[segment_tree_pos] = arr[sum_to_idx];
	}else{
		int mid = (sum_from_idx+sum_to_idx)/2;
		build(segment_tree_pos*2+1, sum_from_idx, mid);
		build(segment_tree_pos*2+2, mid+1, sum_to_idx);
		segment_tree[segment_tree_pos] = segment_tree[segment_tree_pos*2+1]+segment_tree[segment_tree_pos*2+2];
	}
}

// return range query from l to r
// segment tree pos should always correspond to the index for range [sum_from idx, sum_to_idx] 
int range_query(int segment_tree_pos, int sum_from_idx, int sum_to_idx, int l, int r){

	if(sum_from_idx==l && sum_to_idx==r){
		return segment_tree[segment_tree_pos];
	}

	int mid = (sum_from_idx+sum_to_idx)/2;
	if(r<=mid){
		return range_query(segment_tree_pos*2+1, sum_from_idx, mid, l, r);
	}else if(l>mid){
		return range_query(segment_tree_pos*2+2, mid+1, sum_to_idx, l, r);
	}else{
		return range_query(segment_tree_pos*2+1,  sum_from_idx, mid, l, mid) + 
		range_query(segment_tree_pos*2+2, mid+1, sum_to_idx, mid+1, r);
	}
}

// sum_from_idx and sum_to_idx are array positions so it'll be always between 0 to n-1 and comparable to array positions
void update(int segment_tree_pos, int sum_from_idx, int sum_to_idx, int array_update_position, int value_to_update){

	if(sum_from_idx==sum_to_idx){
		segment_tree[segment_tree_pos] = value_to_update;
	}else{
		int mid = (sum_from_idx+sum_to_idx)/2;
		if(array_update_position<=mid){
			update(2*segment_tree_pos+1, sum_from_idx, mid, array_update_position, value_to_update);
		}else{
			update(2*segment_tree_pos+2, mid+1, sum_to_idx, array_update_position, value_to_update);
		}
		// both approaches work but combining 2 would be more helpful
		// segment_tree[segment_tree_pos] += value_to_update - arr[array_update_position];
		segment_tree[segment_tree_pos] = segment_tree[segment_tree_pos*2+1]+segment_tree[segment_tree_pos*2+2];
	}

}

//-------------------------------------------------------------------------------------------------------------


void solve() {
	cin>>n;
	arr.resize(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	build(0, 0, n-1);
	int q;
	cin>>q;
	for(int i=0;i<q;i++){
		int x;
		cin>>x;
		if(x==0){
			int l,r;
			cin>>l>>r;
			cout<<range_query(0, 0, n-1, l,r)<<endl;
		}else{
			int pos, val;
			cin>>pos>>val;
			update(0, 0, n-1, pos, val);
		}
	}
}

int32_t main() {
	io;

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif


	int t = 1;
	//cin >> t;
	double time1 = (double)clock() / CLOCKS_PER_SEC;
	while (t--) solve();


	double time2 = (double)clock() / CLOCKS_PER_SEC;
	cerr << "time taken : " << time2 - time1 << " secs" << endl;
}