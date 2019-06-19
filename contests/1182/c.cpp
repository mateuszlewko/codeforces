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

int map_vowel(char c) {
	if (c == 'a') return 1;
	if (c == 'e') return 2;
	if (c == 'o') return 3;
	if (c == 'i') return 4;
	if (c == 'u') return 5;

	return 0;
}

pii group_word(const string &s) {
	int res_v = 0;
	int v_cnt = 0;

	ForD (i, s.size()) {
		int v = map_vowel(s[i]);
		if (v) {
			if (res_v == 0) res_v = v;
			v_cnt++;
		}
	}

	assert(res_v != 0);
	return {res_v, v_cnt};
}

const int N = 1000 * 1000 + 10;
vector<string> groups[8][N];
int A[8][N];

void print_w(pii p) {
	int x = p.first;
	int y = p.second;

	cout << groups[x][y].back() << " ";
	groups[x][y].pop_back();
}

int main() {
	_upgrade;

	int n;
	cin >> n;

	For (i, n) {
		string s;
		cin >> s;
		
		auto g = group_word(s);
		groups[g.first][g.second].push_back(s);
		A[g.first][g.second]++;
	}

	vector<pii> odd;

	For (i, 6) {
		For (j, n) {
			if (A[i][j] % 2 != 0) {
				A[i][j]--;
				odd.push_back({i, j});
			}
		}
	}

	sort(odd.begin(), odd.end(), [](pii l, pii r) { return l.second < r.second; });

	vector<vector<pii>> ans;

	For (i, 6) {
		For (j, n) {
			while (A[i][j] > 0) {
				vector<pii> aa;

				while (odd.size() >= 2 && odd.back().second != odd[int(odd.size()) - 2].second) {
					odd.pop_back();
				}

				if (odd.size() < 2) {
					if (A[i][j] >= 4) {
						For (k, 4) aa.push_back({i, j});
						A[i][j] -= 4;
					} else {
						For (k, A[i][j]) {
							odd.push_back({i, j});
						}

						A[i][j] = 0;
						continue;
					}
				} else {
					For (k, 2) {
						aa.push_back(odd.back());
						odd.pop_back();
					}
					For (k, 2) aa.push_back({i, j});
					A[i][j] -= 2;
				}

				ans.push_back(aa);
			}
		}
	}

	cout << ans.size() << "\n";
	for (auto aa : ans) {
		// cout << aa[0] << ", " << aa[1] << " | " << aa[2] << ", " << aa[3] << endl;

		print_w(aa[0]);
		print_w(aa[2]);
		cout << "\n";
		print_w(aa[1]);
		print_w(aa[3]);
		cout << "\n";
	}
}

