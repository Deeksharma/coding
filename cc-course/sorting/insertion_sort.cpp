#include<bits/stdc++.h>
using namespace std;

/*
insertion sort mein cards sorting wala algo lagta h

left hand mein sara card hamesha sorted hi hoga
right mein pile of cards h

right hand se card uthao aur left mein uska shi position pr daalo 


algo mein humlog array leftmost size se shuru krenge

size 1 sort kro
size 2 sort kro
.
.
.
size n sort kro

*/

// my implementation 
vector<int> insertion_sort(vector<int> arr){
	int n = arr.size();

	for(int i=0;i<n-1;i++){
		int ele = arr[i+1];
		int j = i;
		for(;j>=0;j--){
			if(arr[j]>ele){
				swap(arr[j], arr[j+1]);
			}else{
				break;
			}
		}
	}
	return arr;
}

// algo book
vector<int> insertion_sort_book(vector<int> arr){
	int n = arr.size();

	for(int i=1;i<n;i++){
		int ele = arr[i];
		int j = i-1;
		while(j>=0&&arr[j]>ele){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = ele;
	}
	return arr;
}

// monotonically decreasing - always decreasing or remaining constant, and never increasing; contrast this with strictly decreasing.
 
// monotonically increasing -  always increasing or remaining constant, and never decreasing; contrast this with strictly increasing.


// strictly increasing - A function from a partially ordered domain to a partially ordered range such that x < y implies f(x) < f(y).


int main (){
	vector<int> v{ 1,2,3,4,5 } ;
	vector<int> v2{ 5,4,3,2,1, -9, 8 } ;

	v = insertion_sort(v);
	v2 = insertion_sort_book(v2);

	for(int i=0;i<5;i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<v2.size();i++){
		cout<<v2[i]<<" ";
	}
	cout<<endl;
}


/*

loop invariant - a property of loop that doesnt changes in any iteration, used to proof algos -> kinda induction principle

Initialization: It is true prior to the ûrst iteration of the loop.
Maintenance: If it is true before an iteration of the loop, it remains true before the next iteration.
Termination: The loop terminates, and when it terminates, the invariant along with the reason that the loop terminated - gives us a useful property that
- usually helps show that the algorithm is correct.

in case of insertion sort - loop variant is (0 to i-1) ta k ka array hamesha sorted rhega for every i starts from 1 


*/

