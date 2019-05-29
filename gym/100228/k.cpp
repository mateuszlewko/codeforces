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

const int N = 8;

int get_type(char c) {
	if (c >= 'A' && c <= 'Z') return 1;
	return 0;	
}

char board[N][N];
bool attacked[N][N];

vector<map<char, vector<pii>>> fill_board(const string &s) {
	int i = 0;
	int j = 0;

	For (t, 2) For (k, N) For (l, N) board[k][l] = 0;

	vector<map<char, vector<pii>>> maps(2);

	for (char c : s) {
		if (c == '/') {
			i++;
			j = 0;
		}
		else if (c >= '0' && c <= '9') j += (c - '0');
		else {
			int t = get_type(c);
			board[i][j] = c;
			maps[t][tolower(c)].push_back({i, j});
			j++;
		}
	}

	return maps;
}

bool in_range(int x, int y) {
	return x >= 0 && y >= 0 && x < N && y < N;
}

void go(bool vis[][N], char c, int t, int x, int y) {

	if (c == 'k') {
		int d[] = {-1, 0, 1};
		For (i, 3) For (j, 3) {
			int nx = x + d[i];
			int ny = y + d[j];

			if (in_range(nx, ny)) vis[nx][ny] = true;
		}
	} else if (c == 'q') {
		int d[] = {0, -1, 1};

		For (i, 3) {
			For (j, 3) {
				For (k, N) {
					int nx = x + d[i] * k;
					int ny = y + d[j] * k;

					if (!in_range(nx, ny)) break;
					vis[nx][ny] = true;

					if ((k > 0) && (board[nx][ny] || board[nx][ny])) break;
				}
			}
		}
	} else if (c == 'r') {
		int dx[] = {0, 1, -1, 0};
		int dy[] = {1, 0, 0, -1};

		For (i, 4) {
			For (k, N) {
				int nx = x + dx[i] * k;
				int ny = y + dy[i] * k;

				if (!in_range(nx, ny)) break;
				vis[nx][ny] = true;

				if ((k > 0) && (board[nx][ny] || board[nx][ny])) break;
			}	
		}
	} else if (c == 'b') {
		int d[] = {-1, 1};

		For (i, 2) {
			For (j, 2) {
				For (k, N) {
					int nx = x + d[i] * k;
					int ny = y + d[j] * k;

					if (!in_range(nx, ny)) break;
					vis[nx][ny] = true;

					if ((k > 0) && (board[nx][ny] || board[nx][ny])) break;
				}
			}
		}
	} else if (c == 'p') {
		int mult = 1;

		if (t == 1) mult = -1;

		if (in_range(x + mult, y - 1)) vis[x + mult][y - 1] = true;
		if (in_range(x + mult, y + 1)) vis[x + mult][y + 1] = true;
	} else if (c == 'n') {

		int dx[] = {2, 1, -1, -1, -2, -2,  1,  2};
		int dy[] = {1, 2,  2, -2,  1, -1, -2, -1};

		For (i, 8) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (!in_range(nx, ny)) continue;
			vis[nx][ny] = true;
		}
	}
}

int tc = 1;

void solve(const string &s) {
	auto maps = fill_board(s);	

	For (i, N) For (j, N) attacked[i][j] = false;
	
	For (t, 2) {
		for (auto c_pos : maps[t]) {
			char c = c_pos.first;
			auto pos = c_pos.second;

			// error(t, c, pos);

			for (auto p : pos) {
				go(attacked, tolower(c), t, p.first, p.second);
			}

			// For (i, N) {
			// 	For (j, N) {
			// 		cout << attacked[(t + 1) % 2][i][j] << " ";
			// 	}
			// 	cout << endl;
			// }
		}
	}

	int cnt = 0;
	// For (t, 2) {
		For (i, N) {
			For (j, N) {
				char c = board[i][j];
				// if (c == 0) cout << ".";
				// else cout << c;

				// cout << "|" << attacked[i][j] << " ";

				if (!attacked[i][j] && board[i][j] == 0) cnt++;
			}
			// cout << endl;
		}

		// cout << endl;
		// cout << endl;
	// }

	// For (t, 2) {
		// For (i, N) {
		// 	For (j, N) {
		// 		cout << attacked[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }

	// 	cout << endl;
	// 	cout << endl;
	// }

	cout << cnt << "\n";
	// if (tc == 23 && cnt == 10) {
	// 	cout << "s: " << s << endl;
	// }
	// tc++;
}

int main() {
	_upgrade;

	string s;
	while (cin >> s) solve(s);
}

