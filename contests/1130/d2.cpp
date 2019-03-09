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

const int N = 5005;
deque<int> dest[N];
ll ans[N];

int dist(int n, int from, int to) {
	return to >= from ? to - from : n - from + to;
}

void go(int mx, int n) {
	int end_at[N] = {0}; 

	For (i, n) {
		if (int(dest[i].size()) < mx - 1 || (int)dest[i].size() == 0) continue;

		int ix = 0;
		while (ix < (int)dest[i].size() && dest[i][ix] < i) ix++;
		int go_pos = ix >= (int)dest[i].size() ? dest[i][0] : dest[i][ix];

		// error(i, go_pos);

		For (j, n) {
			end_at[j] = max(end_at[j], dist(n, j, i) + dist(n, i, go_pos) + 
			                           ((int)dest[i].size() == mx - 1 ? -n : 0));
			// int i_j = dist(n,j,i);
			// int i_go_pos = dist(n,i,go_pos);
			// error(i, j, i_j, i_go_pos);

			// end_at[j] = max(end_at[j], go_pos > j ? go_pos - j : n - j + go_pos);
		}
	}

	For (i, n) {
		ans[i] = (ll)(mx - 1) * (ll)n + end_at[i];
	}
}

int main() {
    _upgrade;

	int n, m;
	read(n, m);

	For (i, m) {
		int a, b;
		read(a, b);
		a--;
		b--;
		dest[a].push_back(b);
	}

	For (i, n) SORT(dest[i]);
	int mx = 0;
	For (i, n) mx = max(mx, (int)dest[i].size());

	go(mx, n);
	For (i, n) write(ans[i]);

	// for (int i = 1; i <= n; i++) {
	// 	write(min(ans(i, n, m, true), ans(i, n, m, false)));
	// }
}

