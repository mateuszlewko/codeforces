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

const int INF = 1 << 30;

pii next_pos(char c, int x, int y) {
  if (c == 'W') return {x, y + 1};
  if (c == 'A') return {x - 1, y};
  if (c == 'D') return {x + 1, y};
	return {x, y - 1};
}

bool hit_twice(vector<pii> &pos, bool which, int min_k, int max_k) {
	int min_k_cnt = 0;
	int max_k_cnt = 0;
	int hit_cnt = 0;

	for (auto [x, y] : pos) {
		int k = which == 0 ? x : y;
		if (k == min_k) {
			if (max_k_cnt > 0) {
				hit_cnt++;
				max_k_cnt = 0;
			}

			min_k_cnt = 1;
		} else if (k == max_k) {
			if (min_k_cnt > 0) {
				hit_cnt++;
				min_k_cnt = 0;
			}

			max_k_cnt++;
		}

		if (hit_cnt >= 2) return true;
	}

	return hit_cnt >= 2;
}

int main() {
  _upgrade;

  int t;
  cin >> t;

  while (t--) {
    string s;
    cin >> s;

    int min_x = 0;
    int max_x = 0;
    int min_y = 0;
    int max_y = 0;
		int x = 0;
		int y = 0;

		vector<pii> pos;
		pos.push_back({x, y});

		for (char c : s) {
			auto nx = next_pos(c, x, y);
			x = nx.first;
			y = nx.second;
			pos.push_back({x, y});

			min_x = min(min_x, x);
			min_y = min(min_y, y);
			max_x = max(max_x, x);
			max_y = max(max_y, y);
		}

		bool hit_twice_x = hit_twice(pos, 0, min_x, max_x);
		bool hit_twice_y = hit_twice(pos, 1, min_y, max_y);
		
		ll dx = max_x - min_x + 1;
		ll dy = max_y - min_y + 1;
		
		ll best = dx * dy;
		error(dx, dy);
		if (!hit_twice_x) best = min(best, max(2LL, dx - 1) * dy);
		if (!hit_twice_y) best = min(best, max(2LL, dy - 1) * dx);

		cout << best << "\n";
  }
}
