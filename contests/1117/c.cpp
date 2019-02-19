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

#pragma endregion 

const int N = 100 * 1000 + 10;
pll A[N];
ll add[N];

ll sgn(ll x) {
	if (x == 0) return 0;
	else if (x < 0) return -1;
	return 1;
}

bool check(pll from, pll to, ll steps, int n) {
	ll full = steps / n;
	pll delta = {0, 0};
	pll all_delta = {0, 0};

	For (i, n) {
		if (i < steps % n) {
			delta.first += A[i].first;
			delta.second += A[i].second;
		}

		all_delta.first += A[i].first;
		all_delta.second += A[i].second;
	}

	pll pos = { all_delta.first * full + delta.first + from.first
	          , all_delta.second * full + delta.second + from.second };

	ll dist = abs(to.first - pos.first) + abs(to.second - pos.second);
	dist -= steps;

	return dist <= 0;
}

ll solve(pll from, pll to, int n) {
	ll beg = 0;
	ll end = 1e14;

	while (beg != end - 1) {
		ll mid = (beg + end) >> 1;

		if (check(from, to, mid, n)) end = mid;
		else beg = mid;
	}

	if (!check(from, to, end, n)) return -1;
	else return end;
}

int main() {
    _upgrade;

	pll from, to;
	cin >> from.first >> from.second >> to.first >> to.second;

	int n;
	cin >> n;
	
	string ss;
	cin >> ss;

	For (i, n) {
		if (ss[i] == 'U') {
			A[i] = {0, 1};
		} else if (ss[i] == 'D') {
			A[i] = {0, -1};
		} else if (ss[i] == 'L') {
			A[i] = {-1, 0};
		} else {
			A[i] = {1, 0};
		}
	}

	cout << solve(from, to, n);
}

