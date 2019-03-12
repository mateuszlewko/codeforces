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

template <class T, class U> ostream &operator<<(ostream &os, const pair<T, U> &p) {
	os << p.first << " " << p.second;
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

const int N = 1010;
int succ[N];

vector<int> st;
int vis[N];
int col[N];
int col_cnt_large[N];
int col_cnt[N];

int dfs(int x, int c) {
	vis[x] = 1;
	int s = succ[x];

	if (s == x) {
		col_cnt[c]++;
		col[x] = c;
		vis[x] = 2;
		return c;
	}

	st.push_back(x);

	if (vis[s] == 1) {
		int cnt = 1;
		while (st.back() != s) {
			st.pop_back();
			cnt++;
		}

		col_cnt_large[c] = cnt;
		col[x] = c;
		col_cnt[c]++;
		vis[x] = 2;

		return c;
	} 

	// error(x, s, vis[s]);
	int cc = col[x] = (vis[s] == 0 ? dfs(s, c) : col[s]);
	col_cnt[cc]++;
	
	vis[x] = 2;

	// error(x, st);
	// st.pop_back();

	return cc;
}

bool dp[2][N];

int main() {
    _upgrade;

	int n, k;
	read(n, k);

	For (i, n) read(succ[i + 1]);

	int col_ind = 0;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			// error(i);
			int c = dfs(i, col_ind);
			// error(i, c);
			if (c == col_ind) col_ind++;
		}
	}

	vector<pii> vs;
	For (i, col_ind) {
		vs.push_back({col_cnt_large[i], col_cnt[i]});
	}

	// error(vs);

	dp[0][0] = true;
	int ind = 0;

	for (auto [from, to] : vs) {
		for (int i = from; i <= to; i++) {
			for (int j = k; j >= 0; j--) {
				if (!dp[ind % 2][j]) continue;
				dp[(ind + 1) % 2][j] = true;

				if (i + j <= k) dp[(ind + 1) % 2][j + i] = true;
			}
		}

		// For (i, k + 1) {
		// 	cout << dp[(ind + 1) % 2][i] << " ";
		// }

		// cout << endl;
		ind++;
	}

	int ans = 0;
	For (i, k + 1) {
		if (dp[ind % 2][i]) ans = i;
	}

	writeln(ans);
}

