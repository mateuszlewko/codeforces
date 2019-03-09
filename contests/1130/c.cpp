#pragma region Template 
#include <bits/stdc++.h> 

using namespace std;

#define For(i, n) for (int i = 0; i < (n); i++)
#define ForD(i, n) for (int i = (n) - 1; i >= 0; i--)
#define SORT(x) sort(begin(x), end(x))
#define REP(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
template<typename... Args>
void read(Args&... args)
{
    ((cin >> args), ...);
}

template<typename... Args>
void write(Args... args)
{
    ((cout << args << " "), ...);
}

template<typename... Args>
void writeln(Args... args)
{
    ((cout << args << " "), ...);
	cout << "\n";
}

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

const int N = 55;
int col[N][N];
int land[N][N];
int n;

void go(int x, int y, int c) {
	if (x < 1 || y < 1 || x > n || y > n) return;
	if (land[x][y] == 0) return;
	if (col[x][y] != 0) return;

	col[x][y] = c;

	int dx[] = {-1, 1, 0, 0};
	int dy[] = {0, 0, -1, 1};

	For (i, 4) {
		go(x + dx[i], y + dy[i], c);
	}
}

int main() {
    _upgrade;

	read(n);

	int r1, c1, r2, c2;
	read(r1, c1, r2, c2);

	For (i, n) {
		For (j, n) {
			char c;
			cin >> c;
			land[i+1][j+1] = (c == '1' ? 0 : 1);
		}
	}

	// For (i, n) {
	// 	For (j, n) {
	// 		cout << land[i+1][j+1] << " ";
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;

	go(r1, c1, 1);
	if (col[r2][c2] == 1) {
		cout << "0\n";
		return 0;
	}

	vector<pll> col1;
	For (i, n) {
		For (j, n) {
			if (col[i+1][j+1] == 1) {
				col1.push_back({i+1, j+1});
			}
		}
	}

	ll res = 1LL << 60;

	go(r2, c2, 2);

	// For (i, n) {
	// 	For (j, n) {
	// 		cout << col[i+1][j+1] << " ";
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;

	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= n; j++) {
			if (col[i][j] != 2) continue;
			for (auto [x, y] : col1) {
				ll dist = (x - i) * (x - i) + (y - j) * (y - j);
				res = min(res, dist);
			}
		}
	}

	assert(res < ( 1LL << 60));

	writeln(res);
}

