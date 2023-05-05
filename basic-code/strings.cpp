#include<bits/stdc++.h>
using namespace std;

vector<int> stringSearch(string big, string small) {
	//store the occurrences in the result vector
	vector<int> result;
	int index = -1;
	do {
		index = big.find(small, index + 1);
		if (index != -1) {
			result.push_back(index);
		}
	} while (index != -1);

	return result;
}

int main() {
	string s; // dynamic array
	//getline(cin, s); // use getline instead of cin, to take input as lines
	// the 3rd argument will be used as a delimiter, till this character take the input.
	//cin >> s;
	// find method in string - imp

	string paragraph = "Yay Deeksha you did it, I'm so proud of you Deeksha.";
	int index = paragraph.find("Deeksha");
	if (index != -1) {
		cout << "first occurrence is at " << index << endl;
	}
	if (index == -1) cout << "string not found" << endl;
	index = paragraph.find("Deeksha", index + 1); // find after index i+1
	if (index != -1) {
		cout << "second occurrence is at " << index << endl;
	}

	cout << s << endl;

}