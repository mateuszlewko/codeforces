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


namespace uf {
	const int N = 2 * 100 * 1000 + 10;

	int sets[N];
	ll cnt[N];

	void init() {
		For (i, N) {
			sets[i] = i;
			cnt[i] = 1;
		}
	} 

	int find(int a)
	{
		if (sets[a] == a)
			return a;
		return sets[a] = find(sets[a]);
	}

	bool connect(int a, int b)
	{
		int fa = find(a);
		int fb = find(b);

		if (fa == fb)
			return false;

		if (cnt[fa] <= cnt[fb])
		{
			cnt[fb] += cnt[fa];
			sets[fa] = fb;
		}
		else
		{
			cnt[fa] += cnt[fb];
			sets[fb] = fa;
		}

		return true;
	}
}


bool vis[uf::N];
vector<int> G[uf::N];

void dfs(int x) {
	if (vis[x]) return;
	vis[x] = true;
	for (int y : G[x]) dfs(y);
}

int main() {
    _upgrade;

	int n, m, k;
	cin >> n >> m >> k;

	uf::init();

	For (i, k) {
		int x;
		cin >> x;
	}

	vector<pair<ll, pair<ll, ll>>> edges;
	For (i, m) {
		ll a, b, c;
		cin >> a >> b >> c;
		
		G[a].push_back(b);
		G[b].push_back(a);

		edges.push_back({c, {a, b}});
	}

	dfs(1);
	For (i, n) {
		if (!vis[i + 1]) {
			cout << "not connected\n";
			exit(11);
		}
	}

	SORT(edges);
	ll ans = 0;

	for (auto e : edges) {
		int x = e.second.first;
		int y = e.second.second;
		ll c = e.first;

		// error(x, y);

		if (uf::connect(x, y)) {
			ans = max(ans, c);
			// error(c);
		}
	}

	For (i, k) {
		cout << ans << " ";
	}
}


