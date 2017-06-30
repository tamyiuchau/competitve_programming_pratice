#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
vector<int> fence;



int search(const vector<int>::iterator begin,const vector<int>::iterator end) {
	if (end - begin == 1)return 0;
	if (end-begin==2)return accumulate(begin, end, 0);
	int sum = accumulate(begin, end,0);
	vector<int>::iterator middle = upper_bound(begin, end, sum / (end - begin));
	if (*middle - *(middle - 1) > *(middle + 1) - *middle)middle++;
	return sum + search(begin, middle) + search(middle, end);
}

int main() {
	int count;
	cin >> count;
	for (int i = 0; i < count; i++) {
		int _tmp;
		cin >> _tmp;
		fence.push_back(_tmp);
	}
	sort(fence.begin(), fence.end());
	cout << search(fence.begin(), fence.end());
	return 0;
}
