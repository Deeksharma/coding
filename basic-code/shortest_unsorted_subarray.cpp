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
#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
	const char* comma = strchr (names + 1, ',');
	cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}


const int N = 200005;

int dir4[4][2] = {{1, 0}, { -1, 0}, {0, -1}, {0, 1}};
int dir8[8][2] = {{1, 0}, { -1, 0}, {0, -1}, {0, 1}, {1, 1}, { -1, 1}, {1, -1}, { -1, -1}};

int power(int a, int b) {
	if (b == 0) return 1;
	if (b % 2) return (a * (power((a * a) % mod, b / 2) % mod)) % mod;
	else return power((a * a) % mod, b / 2) % mod;
}

void solve() {

}

bool outOfOrder(vector<int> nums, int i) {
	if (i == 0) {
		if (nums[i] > nums[i + 1]) return true;
	}
	else if (i == nums.size() - 1) {
		if (nums[i] < nums[i - 1]) return true;
	}
	else {
		if (nums[i] > nums[i + 1] || nums[i] < nums[i - 1]) return true;
	}
	return false;
}
int findUnsortedSubarray(vector<int>& nums) {
	if (nums.size() == 1) return 0;
	// 1. find the largest and smallest number that is out of order then find out where thry should be put, this will give the answer
	// 2. Finding just the two exterme elements that are out of order and are present at farthest - X, wrong approach h eg. 1 9 2 3 4 5 5 6 8
	int smallest = INT_MAX;
	int largest = INT_MIN;
	for (int i = 0; i < nums.size(); i++) {
		int element = nums[i];
		if (outOfOrder(nums, i)) {
			smallest = min(smallest, element);
			largest = max(largest, element);
		}
	}

	if (smallest == INT_MAX) return 0;
	// now we need to find the position of smallest and largest
	int l, r;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] > smallest) {
			l = i;
			break;
		}
	}
	for (int i = nums.size() - 1; i >= 0; i--) {
		if (nums[i] < largest) {
			r = i;
			break;
		}
	}
	return r - l + 1;
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