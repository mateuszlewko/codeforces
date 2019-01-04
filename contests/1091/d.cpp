#pragma region Template 
#include <bits/stdc++.h> 

using namespace std;

#define For(i, n) for (int i = 0; i < (n); i++)
#define ForD(i, n) for (int i = (n) - 1; i >= 0; i--)
#define SORT(x) sort(begin(x), end(x))
#define REP(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

#if DEBUG
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string>) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}
#else
#define error(...) do {} while (0)
#endif

#define _upgrade do { ios::sync_with_stdio(0); cin.tie(0); } while (0)

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#pragma endregion 

ll M = 998244353LL;

int main() {
    _upgrade;

	ll n;
	cin >> n;

	if (n == 1) {
		cout << "1\n";
		return 0;
	} else if (n == 2) {
		cout << "2\n";
		return 0;
	} else if (n == 3) {
		cout << "9\n";
		return 0;
	} else if (n == 4) {
		cout << "56\n";
		return 0;
	}

	ll fact2 = 6;
	ll res = 14;

	for (int i = 5; i <= n; i++) {
		error(fact2);
		res = (res * (i - 1) + ((i - 1) * fact2) % M - 1LL + 4LL * M) % M;
		error(i, res);

		fact2 *= (i - 1);
		fact2 %= M;
	}

	cout << (res * n) % M << "\n";

	// (n-1)! / 2
	// ll n1f = 1LL; //TODO;
	// for (ll i = 3LL; i < n; i++) {
	// 	n1f = (n1f * i) % M;
	// }

	// ll res = (2LL * M + (n - 1) * n1f + (n - 2) * n1f - (n - 1)) % M;
	// error(n1f, res);
	// res = (res * n) % M;
	// cout << res << "\n";

	// vector<int> perm;
	// vector<int> res;

	// For (i, n) perm.push_back(i + 1);
	// do {
	// 	for (int x : perm) {
	// 		cout << x << " ";
	// 		res.push_back(x);
	// 	}
	// 	cout << endl;
	// } while (next_permutation(perm.begin(), perm.end()));

	// cout << "sums: " << endl;

	// for (int i = 0; i < (int)res.size() - n + 1; i++) {
	// 	int s = 0;
	// 	for (int j = i; j < i + n; j++) s += res[j];
	// 	cout << (s == 21 ? "+" : "-") << " ";
	// }
}

