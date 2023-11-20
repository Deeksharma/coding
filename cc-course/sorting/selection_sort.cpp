#include<bits/stdc++.h>
using namespace std;

/*


*/

// my implementation 
vector<int> selection_sort(vector<int> arr){
	int n = arr.size();


	return arr;
}

// algo book
vector<int> selection_sort_book(vector<int> arr){
	int n = arr.size();


	return arr;
}

// monotonically decreasing - always decreasing or remaining constant, and never increasing; contrast this with strictly decreasing.
 
// monotonically increasing -  always increasing or remaining constant, and never decreasing; contrast this with strictly increasing.


// strictly increasing - A function from a partially ordered domain to a partially ordered range such that x < y implies f(x) < f(y).


int main (){
	vector<int> v{ 1,2,3,4,5 } ;
	vector<int> v2{ 5,4,3,2,1, -9, 8 } ;

	v = selection_sort(v);
	v2 = selection_sort_book(v2);

	for(int i=0;i<5;i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<v2.size();i++){
		cout<<v2[i]<<" ";
	}
	cout<<endl;
}


