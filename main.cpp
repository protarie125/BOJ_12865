#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, k;
	cin >> n >> k;

	auto bag = vvi(n + 1, vi(k + 1, 0));

	auto ws = vi(n + 1);
	auto vs = vi(n + 1);
	for (auto i = 1; i <= n; ++i) {
		cin >> ws[i] >> vs[i];
	}

	for (auto i = 1; i <= n; ++i) {
		const auto& w = ws[i];
		const auto& v = vs[i];

		for (auto j = 1; j <= k; ++j) {
			if (j - w < 0) {
				bag[i][j] = bag[i - 1][j];
				continue;
			}

			const auto& p1 = bag[i - 1][j];
			const auto& p2 = bag[i - 1][j - w] + v;
			bag[i][j] = max(p1, p2);
		}
	}

	cout << bag[n][k];

	return 0;
}