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
int deg[N];
vector<int> layers[N];
int layer[N];
vector<int> G[N];

bool bfs(int n) {
	queue<int> Q;

	for (int i = 1; i <= n; i++) {
		if (deg[i] == 1) {
			Q.push(i);
			deg[i]--;
			layers[0].push_back(i);
			layer[i] = 0;
		}
	}

	while (Q.size()) {
		int front = Q.front();
		error(front);
		Q.pop();

		for (int y : G[front]) {
			deg[y]--;
			if (deg[y] == 1) {
				deg[y]--;
				if (layer[y] != 0) return false;
				layer[y] = layer[front] + 1;
				error(y, layer[y]);
				layers[layer[y]].push_back(y);
				Q.push(y);
			}
		}
	}

	return true;
}

bool check(int n, int k) {
	for (int x : layers[0]) {
		if (G[x].size() != 1) { 
			error(x, G[x].size());
			return false;
		}
	}

	int l = 1;
	while (layers[l].size()) {
		for (int x : layers[l]) {
			int cnt = 0;
			for (int y : G[x]) {
				if (layer[y] == layer[x] - 1) cnt++;
				// else if (layer[y] != layer[x] + 1) return false;
			}

			if (cnt < 3) {
				error(cnt, x, l);
				return false;
			}
		}

		l++;
	}

	if (l < 2) { 
		error(l);
		return false;
	}
	if (layers[l - 1].size() != 1) {
		error(l-1, layers[l-1].size());
		return false;
	}

	For (i, n) {
		int x = i + 1;
		for (int y : G[x]) {
			if (layer[x] == layer[y]) return false;
		}
	}

	For (i, n) if (deg[i + 1] != 0) {
		error(deg[i+1], i+1);
		return false;
	}

	error(k, l);
	return k == l - 1;
}

int main() {
    _upgrade;
	int n;
	int k;

	cin >> n >> k;

	For (i, n - 1) {
		int a, b;
		cin >> a >> b;

		G[a].push_back(b);
		G[b].push_back(a);

		deg[a]++;
		deg[b]++;
	}

	if (bfs(n) && check(n, k)) cout << "Yes\n";
	else cout << "No\n";
}

