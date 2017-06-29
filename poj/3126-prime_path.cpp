#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int stepping[1300][15];
int number_s[1300] = { 0 };
int primes[1300];

int search(const int x, const int y) {
	vector<int> a;
	vector<int> b;
  //backtracking to eliminate loops
	set<int> taboo;
	int depth = 1;
	a.push_back(x);
	taboo.insert(x);
	while (!a.empty()) {
		while (!a.empty()) {
			int j = a.back();
			for (int i=0; i < number_s[j]; i++) {
				if (taboo.count(stepping[j][i]) == 0) {
					b.push_back(stepping[j][i]);
					taboo.insert(stepping[j][i]);
				}
				
			}
			a.pop_back();
		
		}
		//a.clear();
		depth++;
		a.swap(b);
	}
	return 0;
}


int main() {
	//pre-compute primes
	primes[0] = 2;
	int prime_c = 1;
	for (int i = 3; i < 10000; i++) {
		bool prime_flag = true;
		for (int j = 0; j < prime_c && primes[j] * primes[j] <= i; j++) {
			if (i%primes[j] == 0) {
				prime_flag = false;
				break;
			}
		}
		if (prime_flag) {
			primes[prime_c] = i;
			prime_c++;
		}
	}
	//precompute possible 1 hamilton distance paths
	for (int i = 0; i < prime_c; i++)
	{
		int _;
		for (int j0 = 1; j0 < 10000; j0 = j0 * 10) {
			int _a;
			_a = primes[i] / j0;
			_a = _a % 10;
			_a = _a*j0;
			for (int j1 = 0; j1 < 10; j1++) {
				
				_ = primes[i] - _a;
				_ = _ + j1 * j0;
				if (binary_search(primes, primes + prime_c, _)) {
					if (_ != primes[i] && _>1000) {
						stepping[i][number_s[i]] = lower_bound(primes, primes + prime_c, _) - primes;
						number_s[i]++;
						max_stepping = max(number_s[i], max_stepping);
					}
				}
			}
		}
		
	}
  //io handling
	int input_count;
	cin >> input_count;
	for (int i = 0; i < input_count; i++) {
		int in_a, in_b;
		cin >> in_a >> in_b;
		if (in_a == in_b) {
			cout << 0 << endl;
			continue;
		}
		cout << search(lower_bound(primes, primes + prime_c, in_a)-primes, lower_bound(primes, primes + prime_c, in_b)-primes)<<endl;
	}
	return 0;
}
