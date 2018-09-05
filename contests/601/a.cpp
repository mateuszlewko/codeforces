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

const int N = 410;
bool conn[N][N];
int dist[N];
bool vis[N];

vector<int> G[N];

int bfs(int x, int n) {
	queue<int> q; 
	q.push(x);

	For (i, n + 1) dist[i] = 1<<30;

	dist[x] = 0;
	vis[x] = true;

	while (q.size()) {
		int front = q.front();
		q.pop();

		for (int y : G[front]) {
			if (!vis[y]) {
				q.push(y);
				dist[y] = min(dist[y], dist[front] + 1);
				vis[y] = true;
			}
		}		
	}

	return dist[n];	
}

int main() {
    _upgrade;
	int n, m;
	cin >> n >> m;

	bool was_n = false;

	For (i, m) {
		int a, b; 
		cin >> a >> b;

		conn[a][b] = conn[b][a] = true;
		if (min(a, b) == 1 && max(a, b) == n) was_n = true;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (was_n != conn[i][j]) {
				G[i].push_back(j);
				G[j].push_back(i);
			}
		}
	}

	int res = bfs(1, n);
	cout << (res == (1<<30) ? -1 : res) << "\n";
}

