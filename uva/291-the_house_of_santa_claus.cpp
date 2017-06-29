//dfs
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;
const int edges = 8;
set<int> house[6];

vector<int> ans;

void search(const int i,const int depth) {
	if (depth == edges) {
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i];
		}
		cout << endl;
		return;
	}
  //copy as set<int> house modified
	vector<int> iter_help;
	copy(house[i].begin(), house[i].end(), back_inserter(iter_help));
	for (auto j:iter_help) {
		house[i].erase(j);
		if (house[j].count(i)) {
			house[j].erase(i);
			ans.push_back(j);
			search(j, depth + 1);
			ans.pop_back();
			house[j].insert(i);
		}
		house[i].insert(j);
	}
}

int main() {
  //construction
	house[1] = { 2,3,5 };
	house[2] = { 1,3,5 };
	house[3] = { 1,2,4,5 };
	house[4] = { 3,5 };
	house[5] = { 1,2,3,4 };
	ans.push_back(1);
	search(1, 0);
	ans.pop_back();
	return 0;
}
