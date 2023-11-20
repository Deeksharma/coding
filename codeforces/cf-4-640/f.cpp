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

// 0 0 1
// 8 7 8
string solve(int t) {
	int n0, n1, n2;
	cin>>n0>>n1>>n2;

	string ans = "";

	if(n0 == 0 && n1 == 0){
		// return n2+1 1's
		for(int i=0;i<=n2;i++){
			ans+="1";
		}
		cout<< ans<<endl;
		return ans;

	}
	if(n2 == 0 && n1 == 0){

		// return n0+1 0's

		for(int i=0;i<=n0;i++){
			ans+="0";
		}
		cout<< ans<<endl;
		return ans;
	}
	if(n0 == 0){
		// create a bianay string of length n1 0101..(reverse and add to the left of the 11 string)
		// add it with 1111 (n2+1) 1's
		string temp = "";
		string bit = "0";
		for(int i=0;i<n1;i++){
			temp += bit;
			if(bit == "0"){
				bit = "1";
			}else{
				bit = "0";
			}
		}
		reverse(temp.begin(), temp.end());
		ans += temp;

		for(int i=0;i<=n2;i++){
			ans+="1";
		}

		cout<< ans<<endl;
		return ans;
	}
	if(n2 == 0){
		// create a bianay string of length n1 101..
		// add it with 000 (n2+1) 1's
		for(int i=0;i<=n0;i++){
			ans+="0";
		}
		string bit = "1";

		for(int i=0;i<n1;i++){
			ans += bit;
			if(bit == "0"){
				bit = "1";
			}else{
				bit = "0";
			}
		}
		cout<< ans<<endl;
		return ans;
	}

	// n0+1 0's n1/2 10's  n1+1 1's 

	
	if(n1%2){
		for(int i=0;i<=n0;i++){
			ans+="0";
		}

		for(int i=0;i<n1/2;i++){
			ans+="10";
		}

		for(int i=0;i<=n2;i++){
			ans+="1";
		}
		cout<<ans<<endl;
		return ans;
	}else{
		for(int i=0;i<=n0;i++){
			ans+="0";
		}

		for(int i=0;i<(n1-1)/2;i++){
			ans+="10";
		}

		for(int i=0;i<=n2;i++){
			ans+="1";
		}
		ans = "1" + ans;

		cout<<ans<<endl;
		return ans;
	}

}

// void check_ans(string s){
// 	int n0=0, n1=0,n2=0;
// 	for(int i=0;i<s.size()-1;i++){
// 		if(s.substr(i,2)=="01" || s.substr(i,2)=="10"){
// 			n1++;
// 		}else if(s.substr(i,2)=="00"){
// 			n0++;
// 		} else{
// 			n2++;
// 		}
// 	}

// 	cout<<n0<<" "<<n1<< " "<< n2<<endl;
// }

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
	while (t--){
		string ans = solve(t);
		// check_ans(ans);

	}


	double time2 = (double)clock() / CLOCKS_PER_SEC;
	cerr << "time taken : " << time2 - time1 << " secs" << endl;
}