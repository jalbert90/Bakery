#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct road {
	int u, v, l;
};

int main() {
	int n, m, k, minAmt = (int)1e9 + 5;
	cin >> n >> m >> k;

	vector<road> r(2*m);
	vector<int> a(k);
	map<int, int> mp;

	for (int i = 0; i < m; i++) {
		int f, s, l;
		cin >> f >> s >> l;
		r[2 * i].u = f;
		r[2 * i].v = s;
		r[2 * i].l = l;
		r[2 * i + 1].u = s;
		r[2 * i + 1].v = f;
		r[2 * i + 1].l = l;
	}

	for (int i = 0; i < k; i++) {
		cin >> a[i];
		mp[a[i]] = 1;
	}

	for (int i = 0; i < 2 * m; i++) {
		if (mp[r[i].u] == 0) { continue; }
		else {
			if (mp[r[i].v] == 0) {
				minAmt = min(minAmt, r[i].l);
			}
		}
	}

	if (minAmt == (int)1e9 + 5) {
		cout << -1 << endl;
	}
	else {
		cout << minAmt << endl;
	}
}