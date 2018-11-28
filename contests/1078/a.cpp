#pragma region Template 
#include <bits/stdc++.h> 

using namespace std;

#define For(i, n) for (int i = 0; i < (n); i++)
#define ForD(i, n) for (int i = (n) - 1; i >= 0; i--)
#define SORT(x) sort(begin(x), end(x))
#define REP(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

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

#define _upgrade do { ios::sync_with_stdio(0); cin.tie(0); } while (0)

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

typedef pair<ld, ld> pdd;

#pragma endregion 

ld get_x_cross(ld y, ld a, ld b, ld c) {
	if (abs(a) < 0.00000001) return 1e11;
	return (-c - b * y) / a;
}

ld get_y_cross(ld x, ld a, ld b, ld c) {
	if (abs(b) < 0.00000001) return 1e11;
	return (-c - a * x) / b;
}

ld get_man(ld x, ld y, ld p, ld q) {
	return abs(p - x) + abs(q - y);
}

ld dist(ld x, ld y, ld p, ld q) {
	return sqrt((q - y) * (q - y) + (p - x) * (p - x));
}

int main() {
    // _upgrade;
	ld a, b, c;
	cin >> a >> b >> c;

	pdd p1, p2;
	cin >> p1.first >> p1.second >> p2.first >> p2.second;

	ld best = get_man(p1.first, p1.second, p2.first, p2.second);

	ld yc = get_y_cross(p1.first, a, b, c);
	ld yc2 = get_y_cross(p2.first, a, b, c);
	ld xc = get_x_cross(p1.second, a, b, c);
	ld xc2 = get_x_cross(p2.second, a, b, c);
	best = min(best, abs(yc - p1.second) + abs(yc2 - p2.second) + dist(p1.first, yc, p2.first, yc2));
	best = min(best, abs(yc - p1.second) + abs(xc2 - p2.first)  + dist(p1.first, yc, xc2, p2.second));
	best = min(best, abs(xc - p1.first)  + abs(xc2 - p2.first)  + dist(xc, p1.second, xc2, p2.second));
	best = min(best, abs(xc - p1.first)  + abs(yc2 - p2.second) + dist(xc, p1.second, p2.first, yc2));

	printf("%.10Lf\n", best);
}