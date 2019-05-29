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

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#pragma endregion

int n, m, k;
unordered_map<ll, ll> edges;
vector<pair<pii, ll>> edges_v;

const ll INF = 1LL<<61;

inline ll hash_edge(int x, int y) {
    if (x > y) swap(x, y);

    ll e = x;
    e <<= 22;
    e |= y;
    return e;
}

ll check_edges(vector<pii> p) {
    if ((int)p.size() != k) return INF;
    if (p.front().first != 1) return INF;
    if (p.back().second != n) return INF;

    //error(p);

    ll cost = 0;
    For (i, p.size()) {
        auto e = p[i];
        if (i > 0 && e.first != p[i - 1].second) return INF;

        ll he = hash_edge(e.first, e.second);
        if (edges.count(he) == 0) return INF;

        cost += edges[he];
    }

    return cost;
}

void solve_n() {
    ll best = INF;

    For (i, (1<<n)) {
        vector<pii> perm;
        For (j, n) {
            if (i & (1 << j)) perm.push_back({1 + perm.size(), j + 1});
        }

        if ((int)perm.size() != k + 1) continue;
        if (perm.front().second != 1 || perm.back().second != n) continue;

        do {
            vector<pii> p;
            For (j, int(perm.size()) - 1) {
                p.push_back({perm[j].second, perm[j + 1].second});
            }

            best = min(best, check_edges(p));

        } while (next_permutation(perm.begin(), perm.end()));
    }

    if (best >= INF) {
        cout << "-1\n";
    } else {
        cout << best << "\n";
    }
}

const int N = 10 * 1000 * 1000;

vector<pair<int, ll>> G[N];

vector<int> proper;
bool vis[N];

void dfs(int x) {
    if (vis[x]) return;

    proper.push_back(x);
    vis[x] = true;

    for (auto e : G[x]) {
        dfs(e.first);
    }
}

void solve_m() {

    dfs(1);

    if (!vis[n]) {
        cout << "-1\n";
        return;
    }

    ll best = INF;

    int nn = proper.size();

    For (i, (1<<nn)) {
        vector<pii> perm;
        For (j, nn) {
            if (i & (1 << j)) perm.push_back({1 + perm.size(), proper[j]});
        }

        if ((int)perm.size() != k + 1) continue;
        if (perm.front().second != 1 || perm.back().second != n) continue;

        do {
            vector<pii> p;
            For (j, int(perm.size()) - 1) {
                p.push_back({perm[j].second, perm[j + 1].second});
            }

            best = min(best, check_edges(p));

        } while (next_permutation(perm.begin(), perm.end()));
    }

    if (best >= INF) {
        cout << "-1\n";
    } else {
        cout << best << "\n";
    }
}

vector<pair<ll, pii>> best_edge_f[N];
vector<pair<ll, pii>> best_edge_s[N];

bool k_mode;

void add_edge(int x, int y, ll c) {
    if (k_mode == false) {
        edges[hash_edge(x, y)] = c;
    } else {
        edges_v.push_back({{y, x}, c});
        edges_v.push_back({{x, y}, c});
    }

    //error(x, y);

    G[x].push_back({y, c});
    G[y].push_back({x, c});
}

ll dist_to_f[N];
ll dist_to_s[N];

void do_best_edges(ll dist_to[], vector<pair<ll, pii>> best_edge[], int s) {
    For (i, n + 5) dist_to[i] = INF;

    for (auto e : G[s]) {
        int x = e.first;
        dist_to[x] = min(dist_to[x], e.second);
    }

    for (auto ec : edges_v) {
        auto e = ec.first;
        int c = ec.second;

        if (dist_to[e.first] == INF) continue;

        best_edge[e.second].push_back({c + dist_to[e.first], e});

        if (best_edge[e.second].size() > 8) {
            SORT(best_edge[e.second]);
            best_edge[e.second].pop_back();
        }
    }

    For (i, n + 3) {
        SORT(best_edge[i]);
    }
}

void solve_k() {
    int f = n;
    k_mode = true;

    if (k != 5) {

        vector<pii> to_add;

        for (auto e : G[1]) {
          to_add.push_back({1, n + 1});
          n++;
          m++;

          For (i, 4 - k) {
              add_edge(n, n + 1, 0);
              m++;
              n++;
          }

          add_edge(n, e.first, e.second);
          m++;
          n++;
        }

        for (auto e : to_add) {
          add_edge(e.first, e.second, 0);
        }

    }

    do_best_edges(dist_to_s, best_edge_s, 1);
    do_best_edges(dist_to_f, best_edge_f, f);

    ll best = INF;

    for (auto ec : edges_v) {
        auto e = ec.first;
        ll c = ec.second;

        ll ly = e.first;
        ll ry = e.second;

        For (i, 8) {
            if ((int)best_edge_s[ly].size() < i + 1) break;
            auto lx_e = best_edge_s[ly][i];
            int lx = lx_e.second.first;
            ll l_c = lx_e.first;

            For (j, 8) {
                if ((int)best_edge_f[ry].size() < j + 1) break;

                auto rx_e = best_edge_f[ry][j];

                int rx = rx_e.second.first;
                ll r_c = rx_e.first;

                if (rx == lx) continue;
                if (lx == ry) continue;
                if (ly == rx) continue;
                if (lx == 1 || ly == 1 || lx == f || ly == f 
                    || rx == 1 || ry == 1 || rx == f || ry == f) continue;

                best = min(best, l_c + r_c + c);
            }
        }
    }

    if (best >= INF) {
        cout << "-1\n";
    } else {
        cout << best << "\n";
    }
}


int main() {
	ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> k;

    if (!(n <= 5 || m <= 5)) k_mode = true;

    For (i, m) {
        int x, y;
        ll c;

        cin >> x >> y >> c;
        add_edge(x, y, c);
    }

    if (n <= 5) solve_n();
    else if (m <= 5) solve_m();
    else solve_k();

    return 0;
}