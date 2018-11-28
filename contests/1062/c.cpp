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

const int N  = 100 * 1000 + 10;
const ll MOD = 1000 * 1000 * 1000 + 7;
ll pows_pref[N];
ll ones_cnt[N];

int main() {
    _upgrade;

	int n, q;
	cin >> n >> q;

	pows_pref[0] = 0;
	pows_pref[1] = 1;
	ll p = 1;

	For (i, n) {
		p *= 2LL;
		p %= MOD;
		pows_pref[i + 2] = (pows_pref[i + 1] + p) % MOD;
	}

	string s;
	cin >> s;
	For (i, n) {
		ones_cnt[i + 1] = ones_cnt[i] + (s[i] == '1' ? 1 : 0);
	}

	For (i, q) {
		int l, r;
		cin >> l >> r;

		ll len = r - l + 1;
		ll cnt1 = ones_cnt[r] - ones_cnt[l - 1];
		ll res = pows_pref[len] - pows_pref[len - cnt1] + MOD;
		cout << res % MOD << "\n";

	}
}

