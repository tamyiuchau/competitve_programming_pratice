#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	string input;
	while (cin >> input) {
		if (input == "#") {
			break;
		}
		else {
			if (next_permutation(input.begin(), input.end())) {
				cout << input << endl;
			}
			else {
				cout << "No Successor" << endl;
			}
		}
	}
	return 0;
}
