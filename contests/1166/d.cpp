#pragma region Template 
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

#pragma endregion 

int main() {
	_upgrade;

	int q;
	cin >> q;
	while (q--) {
		ll a, b, m;
		cin >> a >> b >> m;

		if (a == b) {
			cout << 1 << " " << a << "\n";
			continue;
		}

		int found_k = -1;
		for (int k = 1; k <= 49; k++) {
			ll beg = (1 << (k - 1)) * a + (1 << (k - 1));
			ll end = (1 << (k - 1)) * a + m * (1 << (k - 1));

			error(beg, end);
			
			if (b >= beg && b <= end) {
				found_k = k;
				break;
			}

			if (beg > b) break;
		}

		if (found_k == -1) {
			cout << "-1\n";
			continue;
		}

		vector<ll> ans(found_k + 1, 0);
		ans[0] = a;

		ll k = found_k;
		ll extra_left = b - (1 << (k - 1)) * a - (1 << (k - 1));
		error(k, extra_left);

		ll current_add = 0;

		for (int i = 1; i <= k; i++) {
			ll left_steps = k - i + 1;
			ll left_steps_pow = 1 << (left_steps - 1);
			ll add_cnt = min(m - 1, extra_left / left_steps_pow);
			ll add_val = add_cnt * left_steps_pow;

			error(i, extra_left, add_cnt, add_val);
			
			extra_left -= add_val;

			ans[i] = (1 << (i - 1)) * a + add_cnt + current_add + 1;

			current_add += add_cnt + 1 + current_add;
		}

		// assert(extra_left == 0);
		// assert(ans.back() == b);

		ans[ans.size() - 1] = b;
		cout << ans.size() << " " << ans << "\n";
	}
}

