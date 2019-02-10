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

int find_max(int x) {
	int best = 0;
	int b = 0;
	for (int i = 1; i < x; i++) {
		int g = __gcd(x ^ i, x & i);
		if (g > best) {
			b = i;
			best = g;
		}
	} 

	return b;
}

int find_best(int x) {
	int best = 0;
	int b = 0;
	for (int i = 1; i < x; i++) {
		int g = __gcd(x ^ i, x & i);
		if (g > best) {
			b = i;
			best = g;
		}
	} 

	return best;
}

string bin(int x) {
	string s;
	while (x) {
		s.push_back('0' + int(x & 1));
		x >>= 1;
	}

	reverse(s.begin(), s.end());
	return s;
}

ll ans(ll a, ll b) {
	return __gcd(a ^ b, a & b);
}

int main() {
    _upgrade;

	int q;
	cin >> q;

	For (i, q) {
		ll a;
		cin >> a;
		ll aa = a;

		bool all_ones = true;
		int cnt = 0;

		while (a) {
			if ((a&1) == 0) {
				all_ones = false;
			}

			a >>= 1;
			cnt++;
		}


		if (!all_ones) {
			ll res = 0;
			cout << (1LL<<cnt) - 1 << "\n";
		} else {
			ll best = 1;
			for (ll j = 2; j * j <= aa; j++) {
				if (aa % j == 0) best = max(best, max(j, aa / j));
			}

			cout << best << "\n";
		}
	}

}

