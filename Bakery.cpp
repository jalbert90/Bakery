#include <iostream>
#include <vector>

using namespace std;

struct road {
	int u, v, l;
};

int main() {
	int n, m, k, minAmt = (int)1e9 + 5;
	cin >> n >> m >> k;

	vector<road> r(m);
	vector<int> a(k);

	for (int i = 0; i < m; i++) {
		cin >> r[i].u >> r[i].v >> r[i].l;
	}

	for (int i = 0; i < k; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < k; i++) {
		vector<int>::iterator it;
		for (int j = 0; j < m; j++) {
			if (r[j].u == a[i]) {
				it = find(a.begin(), a.end(), r[j].v);
				if (it == a.end()) {
					minAmt = min(minAmt, r[j].l);
				}
			}
			else if (r[j].v == a[i]) {
				it = find(a.begin(), a.end(), r[j].u);
				if (it == a.end()) {
					minAmt = min(minAmt, r[j].l);
				}
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