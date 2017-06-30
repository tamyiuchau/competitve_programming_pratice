#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int,int> > wood;

int wood_compare(pair<int, int> a, pair<int, int> b) {
	return a.first + a.second > b.first+ b.second;
}


int counter(vector<pair<int, int> > &wood) {
	vector<pair<int, int> > counter;
	for (auto i : wood) {
		bool flag = true;
		for (auto j : counter) {
			if (j.first >= i.first && j.second >= i.first) {
				flag = false;
				break;
			}
		}
		if (flag)counter.push_back(i);
	}
	return counter.size();
}

int main() {
	int count;
	cin >> count;
	for (int i = 0; i < count; i++) {
		int pair_count;
		cin >> pair_count;
		wood.clear();
		for (int j = 0; j < pair_count; j++) {
			int a, b;
			cin >> a >> b;
			wood.push_back(pair<int, int>(a, b));
		}
		sort(wood.begin(), wood.end(), wood_compare);
		cout << counter(wood) << endl;
	}
	return 0;
}
