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


#define ft first
#define sd second

const int N = 300 * 1000 + 10;
ll dist[N];
int pred[N];
vector<pair<int, ll>> G[N];

struct qCmp
{
    inline bool operator()(const int &lhs, const int &rhs) const
    {
        if (dist[lhs] != dist[rhs])
            return dist[lhs] < dist[rhs];
        return lhs < rhs;
    }
};

void dijkstra(int x, int n)
{
    set<int, qCmp> Q;
	for (int i = 1; i <= n; i++) 
		dist[i] = 1LL<<60;

    dist[x] = 0;
    Q.insert(x);

    while (Q.size())
    {
        int u = *Q.begin();
        Q.erase(Q.begin());

        for (auto v : G[u])
        {
            if (dist[v.ft] > dist[u] + v.sd)
            {
                auto it = Q.find(v.ft);
                if (it != Q.end())
                    Q.erase(it);

                dist[v.ft] = dist[u] + v.sd;
				pred[v.ft] = u;
                Q.insert(v.ft);
            }
        }
    }
}

vector<int> short_g[N];

set<pair<int, int>> good_edges;
int deg[N];

int to_remove;
void dfs_remove(int x, int p) {
	if (to_remove <= 0) return;

	for (int y : short_g[x]) {
		if (y != p)
			dfs_remove(y, x);
	}

	if (to_remove > 0) {
		to_remove--;
		good_edges.erase({min(x, p), max(x, p)});
	}
}

// void top_sort(int n, int to_remove) {
// 	if (to_remove <= 0) return;

// 	queue<int> leafs;
// 	for (int i = 1; i <= n; i++) {
// 		for (int y : short_g[i]) {
// 			deg[y]++;
// 		}
// 	}

// 	for (int i = 2; i <= n; i++) { 
// 		// error(i, deg[i]);
// 		if (deg[i] == 1) {
// 			leafs.push(i);
// 		}
// 	}

// 	// error(leafs.size());

// 	while (to_remove > 0 && leafs.size()) {
// 		int x = leafs.front();
// 		leafs.pop();
// 		deg[x]--;

// 		for (int y : short_g[x]) {
// 			deg[y]--;
// 			good_edges.erase({min(x, y), max(x, y)});
// 			// error("removing", min(x, y), max(x, y));
// 			to_remove--;
// 			if (to_remove == 0) return;
// 			if (deg[y] == 1 && y != 1) leafs.push(y);
// 		}
// 	}
// }

map<pair<int, int>, int> edge_num;

int main() {
    _upgrade;
	int n, m, k;
	cin >> n >> m >> k;

	if (k == 0) {
		cout << "0\n";
		return 0;
	}

	For (i, m) {
		int a, b;
		ll c;
		cin >> a >> b >> c;
		G[a].push_back({b, c});
		G[b].push_back({a, c});
		edge_num[{min(a, b), max(a, b)}] = i + 1;
	}

	dijkstra(1, n);

	for (int i = 1; i <= n; i++) {
		if (pred[i] != 0) {
			short_g[i].push_back(pred[i]);
			short_g[pred[i]].push_back(i);
			good_edges.insert({min(i, pred[i]), max(i, pred[i])});
		}
	}

	// for (auto e : good_edges) {
	// 	error(e.ft, e.sd);
	// }

	// top_sort(n, (int)good_edges.size() - k);
	to_remove = (int)good_edges.size() - k;
	dfs_remove(1, -1);

	cout << good_edges.size() << "\n";
	vector<int> nums;
	for (auto it : good_edges) {
		nums.push_back(edge_num[it]);
	}

	SORT(nums);
	for (int x : nums) {
		cout << x << " ";
	}
}

