#include<bits/stdc++.h>
using namespace std;


// bubble sort mein saare element ko adjaent elemnt
// se compare krte h, aur swap kete jaate j,
// eventually last element tumhara highest number ho jayega

// worst case complexity - o(n^2)
// best case complexity - o(n)

vector<int> bubble_sort(vector<int> arr){
	int n = arr.size();
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				swap(arr[j], arr[j+1]);
			}
		}
	}
	return arr;
}

vector<int> bubble_sort_modified(vector<int> arr){
	int n = arr.size();
	bool swapped = false;
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				swap(arr[j], arr[j+1]);
				swapped = true;
			}
		}
		if(!swapped){ // array is aready sorted 
			break;
		}
	}
	return arr;
}



int main(){
	vector<int> v{ 1,2,3,4,5 } ;
	vector<int> v2{ 5,4,3,2,1 } ;

	v = bubble_sort(v);
	v2 = bubble_sort(v2);

	for(int i=0;i<5;i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<5;i++){
		cout<<v2[i]<<" ";
	}
	cout<<endl;
}