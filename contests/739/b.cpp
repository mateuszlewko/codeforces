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

const int N = 2 * 100 * 1000 + 10;
vector<pii> G[N];

int d[N];
ll ans[N];

ll rem_at[N];
vector<pll> sum;

ll go_sum(int x, ll dist) {
	int ix = 0;

	if (sum.size() > 0) {
		ix = (int)(lower_bound(sum.begin(), sum.end(), (pll){sum.back().first + dist - d[x], -1}) - sum.begin());
	}
		
	int add = 0;

	if (ix < sum.size()) {
		rem_at[sum[ix].second]++;
		add = 1;
	}

	sum.push_back({sum.size() ? sum.back().first + dist : dist, x});

	ll child_sum = 0;
	for (auto y : G[x]) {
		child_sum += go_sum(y.first, y.second);
	}

	ans[x] = child_sum;
	sum.pop_back();

	return child_sum + add - rem_at[x];
}

int main() {
    _upgrade;

	int n;
	cin >> n;

	For (i, n) {
		cin >> d[i + 1];
	}

	For (i, n - 1) {
		int p, dist;
		cin >> p >> dist;
		G[p].push_back({i + 2, dist});
	}

	go_sum(1, 0);
	For (i, n) {
		cout << ans[i + 1] << " ";
	}
}

