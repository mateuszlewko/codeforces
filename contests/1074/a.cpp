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

const int N = 100 * 1000;
int h[N];
const int inf = 1000 * 1000 * 1000;

int main() {
    _upgrade;
	int n, m;
	cin >> n >> m;

	vector<int> v;

	For (i, n) cin >> h[i];
	For (i, m) {
		int a, b, y;
		cin >> a >> b >> y;
		if (a == 1) v.push_back(b);
	}	

	SORT(v);
	sort(h, h + n);

	int res = v.end() - lower_bound(v.begin(), v.end(), n > 0 ? h[0] : inf);

	For (i, n) {
		int from_left = i < n - 1 ? h[i + 1] : inf;
		int cnt = v.end() - lower_bound(v.begin(), v.end(), from_left);
		res = min(res, i + 1 + cnt);
	}

	cout << res << "\n";
}

