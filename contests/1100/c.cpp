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

#pragma endregion 

constexpr double const_pi() { return std::atan(1)*4; }

#define PI           3.14159265358979323846 

int main() {
    // _upgrade;

	ld n, r;
	// cin >> n > r;
	scanf("%Lf %Lf", &n, &r);
	ld x = ((n - 2.0) / (2.0 * n)) * PI;

	// printf("%.9Lf\n", (const_pi()));

	error(x, cos(x));

	ld ans = cos(x) / (1.0 - cos(x));
	printf("%.9Lf\n", ans * r);
}

