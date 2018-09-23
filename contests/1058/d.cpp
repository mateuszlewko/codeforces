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

int main() {
    _upgrade;
	ll n, m, k;
	cin >> n >> m >> k;

	ll res_n = n;
	ll res_m = m;

	bool dived2 = false;
	ll curr_k = k;

	ll d = 2;
	while (curr_k > 1 && d * d <= k) {
		while (curr_k % d == 0) {
			// error(curr_k, d);

			if (d == 2 && !dived2) {
				dived2 = true;
				curr_k /= d;
			} else if (res_n % d == 0) {
				res_n /= d;
				curr_k /= d;
			} else if (res_m % d == 0) {
				res_m /= d;
				curr_k /= d;
			} else {
				cout << "NO\n";
				return 0;
			}
		}

		d++;
	}

	if (res_n % curr_k == 0) {
		res_n /= curr_k;
		curr_k = 1;
	} else if (res_m % curr_k == 0) {
		res_m /= curr_k;
		curr_k = 1;
	}

	if (!dived2 && curr_k % 2 == 0) {
		curr_k /= 2;
		dived2 = true;
	}

	if (curr_k != 1) {
		cout << "NO\n";
		return 0;
	}

	if (!dived2) {
		if (res_n * 2 <= n) {
			res_n *= 2;
		} else if (res_m * 2 <= m) {
			res_m *= 2;
		} else {
			cout << "NO\n";
			return 0;
		}
	}

	cout << "YES\n" << "0 0\n" << "0 " << res_m << "\n" << res_n << " 0\n";
}

