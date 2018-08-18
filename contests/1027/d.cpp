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

const int INF = 1<<30;

const int N = 2 * 100 * 1000;
int cost[N];
int next_[N];

// int ans_for_color[N];
int node_ans[N];
bool vis[N];
int color[N];

int dfs_cycle(int x) {
	if (vis[x]) {
		return min(node_ans[x], cost[x]);
	}

	vis[x] = true;
	node_ans[x] = min(dfs_cycle(next_[x]), cost[x]);
	return node_ans[x];
}

int vis_cyc[N];

int on_cycle(int x) {
	if (vis_cyc[x] == 1) {
		return x;
	}

	if (vis_cyc[x] == 2) return -1;

	vis_cyc[x] = 1;

	int ans = on_cycle(next_[x]);

	vis_cyc[x] = 2;
	return ans;
}

int main() {
    _upgrade;
	int n;
	cin >> n; 

	For (i, n + 1) node_ans[i] = INF;

	For (i, n) cin >> cost[i + 1];
	For (i, n) {
		cin >> next_[i + 1];
	}

	// int curr_col = 1;

	ll sum = 0;
	
	for (int i = 1; i <= n; i++) {
		if (!vis_cyc[i]) {
			int start_from = on_cycle(i);
			// error(i, start_from);

			if (start_from != -1 && !vis[start_from]) {
				int aa = dfs_cycle(start_from);
				// error(aa);
				sum += aa;
				// ans_for_color[res.first] = min(ans_for_color[res.first], res.second);
				
				// error(res.first, res.second, i);
				
				// if (res.first == curr_col) curr_col++;
			}
		}
	}

	// ll sum = 0;
	// For (i, curr_col) 
	// 	if (ans_for_color[i] != INF)
	// 		sum += ans_for_color[i];

	cout << sum << "\n";
}

