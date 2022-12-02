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

	sort(r.begin(), r.end(), [](road a, road b) {return a.u < b.u;});

	for (int i = 0; i < k; i++) {
		int key = a[i];
		vector<int>::iterator it;
		vector<road>::iterator fit, lit;
		int fio, ubnd;
		fit = find_if(r.begin(), r.end(), [key](road a) {return a.u == key;});
		fio = fit - r.begin();
		lit = upper_bound(fit, r.end(), key, [](int value, road a) {return value < a.u;});
		ubnd = lit - r.begin();
		for (int j = fio; j < ubnd; j++) {
			if (r[j].u == a[i]) {
				if (mp[r[j].v] == 0) {
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