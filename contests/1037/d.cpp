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
int parent[N];

vector<int> G[N];
int dist[N];

void dfs(int x, int p, int d) {
	dist[x] = d;
	parent[x] = p;

	for (int child : G[x]) {
		if (child != p) {
			dfs(child, x, d + 1);
		}
	}
}

int parent_pos[N];
int ord[N];
bool used[N];

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

	dfs(1, 0, 0); 
	int max_dist = 0;
	int max_parent_pos = 0;
	
	bool wrong = false;

	For (i, n) parent_pos[i] = 0;

	For (i, n) {
		cin >> ord[i];
		parent_pos[ord[i]] = i;

		if (dist[ord[i]] < max_dist || dist[ord[i]] > max_dist + 1 || 
		    used[parent[ord[i]]] || parent_pos[parent[ord[i]]] < max_parent_pos) {
			wrong = true;
			break;
		}

		max_parent_pos = max(max_parent_pos, parent_pos[parent[ord[i]]]);

		max_dist = max(max_dist, dist[ord[i]]);
		if (i > 0 && parent[ord[i]] != parent[ord[i - 1]])
			used[parent[ord[i - 1]]] = true;
	}

	if (ord[0] != 1) wrong = true;

	cout << (wrong ? "No\n" : "Yes\n");
}

