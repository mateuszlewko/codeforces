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

vector<ll> factors(ll x) {
	vector<ll> res; 

	for (ll i = 1; i * i <= x; i++) {
		if (x % i == 0) {
			res.push_back(i);
			if (x / i != i) res.push_back(x / i);
		}
	}

	return res;
}

const ll MOD = 1000 * 1000 * 1000LL + 7LL;

long long _inv(long long a, long long b){
 return 1LL<a ? b - _inv(b%a,a)*b/a : 1LL;
}

ll inv(ll x) {
	return _inv(x, MOD);
}

const int DIVS = 50 * 1000;

ll prev_ans[DIVS];
ll next_ans[DIVS];

unordered_map<ll, ll> renum;
unordered_map<ll, ll> renum_rev;

int main() {
    _upgrade;

	ll n;
	int k;
	cin >> n >> k;

	auto fs = factors(n);
	SORT(fs);
	For (i, (int)fs.size()) {
		renum[fs[i]] = i;
		renum_rev[i] = fs[i];
	}

	// unordered_map<ll, ll> prev_ans;
	vector<pair<ll, pair<ll, vector<ll>>>> my_divs;

	for (auto f : fs) {
		vector<ll> divs;
		for (auto other : fs) {
			if (f % other == 0) divs.push_back(renum[other]); 
		}

		SORT(divs);

		my_divs.push_back({renum[f], {inv((ll)divs.size()) % MOD, divs}});
	}

	ll divs_inv = inv((ll)fs.size()) % MOD;

	for (auto& f : my_divs) {
		prev_ans[f.first] = divs_inv;
		// cout << "init ans: " << f.first << ", => " << prev_ans[f.first] << endl;
	}

	SORT(my_divs);

	For (i, k - 1) {
		// unordered_map<ll, ll> next_ans;
		// For (j, (int)my_divs.size()) {
		for (auto& f : my_divs) {
			// auto& f = my_divs[j];
			
			ll my_prev = prev_ans[f.first];
			ll to_add = (my_prev * f.second.first) % MOD;
			

			for (auto d : f.second.second) {
			// For (k, (int)f.second.second.size()) {
				// auto d = f.second.second[k];
				next_ans[d] += to_add;
				// next_ans[d] %= MOD;
			}
		}

		For (j, (int)fs.size()) {
			prev_ans[j] = next_ans[j] % MOD;
			next_ans[j] = 0;
		}
	}

	ll ans = 0;
	For (i, (int)fs.size()) {
		ll res = prev_ans[i] % MOD;
		ll tru = renum_rev[i] % MOD;

		ans = (ans + res * tru) % MOD;
	}

	cout << ans << "\n";
}