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
typedef pair<ld, ld> pdd;

ld dist(pdd p1, pdd p2) {
	ld x = p1.first - p2.first;
	ld y = p1.second - p2.second;
	
	ld rd = sqrt(x * x + y * y);
	// error(x, y, rd);
	return rd;
}

ld eval_dist(pdd p1, pdd p2, pdd p3) {
	return dist(p1, p2) + dist(p2, p3) + dist(p3, p1);
}

ld find_smallest(pdd p1, pdd p2, ld p3_x, ld p3_max_y) {
	ld beg = 0;
	ld end = p3_max_y;

	For (i, 50) {
	 	long double m1 = (beg * 2 + end) / 3.0;
    long double m2 = (beg + 2 * end) / 3.0;
		
		ld m1_e = eval_dist(p1, p2, {p3_x, m1});
		ld m2_e = eval_dist(p1, p2, {p3_x, m2});

		if (m2_e > m1_e) end = m2;
		else beg = m1;
	}

	return eval_dist(p1, p2, {p3_x, (beg + end) * 0.5});
}

int main() {
	// _upgrade;
	int t;
	scanf("%d", &t);

	while (t--) {
		ld a, b, c, x;
		scanf("%Lf %Lf %Lf %Lf", &a, &b, &c, &x);
		x /= 100.0;
		
		ld res = 0;
		// error(a, b, c, x);

		res += find_smallest({b, 0}, {0, a}, b + c, a) - sqrt(b * b + a * a);
		// error(res);

		ld left_a = a - a * x;
		pdd p4 = {b * x, left_a};
		
		ld grand_home = sqrt(b * b + a * a);
		res += x * grand_home;

		res += find_smallest({b, 0}, p4, b + c, left_a) - (1 - x) * grand_home;


		printf("%.9Lf\n", res);
	}
}

