#include<bits/stdc++.h>
#define For(i, n) for (int i = 0; i < int(n); i++)
using namespace std;

typedef long long ll;
/*
int n;
void go(int i, int j) {
	if (i > n) return;

	cout << j + (i - 1) * n << " ";

	if (n % 2 == 1) {
		int mid = (n + 1) / 2;
		int d = mid - j;
		go(i + 1, j + 2 * d);
	} else {
		int mid = -1;

		if (j <= n / 2) {
			mid = n / 2 + 1;
		} else mid = n / 2;

		int d = mid - j;
		go(i + 1, j + 2 * d);
	}
}
*/
int main() {
	ios::sync_with_stdio(0);

	int n;
	cin >> n;
	// For (i, n) {
	// 	go(1, i + 1);
	// 	cout << "\n";
	// }

	For (i, n) {
		For (j, n) {
			if (j % 2 == 0) cout << (j * n) + i + 1 << " ";
			else cout << ((j + 1) * n) - i << " ";
		}

		cout << "\n";
	}
}
