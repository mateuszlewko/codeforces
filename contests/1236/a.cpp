#include<bits/stdc++.h>
#define For(i, n) for (int i = 0; i < int(n); i++)
using namespace std;

int main() {
	ios::sync_with_stdio(0);

	int t;
	cin >> t;

	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;

		int best = 0;
		for (int i = 0; i <= a; i++) {
			for (int j = 0; j <= b; j++) {
				if (b - j - 2 * i < 0 || c - 2 * j < 0) continue;
				best = max(best, i + 2 * i + j + 2 * j);
			}
		}

		cout << best << "\n";
	}

}
