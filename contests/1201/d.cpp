#include <bits/stdc++.h>

using namespace std;

#define For(i, n) for (int i = 0; i < int(n); i++)
#define ForD(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define SORT(x) sort(begin(x), end(x))
#define REP(i, begin, end)                            \
  for (__typeof(end) i = (begin) - ((begin) > (end)); \
       i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

template <typename T, typename U>
pair<T, U> &operator+=(pair<T, U> &lhs, const pair<T, U> &rhs) {
  lhs.first += rhs.first;
  lhs.second += rhs.second;
  return lhs;
}

template <typename T, typename U>
pair<T, U> &operator-=(pair<T, U> &lhs, const pair<T, U> &rhs) {
  lhs.first -= rhs.first;
  lhs.second -= rhs.second;
  return lhs;
}

template <class T>
ostream &operator<<(ostream &os, const vector<T> &container) {
  for (auto &u : container) os << u << " ";
  return os;
}

template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  os << p.first << " " << p.second;
  return os;
}

#include <ext/pb_ds/assoc_container.hpp>  // Common file
#include <ext/pb_ds/tree_policy.hpp>  // Including tree_order_statistics_node_update
// #include <ext/pb_ds/detail/standard_policies.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using pb_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#if DEBUG
#define error(args...)                       \
  {                                          \
    string _s = #args;                       \
    replace(_s.begin(), _s.end(), ',', ' '); \
    stringstream _ss(_s);                    \
    istream_iterator<string> _it(_ss);       \
    err(_it, args);                          \
  }
void err(istream_iterator<string>) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << endl;
  err(++it, args...);
}
#else
#define error(...) \
  do {             \
  } while (0)
#endif

template <typename T, typename U>
pair<T, U> operator-(const pair<T, U> &l, const pair<T, U> &r) {
  return {l.first - r.first, l.second - r.second};
}
template <typename T, typename U>
pair<T, U> operator+(const pair<T, U> &l, const pair<T, U> &r) {
  return {l.first + r.first, l.second + r.second};
}

#define _upgrade             \
  do {                       \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
  } while (0)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<ll> safe_cols;
map<int, vector<ll>> on_lvl;
vector<pair<int, pii>> lvl_range;

const ll INF = 1LL << 58;

// ll go_down(int ix, int lvl, int col, ll cost = 0) {
//   if (lvl == 1 && col == 1) return cost;

// }

const int N = 600 * 1000 + 100;
ll dp[N][2];

ll get_smaller(ll c) {
	int ix = lower_bound(safe_cols.begin(), safe_cols.end(), c) - safe_cols.begin();
	if (ix == 0) return -INF;
	return safe_cols[ix - 1];
}

ll get_geq(ll c) {
	int ix = lower_bound(safe_cols.begin(), safe_cols.end(), c) - safe_cols.begin();
	if (ix == int(safe_cols.size())) return INF;
	return safe_cols[ix];
}

int main() {
  _upgrade;

  int n, m, kk, qq;
  cin >> n >> m >> kk >> qq;

  For(i, kk) {
    int r, c;
    cin >> r >> c;
    on_lvl[r].push_back(c);
  }

	For (i, qq) {
		int c;
		cin >> c;
		safe_cols.push_back(c);
	}

	SORT(safe_cols);
  assert(int(safe_cols.size()) > 0);

  for (auto [lvl, cs] : on_lvl) {
    ll mi = INF;
    ll ma = 0;

    for (ll c : cs) {
      mi = min(mi, c);
      ma = max(ma, c);
    }

    lvl_range.push_back({lvl, {mi, ma}});
  }

  assert(int(lvl_range.size()) < N);

  For(i, lvl_range.size()) {
    auto [lvl, rr] = lvl_range[i];
    auto [p, q] = rr;
    ll lvl_diff = lvl - (i == 0 ? 1 : lvl_range[i - 1].first);
    // j - nowa
    For(j, 2) {
      ll mn = INF;
      ll next_c = j == 0 ? p : q;

      // k - stara
      For(k, 2) {
        ll prev_c = i == 0 ? 1
                            : (k == 0 ? lvl_range[i - 1].second.first
                                      : lvl_range[i - 1].second.second);
				
				ll prev_dp = i == 0 ? 0 : dp[i - 1][k];
				ll smaller_c = get_smaller(prev_c);
				ll cost = abs(prev_c - smaller_c) + abs(smaller_c - next_c);

				ll geq_c = get_geq(prev_c);
				cost = min(cost, abs(prev_c - geq_c) + abs(geq_c - next_c));

				if (lvl_diff == 0) {
					cost = min(cost, abs(prev_c - next_c));
				}

				// error(k, mn, cost, prev_dp, prev_c, geq_c, smaller_c);
				mn = min(mn, cost + prev_dp);
      }

			assert(mn < INF);
			// error(mn, i, j);

      dp[i][(j + 1) % 2] = (ll)mn + (ll)lvl_diff + q - p;
    }
  }

	int sz = int(lvl_range.size());
	cout << min(dp[sz - 1][0], dp[sz - 1][1]) << "\n";

  // auto [lvl, rr] = lvl_range.back();
  // int ix = int(lvl_range.size()) - 1;

  // ll res = min(go_down(ix, lvl, rr.first), go_down(ix, lvl, rr.second)) +
  //          rr.second - rr.first;
  // cout << res << "\n";
}
