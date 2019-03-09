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
int cnt[N];

vector<int> start[N];
vector<int> finish[N];

int my_len[N];

int pair_len[N][N];

int main() {
    _upgrade;

	int n, q;
	read(n, q);

	For (i, q) {
		int l, r;
		read(l, r);
		start[l].push_back(i);
		finish[r].push_back(i);
	}

	unordered_set<int> present;

	int total = 0;

	for (int i = 1; i <= n; i++) {
		for (int x : start[i]) {
			present.insert(x);
		}

		cnt[i] = (int)present.size();

		if (cnt[i] > 0) total++;
		if (cnt[i] == 1) {
			my_len[*present.begin()]++;
		} else if(cnt[i] == 2) {
			auto it = present.begin();
			int x = *it;
			it++;
			int y = *it;

			pair_len[x][y]++;
			pair_len[y][x]++;
		}

		for (int x : finish[i]) present.erase(x);
	}

	int best = 0;
	For (i, q) {
		for (int j = i + 1; j < q; j++) {
			// error(i, my_len[i], j, my_len[j], pair_len[i][j]);
			best = max(best, total - my_len[i] - my_len[j] - pair_len[i][j]);
		}
	}

	writeln(best);
}

