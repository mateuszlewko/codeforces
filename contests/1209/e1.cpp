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

int A[4][110];
vector<int> V[110];
int cnt[110];

int main() {
	_upgrade;

	int t;
	cin >> t;
	
	while (t--) {
		int n, m;
		cin >> n >> m;

		vector<pair<int, pii>> vs;
		For (i, 4) For (j, m) A[i][j] = 0;
		For (j, m) V[j].clear();

		For (i, n) {
			For (j, m) {
				cin >> A[i][j];
				V[j].push_back(A[i][j]);
			}
		}

		For (i, n - 4) {
			For (j, m) {
				V[j].push_back(0);
			}
		}

		For (i, m) {
			sort(V[i].begin(), V[i].end(), greater<>());
		}

		For (i, m) {
			For (j, n) vs.push_back({V[i][j], {i, j}});
		}
		sort(vs.begin(), vs.end(), greater<>());

		int best = 0;

		For (i, m) {
			For (j, m) {
				For (k, m) {
					int res = 0;
					cnt[i] = cnt[j] = cnt[k] = 0;
					res += V[i][cnt[i]++];
					if (n >= 2) res += V[j][cnt[j]++];
					if (n >= 3) res += V[k][cnt[k]++];
					
					if (n == 4) {
						For (l, 4) {
							int col = vs[l].second.first;
							int row = vs[l].second.second;

							if (col == i || col == j || col == k) {
								if (cnt[col] > row) continue;
								// if (res + vs[l].first > best) {
								// 	error(i, j, k, res, col, cnt[col], row, vs[l].first);
								// }
								res += vs[l].first;
								break;
							} else {
								res += vs[l].first;
								// if (res + vs[l].first > best) {
								// 	error(i, j, k, res, col, cnt[col], row, vs[l].first);
								// }
								break;
							}
						}
					}

					best = max(best, res);
 				}
			}
		}

		cout << best << "\n";
	}
}

