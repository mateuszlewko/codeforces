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

const ll _MAX = 1000LL * 1000LL * 1000LL;
const ll MAX = _MAX * _MAX;

int main() {
    _upgrade;

	int n;
	read(n);

	set<ll> not_like;
	int liked_cnt = 0;
	unordered_map<ll, int> num_cnt;

	For (i, n) {
		int op, cnt;
		read(op, cnt);

		unordered_set<ll> liked_to_keep;

		For (j, cnt) {
			ll x;
			read(x);

			if (op == 2) {
				not_like.insert(x);
			} else {
				liked_to_keep.insert(x);
			}
		}

		if (op == 1) {
			liked_cnt++;
			for (ll x : liked_to_keep) {
				num_cnt[x]++;
			}
		}
	}

	set<ll> liked;
	for (auto it : num_cnt) {
		if (it.second == liked_cnt) {
			liked.insert(it.first);
		}
	}

	if (liked_cnt == 0) {
		writeln(MAX - not_like.size());
	} else {
		for (ll x : not_like) {
			liked.erase(x);
		}

		writeln(liked.size());
	}
}

