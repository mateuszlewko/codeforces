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

const int N = 3 * 100 * 1000 + 10;
vector<int> G[N];
ll sum[N];
vector<pair<int, ll>> qs[N];

set<pair<pair<int, ll>, int>> curr_q;

void dfs(int x, int p, int lvl, ll curr_sum) {
	error(x, p, lvl, curr_sum);

	ll orig_sum = curr_sum;

	int ind = 0;
	for (auto q : qs[x]) {
		curr_sum += q.second;
		curr_q.insert({{lvl + q.first, q.second}, ind});
		ind++;
	}

	error(curr_sum);

	vector<pair<pair<int, ll>, int>> removed;

	while (curr_q.size() && (curr_q.begin())->first.first < lvl) {
		auto b = *curr_q.begin();
		removed.push_back(b);
		curr_sum -= b.first.second;
		curr_q.erase(b);
	}

	error(curr_sum);
	// cout << endl;
	sum[x] = curr_sum;

	for (int y : G[x]) {
		if (y != p) {
			dfs(y, x, lvl + 1, curr_sum);
		}
	} 

	ind = 0;
	for (auto q : qs[x]) {
		curr_sum -= q.second;
		curr_q.erase({{lvl + q.first, q.second}, ind});
		ind++;
	}

	for (auto q : removed) {
		curr_sum += q.first.second;
		curr_q.insert(q);
	}

	assert(curr_sum == orig_sum);
}

int main() {
    _upgrade;

	int n;
	cin >> n;

	For (i, n - 1) {
		int a, b; 
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	int q;
	cin >> q;
	while(q--) {
		int v, d;
		ll x;
		cin >> v >> d >> x;
		qs[v].push_back({d, x});
	}

	dfs(1, -1, 0, 0);

	For (i, n) 
		cout << sum[i + 1] << " " << "\n";
}

