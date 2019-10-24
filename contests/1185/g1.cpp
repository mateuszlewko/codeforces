#include <bits/stdc++.h> 

using namespace std;

#define For(i, n) for (int i = 0; i < int(n); i++)
#define ForD(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define SORT(x) sort(begin(x), end(x))
#define REP(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

template<typename T, typename U>
pair<T, U>& operator+=(pair<T, U> &lhs, const pair<T, U> &rhs){
	lhs.first += rhs.first;
	lhs.second += rhs.second;
	return lhs;
}

template<typename T, typename U>
pair<T, U>& operator-=(pair<T, U> &lhs, const pair<T, U> &rhs){
	lhs.first -= rhs.first;
	lhs.second -= rhs.second;
	return lhs;
}

template <class T> ostream &operator<<(ostream &os, const vector<T> &container) {
	for (auto &u : container) os << u << " ";
	return os;
}

template <class T, class U> ostream &operator<<(ostream &os, const pair<T, U> &p) {
	os << p.first << " " << p.second;
	return os;
}

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
// #include <ext/pb_ds/detail/standard_policies.hpp>

using namespace __gnu_pbds; 
using namespace std; 

template<typename T>
using pb_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

template<typename T, typename U>
pair<T, U> operator-(const pair<T, U> &l, const pair<T, U> &r) {
	return {l.first - r.first, l.second - r.second};
}
template<typename T, typename U>
pair<T, U> operator+(const pair<T, U> &l, const pair<T, U> &r) {
	return {l.first + r.first, l.second + r.second};
}

#define _upgrade do { ios::sync_with_stdio(0); cin.tie(0); } while (0)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

pii A[100];

ll factor[20];

const ll MOD = 1000 * 1000 * 1000 + 7;

ll n_po_k(ll n, ll k) {
	ll top = factor[n] / factor[k];
	top /= factor[n - k];
	return top;
}

int main() {
	_upgrade;

	factor[0] = 1;
	factor[1] = 1;
	for (ll i = 2; i < 20; i++) {
		factor[i] = factor[i - 1] * i;
	}

	int n, t;
	cin >> n >> t;

	For (i, n) cin >> A[i].first >> A[i].second;

	ll res = 0;

	int curr_n = 0;

	For (i, 1<<n) {
		int tot = 0;
		int type_cnt[] = {0, 0, 0};

		For (j, n) {
			if (i & (1<<j)) {
				tot += A[j].first;
				curr_n++;
				type_cnt[A[j].second - 1]++;
			}
		}

		if (max(type_cnt[0], max(type_cnt[1], type_cnt[2])) > (n + 1) / 2) continue;

		if (tot != t) continue;
		
		for (int s = i; s; s = (s - 1) & i) {
			if (__builtin_popcount(s) != type_cnt[0]) continue;

			bool bad = false;
			int odd_cnt = 0;
			int even_cnt = 0;

			int curr_len = 0;
			For (j, n) {
				if ((i & (1<<j)) == 0) {
					curr_len++;
				} else {
					if (curr_len % 2 == 0) even_cnt++;
					else odd_cnt++;

					if (j > 0 && (i & (1<<(j - 1))) == 1) {
						bad = true;
						break;
					} 
				}
			}

			if (curr_len > 0) {
				if (curr_len % 2 == 0) even_cnt++;
				else odd_cnt++;
			}

			if (bad) continue;

			int x = odd_cnt - abs(type_cnt[2] - type_cnt[1]);
			if (x < 0) continue;

			assert(x % 2 == 0);
			x /= 2;

			ll add = 1;
			For (k, 3) add = (add * factor[type_cnt[k]]) % MOD;
			add = (add * (1LL << even_cnt)) % MOD;
			add = (add * (n_po_k(odd_cnt, x))) % MOD;

			res += add;
			res %= MOD;
		}
	}

	cout << res << "\n";
}
