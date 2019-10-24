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

typedef bitset<64> row;

vector<ll> from[64]; 

row get_row(ll x) {
	row r;
	int i = 0;
	while (x) {
		if (x & 1) {
			r[i] = 1;
		}

		i++;
		x >>= 1;
	}

	return r;
}

const int INF = 1<<30;

const int N = 100 * 1000 + 10;
ll A[N];

int cycle(int x) {
	unordered_set<ll> vis;
	unordered_map<ll, int> dist;
	queue<int> q;

	q.push(x);
	dist[x] = 0;
	vis.insert(x);
	// cout << "start: " << x << endl;

	while (q.size()) {
		int u = q.front();
		// cout << "u: " << u << endl;
		q.pop();

		vector<ll> nx;
		int udist = dist[u];

		For (i, 64) {
			if (!(A[u] & (1LL << i))) continue;
			for (int v : from[i]) {
				if (v == u) continue;

				if (vis.count(v)) {
					int vdist = dist[v];
					if (vdist + 1 == udist) continue;
					error(u, v, udist);
					return udist + vdist + 1;
				}

				// cout << "vis: " << v << " d: " << udist + 1 << endl;
				nx.push_back(v);
			}
		}
		
		for (ll v : nx) {
			vis.insert(v);
			q.push(v);
			dist[v] = udist + 1;
		}
	}

	return INF;
}

bool vis2[100][100];

int main() {
	_upgrade;

	int n;
	cin >> n;
	set<ll> vs;

	For (i, n) {
		ll x;
		cin >> x;
		A[i] = x;

		// for (auto [i, j] : x) {
		// 	if ()
		// }

		For (j, 64) {
			for (int k = j; k < 64; k++) {
				if ((x & (1LL << j)) && (x & (1LL << k)) && !vis2[j][k]) {
					vis2[j][k] = true;
					vs.insert(i);
					// error(i);
				}
			}
		}

		For (j, 64) {
			if (x & (1LL << j)) {
				from[j].push_back(i);
			}
		}
	}

	int best = INF;
	for (auto x : vs) {
		best = min(best, cycle(x));
	}

	if (best >= INF) cout << "-1";
	else cout << best << "\n";
}

