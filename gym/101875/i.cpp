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

const int N = 200 * 1000 + 10;
pii vec_range[N];

vector<int> G[N];

int curr_time = 1;

void go(int x) {
	if (vec_range[x].first != 0) return;

	vec_range[x].first = curr_time;
	curr_time++;

	for (int y : G[x]) {
		go(y);
	}

	vec_range[x].second = curr_time;
	curr_time++;
}

bool parent[N];

int main() {
    // _upgrade;

	int n, q;
	// read(n, q);
	scanf("%d %d", &n, &q);

	For (i, n) {
		int p;
		scanf("%d", &p);
		if (p == -1) {
			parent[i] = true;
		} else {
			// read(p);
			G[p].push_back(i);
		}
	}

	For (i, n) {
		if (parent[i]) {
			go(i);
		}
	}

	For (i, q) {
		int x, y;
		scanf("%d %d", &x, &y);
		// read(x, y);

		if (vec_range[x].first >= vec_range[y].first && 
		    vec_range[x].second <= vec_range[y].second) {
			// writeln("Yes");
			puts("Yes");
		} else {
			// writeln("No");
			puts("No");
		}
	}

	return 0;
}

