#include<bits/stdc++.h>
#define For(i, n) for (int i = 0; i < int(n); i++)
using namespace std;

typedef long long ll;
const ll M = 1000 * 1000 * 1000 + 7;

ll poww(ll x, ll n) {
	if (n == 0) return 1;
	ll r = poww(x, n / 2);

	r = (r * r) % M;
	if (n & 1) {
		r = (r * x) % M;
	}

	return r;
}

int main() {
	ios::sync_with_stdio(0);

	ll n, m;
	cin >> n >> m;

	ll r = (M + poww(2, m) - 1) % M;
	cout << poww(r, n) << "\n";
}
