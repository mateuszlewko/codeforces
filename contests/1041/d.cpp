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

const int N = 2 * 100 * 1000 + 10;
pii flows[N];
ll pref[N];

int main() {
    _upgrade;

	int n, h;
	cin >> n >> h;

	For (i, n) cin >> flows[i].first >> flows[i].second;
	int rem = flows[0].first - 1;
	flows[0].first = 1;
	flows[0].second -= rem;
	for (int i = 1; i < n; i++) {
		flows[i].first -= rem;
		flows[i].second -= rem;
	}

	pref[0] = 0;
	pref[1] = 1;
	for (int i = 1; i < n; i++) {
		pref[i + 1] = flows[i].first - flows[i - 1].second + pref[i];
	}

	// For (i, n + 2) {
	// 	cout << pref[i] << " ";
	// }
	// cout << "\n";
	h--;

	ll res = 0;
	For (i, n) {
		int pos = upper_bound(pref, pref + n + 1, h + pref[i + 1]) - pref - 1;
		// error(pos);
		// error(pref[i+1]);

		ll left = (h + pref[i + 1]) - pref[pos];
		// error(left);
		res = max(res, flows[pos - 1].second - flows[i].first + left);
	}

	cout << res + 1 << "\n";
}

