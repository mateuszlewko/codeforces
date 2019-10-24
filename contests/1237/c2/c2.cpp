#include <bits/stdc++.h> 

using namespace std;

#define For(i, n) for (int i = 0; i < int(n); i++)
#define ForD(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define SORT(x) sort(begin(x), end(x))
#define REP(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

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

typedef array<int, 4> point;

bool inside(point &a, point &b, point &c) {
	For (i, 3) {
		if (min(a[i], b[i]) > c[i] || max(a[i], b[i]) < c[i]) return false;
	}

	return true;
}

bool grt(point &a, point &b, point &c) {
	For (i, 3) {
		if (max(abs(a[i]), abs(b[i])) > abs(c[i])) return false;
	}

	return true;
}

const int N = 50005;
point ps[N];

bool done[N];

int main() {
	_upgrade;

	int n;
	cin >> n;

	set<int> avail;

	For (i, n) {
		For (j, 3) cin >> ps[i + 1][j];
		ps[i + 1][3] = i + 1;
		avail.insert(i + 1);
	}

	sort(ps + 1, ps + n + 1 , [](point l, point r) {
		pair<pii, pii> lp = { {abs(l[0]), abs(l[1])} , {abs(l[2]), l[3]} };
		pair<pii, pii> rp = { {abs(r[0]), abs(r[1])} , {abs(r[2]), r[3]} };
 
		return lp < rp;
	});

	for (int i = 1; i <= n; i++) {
		if (done[i]) continue;
		avail.erase(i);

		auto y = *avail.begin();

		auto ind = next(avail.begin());
		while (ind != avail.end()) {
			if (inside(ps[i], ps[y], ps[*ind])) y = *ind;
			else if (grt(ps[i], ps[y], ps[*ind])) {
				break;
			}

			ind++;
		}

		cout << ps[i][3] << " " << ps[y][3] << "\n";
		done[i] = done[y] = true;
		avail.erase(y);	
	}
}

