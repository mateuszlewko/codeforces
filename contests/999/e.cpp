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

const int N = 5005;
vector<int> graph[N];

int vis[N];

void dfs(int x) {
	if (vis[x]) return;
	vis[x] = 2; 

	for (int y : graph[x])
		dfs(y);
}

vector<int> set_vis;

bool is_on_cycle(int x) {
	if (vis[x] == 1)
		return true;
	if (vis[x] == 2)
		return false;

	vis[x] = 1;
	set_vis.push_back(x);

	bool any = false;
	for (int y : graph[x]) {
		any |= is_on_cycle(y);
	}

	vis[x] = 2;
	return any;
}

int degree[N];

int main() {
    // _upgrade;
	int n, m, s;
	scanf("%d %d %d", &n, &m, &s);

	For (i, m) {
		int a, b; 
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		degree[b]++;
	}

	dfs(s);

	int res = 0; 
	REP (i, 1, n + 1) {
		if (!vis[i] && degree[i] == 0) {
			res++;
			dfs(i);
		}
	}	

	vector<pair<int, int>> vs; 

	REP (i, 1, n + 1) {
		if (!vis[i]) {
			if (is_on_cycle(i)) {
				vs.push_back({set_vis.size(), i});
			}

			for (auto x : set_vis)
				vis[x] = 0;

			set_vis.clear();
		}
	}

	sort(begin(vs), end(vs));
	reverse(vs.begin(), vs.end());

	for (auto x : vs) {
		if (!vis[x.second]) {
			dfs(x.second);
			res++;
		}
	}

	printf("%d\n", res);
}

