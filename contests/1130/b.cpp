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

const int N = 2 * 100 * 1000 + 10;
int cnt[N];
int pos[N][2];
ll dp[N][2];

int main() {
    _upgrade;

	int n;
	read(n);

	For (i, 2 * n) {
		int x;
		read(x);
		pos[x][cnt[x]++] = i;
	}

	for (int i = 1; i <= n; i++) {
		ll from0_to0 = abs(pos[i][0] - pos[i - 1][0]) + abs(pos[i][1] - pos[i - 1][1]) + dp[i - 1][0];
		ll from1_to0 = abs(pos[i][0] - pos[i - 1][1]) + abs(pos[i][1] - pos[i - 1][0]) + dp[i - 1][1];
		dp[i][0] = min(from0_to0, from1_to0);

		ll from0_to1 = abs(pos[i][1] - pos[i - 1][0]) + abs(pos[i][0] - pos[i - 1][1]) + dp[i - 1][0];
		ll from1_to1 = abs(pos[i][1] - pos[i - 1][1]) + abs(pos[i][0] - pos[i - 1][0]) + dp[i - 1][1];
		dp[i][1] = min(from0_to1, from1_to1);
	}

	writeln(min(dp[n][0], dp[n][1]));
}

