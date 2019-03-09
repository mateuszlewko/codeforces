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

const int N = 3 * 100 * 1000 + 10;
int col[N];
vector<int> G[N];

int ans;
pii sum_all;

pii go(int x, int p) {
	pii sum_me = {int(col[x] == 1), int(col[x] == 2)};

	for (int y : G[x]) {
		if (y == p) continue;
		sum_me += go(y, x);	
	}

	pii other = sum_all - sum_me;

	// error(x, p, sum_me.first, sum_me.second, other.first, other.second);
	// writeln("-----");

	if (!(sum_me.first > 0 && sum_me.second > 0) && 
	    !(other.first > 0 && other.second > 0)) {
		ans++;
	}

	return sum_me;
}

int main() {
    _upgrade;

	int n;
	read(n);

	For (i, n) {
		read(col[i + 1]);

		if (col[i + 1] == 1) sum_all.first++;
		else if (col[i + 1] == 2) sum_all.second++;
	}
	
	For (i, n - 1) {
		int a, b;
		read(a, b);
		G[a].push_back(b);
		G[b].push_back(a);
	}	

	go(1, -1);
	writeln(ans);

	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(4);

	writeln("v:", v);
}

