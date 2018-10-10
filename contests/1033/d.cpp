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

ll find(ll x, ll end, int f) {
	ll beg = 0;

	while (beg + 1 < end) {
		// error(x, beg, end);

		ll mid = (end + beg) / 2;
		ll r = mid * mid;
		if (f >= 3) r *= mid;
		if (f >= 4) r *= mid;

		if (r > x) {
			end = mid;
		} else {
			beg = mid;
		}
	}

	for (ll i = max(1LL, beg - 4); i <= beg + 9; i++) {
		ll r = i * i;
		if (f >= 3) r *= i;
		if (f >= 4) r *= i;

		// error(r, f, )
		if (r == x) return i;
	}

	return -1;
}

pll prime_and_cnt(ll param) {
	ll x = find(param, 60 * 1000L, 4);
	if (x > 0) return {x, 4};

	x = find(param, 2000L * 1000, 3);
	if (x > 0) return {x, 3};

	x = find(param, 2000L * 1000 * 1000, 2);
	if (x > 0) return {x, 2};

	return {-1, 4};
}

ll MOD = 998244353;

int main() {
    // _upgrade;
	int n;
	cin >> n;

	unordered_map<ll, ll> cnt;

	vector<ll> special;

	For (i, n) {
		ll x;
		cin >> x;
		auto pc = prime_and_cnt(x);

		if (pc.first == -1) {
			special.push_back(x);
		} else cnt[pc.first] += pc.second;
	}

	{
		vector<bool> keep;
		For (i, (int)special.size()) keep.push_back(true);

		For (i, (int)special.size() - 1) {
			if (!keep[i]) continue;
			ll myg = -1;

			for (int j = i + 1; j < (int)special.size(); j++) {
				ll g = __gcd(special[i], special[j]);
				if (g > 1) {
					keep[i] = false;
					keep[j] = false;
					myg = g;

					cnt[g]++;
					cnt[special[j] / g]++;
				}
			}

			if (!keep[i] && myg > 0) {
				cnt[myg]++;
				cnt[special[i] / myg]++;
			} 
		}

		vector<ll> keep_again;
		For (i, special.size()) {
			if (keep[i]) 
				keep_again.push_back(special[i]);
		}

		special = keep_again;
		for (ll s : special) {
			cout << "s:" << s << " " ;
		}
		cout << "\n";
	}

	bool once = true;
	while (once && special.size()) {
		vector<ll> keep;
		once = false;

		for (ll x : special) {
			bool here = false;

			for (auto c : cnt) {
				if (x % c.first == 0) {
					here = true;
					once = true;
					cnt[c.first]++;
					cnt[x / c.first]++;
					break;
				}
			}

			if (!here) keep.push_back(x);
		}

		special = keep;
	}

	ll res = 1;
	for (auto c : cnt) {
		error(c.first, c.second);

		res = (res * ((c.second + 1) % MOD)) % MOD;
	}

	For (i, special.size()) {
		res = (res * 4) % MOD;
	}

	cout << res << "\n";
}

