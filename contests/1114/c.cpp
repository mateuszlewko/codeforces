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

vector<pll> factor(ll x) {
	vector<pll> res; 

	ll a = x;
	for (ll i = 2; i * i <= x; i++) {
		if (i * i > a) break;
		ll cnt = 0;
		while (a % i == 0) {
			cnt++;
			a /= i;
		}

		if (cnt) res.push_back({i, cnt});
	} 

	if (a > 1) res.push_back({a, 1});
	return res;
}

ll get_cnt(ll n, ll f) {
	ll res = 0;
	ll a = f;

	while (true) {
		ll add = n / a;
		res += add;

		if (add == 0) break;
		a *= f;
	}

	return res; 
}

int main() {
    _upgrade;

	ll n, b;
	cin >> n >> b;

	auto fs = factor(b);
	vector<ll> cnts; 

	ll cnt5 = 0;
	ll need5 = 0;
	ll cnt2 = 0;
	ll need2 = 0;

	for (auto f : fs) {
		ll c = get_cnt(n, f.first);
		cnts.push_back(c / f.second);
		if (f.first == 5) {
			cnt5 = c;
			need5 = f.second;
		}

		if (f.first == 2) {
			cnt2 = c;
			need2 = f.second;
		}
	}

	ll res = (1LL<<60);
	for (ll x : cnts) {
		res = min(res, x);
	}

	cnt5 -= res * need5;
	cnt2 -= res * need2;

	assert(cnt2 >= 0);
	assert(cnt5 >= 0);

	ll c = b;
	ll b_c = 0;
	while (c) {
		b_c += c % 10LL;
		c /= 10LL;
	}

	if (b >= 10 && b_c == 1) {
		// res += min(cnt5, cnt2);
	}

	cout << res << "\n";
}

