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

const int N = 110;
deque<int> dest[N];

int ans(int start, int n, int m, bool from_high) {
	int ans = 0;
	deque<int> my_dest[N];
	For (i, n + 1) my_dest[i] = dest[i];

	int carry[N] = {0};

	int pos = start;
	while (m) {
		if (my_dest[pos].size()) {
			int d = 0;
			if (from_high) {
				d = my_dest[pos].back();
				my_dest[pos].pop_back();
			} else {
				d = my_dest[pos].front();
				my_dest[pos].pop_front();
			}
			// error(start, pos, d);
			carry[d]++;
		}

		// error(pos);
		m -= carry[pos];
		carry[pos] = 0;
 
		pos++;
		if (pos > n) pos = 1;
		if (m > 0) ans++;
	}

	return ans;
}

int main() {
    _upgrade;

	int n, m;
	read(n, m);

	For (i, m) {
		int a, b;
		read(a, b);
		dest[a].push_back(b);
	}

	For (i, n) SORT(dest[i+1]);

	for (int i = 1; i <= n; i++) {
		write(min(ans(i, n, m, true), ans(i, n, m, false)));
	}
}

