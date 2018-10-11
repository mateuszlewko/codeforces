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

const int N = 12;
pii pos_of[N * N];
int num[N][N];

typedef pair<int, pii> state;
map<state, vector<pair<pii, state>>> G;

enum Kind {
	Wie = 0,
	Kon = 1,
	Gon = 2
};

const int INF = 1<<30;

map<state, pii> dists;

void dijkstra(vector<state> from) {
	auto cmp = [](auto a, auto b) {
        pii dl = dists[a];
        pii dr = dists[b];

        if (dl.first != dr.first) return dl.first < dr.first; 
        else if (dl.second != dr.second) return dl.second < dr.second;
        else return a < b;
    };

    set<state, decltype(cmp)> S(cmp);

	for (auto s : from) {
		dists[s] = {0, 0};
		S.insert(s);
	}

	while (S.size()) {
		auto x = *S.begin();
		S.erase(S.begin());

		error(x.first, x.second.first, x.second.second);
		pii orig_dist = dists[x];
		error(orig_dist.first, orig_dist.second);

		for (auto y : G[x]) {
			pii new_dist = orig_dist;
			new_dist.first += y.first.first;
			new_dist.second += y.first.second;

			error(new_dist.first, new_dist.second);

			auto it = dists.find(y.second);

			if (it != dists.end()) {
				error(it->second.first, it->second.second);
			}

			if (it == dists.end() || it->second > new_dist) {
				auto eit = S.find(y.second);
				if (eit != S.end()) S.erase(eit);

				dists[y.second] = new_dist;
				S.insert(y.second);
			}
		}
	}
}

int main() {
    _upgrade;

	int n;
	cin >> n;

	For (i, n) {
		For (j, n) {
			cin >> num[i][j];
			pos_of[num[i][j]] = {i, j};
		}
	}

	for (int i = 1; i <= n * n; i++) 
		for (int j = 1; j <= n * n; j++)
			For (k, 3) {
				const state from = {k, {i, j}};
				const pii pos = pos_of[i];

				For (l, 3) {
					if (l != k)
						G[from].push_back({{1, 1}, {l, {i, j}}});
				}

				if (k == Wie) {
					For (l, n) {
						int next_num1 = num[l][pos.second];
						int next_num2 = num[pos.first][l];
						G[from].push_back({{1, 0}, {k, {next_num1, next_num1 == j + 1 ? j + 1 : j}}});
						G[from].push_back({{1, 0}, {k, {next_num2, next_num2 == j + 1 ? j + 1 : j}}});
					}
				} 

				if (k == Gon) {
					int curr_x = pos.first;
					int curr_y = pos.second;

					while (curr_x > 0 && curr_y > 0) {
						curr_x--;
						curr_y--;
						int next_num = num[curr_x][curr_y];
						G[from].push_back({{1, 0}, {k, {next_num, next_num == j + 1 ? j + 1 : j}}});
					}

					curr_x = pos.first;
					curr_y = pos.second;

					while (curr_x < n - 1 && curr_y < n - 1) {
						curr_x++;
						curr_y++;
						int next_num = num[curr_x][curr_y];
						G[from].push_back({{1, 0}, {k, {next_num, next_num == j + 1 ? j + 1 : j}}});
					}

					curr_x = pos.first;
					curr_y = pos.second;

					while (curr_x < n - 1 && curr_y > 0) {
						curr_x++;
						curr_y--;
						int next_num = num[curr_x][curr_y];
						G[from].push_back({{1, 0}, {k, {next_num, next_num == j + 1 ? j + 1 : j}}});
					}
					curr_x = pos.first;
					curr_y = pos.second;

					while (curr_x > 0 && curr_y < n - 1) {
						curr_x--;
						curr_y++;
						int next_num = num[curr_x][curr_y];
						G[from].push_back({{1, 0}, {k, {next_num, next_num == j + 1 ? j + 1 : j}}});
					}
				}					
				
				if (k == Kon) {
					for (int dx = -2; dx <= 2; dx++) {
						for (int dy = -2; dy <= 2; dy++) {
							if ((abs(dx) == 2 && abs(dy) == 1) || (abs(dx) == 1 && abs(dy) == 2)) {
								int curr_x = pos.first + dx;
								int curr_y = pos.second + dy;
								if (min(curr_x, curr_y) < 0 || max(curr_x, curr_y) >= n) continue;

								int next_num = num[curr_x][curr_y];
								G[from].push_back({{1, 0}, {k, {next_num, next_num == j + 1 ? j + 1 : j}}});
							}
						}
					}
				}
			}

	vector<state> froms;
	For (i, 3) {
		froms.push_back({i, {1, 1}});
	}
	dijkstra(froms);

	pii best = {INF, INF};
	For (i, 3) {
		For (j, n * n + 1) {
			auto it = dists.find({i, {n * n, n * n}});
			if (it != dists.end() && it->second < best) {
				best = it->second;
			}
		}
	}

	cout << best.first << " " << best.second;
}

