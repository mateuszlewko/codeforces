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

const int N = 100 * 1000 + 10;
vector<int> G[N];

bool vis[N];

void dfs(int x) {
  if (vis[x]) return;

  vis[x] = true;
  for (int y : G[x]) dfs(y);
}

bool is_conn(int n) {
  dfs(1);

  for (int i = 1; i <= n; i++) {
    if (!vis[i]) return false;
  }

  return true;
}

bool has[3][N];
bool taken[N];

int result[N];
int v_cnt[N];

int main() {
  _upgrade;

  int n, m;
  cin >> n >> m;

  vector<pii> edges;

  For(i, m) {
    int x, y;
    cin >> x >> y;
    G[x].push_back(y);
    G[y].push_back(x);
    edges.emplace_back(x, y);
  }

  if (!is_conn(n)) {
    error("0");
    cout << "-1\n";
    return 0;
  }

  vector<int> gr[3];

  for (int y : G[1]) {
    has[0][y] = true;
  }

  // gr[0].push_back(1);
  taken[1] = true;
  for (int i = 1; i <= n; i++) {
    if (!has[0][i]) {
      gr[0].push_back(i);
      taken[i] = true;
    }
  }

  assert(G[1].size());

  int v2 = G[1][0];
  for (int y : G[v2]) {
    has[1][y] = true;
  }

  // gr[1].push_back(v2);
  taken[v2] = true;

  for (int i = 1; i <= n; i++) {
    if (!has[1][i]) {
      gr[1].push_back(i);
      taken[i] = true;
    }
  }

  for (int i = 1; i <= n; i++) {
    if (!taken[i]) {
      gr[2].push_back(i);
    }
  }

  For(i, 3) {
    // error(i, gr[i]);

    for (int x : gr[i]) {
      if (result[x] != 0) {
        error("1");
        cout << "-1\n";
        return 0;
      }

      result[x] = i + 1;
      v_cnt[x] = n - int(gr[i].size());
    }
  }

  for (auto [x, y] : edges) {
    if (result[x] == result[y]) {
      error("2");
      cout << "-1\n";
      return 0;
    }

    v_cnt[x]--;
    v_cnt[y]--;
  }

  for (int i = 1; i <= n; i++) {
    if (v_cnt[i] != 0) {
      error("3");
      cout << "-1\n";
      return 0;
    }
  }

  For(i, 3) {
    if (gr[i].empty()) {
      error("5");
      cout << "-1\n";
      return 0;
    }
  }

  For(i, n) { cout << result[i + 1] << "\n"; }
}
