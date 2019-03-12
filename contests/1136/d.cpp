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

const int N = 3 * 100 * 1000 + 10;
int najdalej[N];
int order_of[N];
int at_pos[N];

vector<int> blizej[N];
vector<int> dalej[N];
int zaliczone[N];

int main() {
    _upgrade;

	int n, m;
	read(n, m);

	For (i, n) {
		int x;
		read(x);
		order_of[x] = i + 1;
		at_pos[i + 1] = x;
	}

	For (i, m) {
		int q, p;
		read(q, p);

		if (order_of[p] > order_of[q]) {
			blizej[p].push_back(q);
		} else {
			dalej[p].push_back(q);
		}
	}

	For (i, n) najdalej[i + 1] = order_of[i + 1];

	for (int i = 2; i <= n; i++) {
		vector<pii> jak_daleko;
		int w = at_pos[i];
		for (int bliski : blizej[w]) {
			jak_daleko.push_back({najdalej[bliski], bliski});
		}

		SORT(jak_daleko);
		jak_daleko.push_back({i, w});

		int cnt = 1;
		for (int j = int(jak_daleko.size()) - 2, k = 1; j >= 0; j--, k++) {
			// error(j, jak_daleko[j], w, order_of[w], k);
			if (jak_daleko[j].first >= order_of[w] - k) cnt++;
			else break;
		}

		For (j, cnt) {
			int ile = int(jak_daleko.size());
			int y = jak_daleko[ile - j - 1].second;
			najdalej[y] = min(najdalej[y] + 1, najdalej[w]);
		}
		zaliczone[w] = cnt - 1;
	}

	// For (i, n) error(i+1, najdalej[i+1]);
	// For (i, n) error(i+1, zaliczone[i+1]);

	writeln(zaliczone[at_pos[n]]);
}

