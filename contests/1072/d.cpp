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

const int N = 2010;
string A[N];
int left_dist[N][N];

vector<pii> go(int k, int n) {
	left_dist[0][0] = k;
	if (A[0][0] == 'a') left_dist[0][0] += 1;

	vector<pii> res;
	if (left_dist[0][0] == 0) res.push_back({0, 0});

	For (i, n) {
		For (j, n) {
			if (i == 0 && j == 0) continue;
			int up = i > 0 ? left_dist[i - 1][j] : 0;
			int left = j > 0 ? left_dist[i][j - 1] : 0;
			left_dist[i][j] = max(left, up) - 1;
			if (A[i][j] == 'a') left_dist[i][j] += 1;

			error(i, j, left_dist[i][j]);
			if ((up > 0 || left > 0) && left_dist[i][j] == 0) {
				res.push_back({i, j});
			}
		}
	}

	return res;
}

pii prevs[N][N];

vector<pii> get_best(vector<pii> ps) {
	sort(ps.begin(), ps.end(), [&](auto l, auto r) {
		if (l.first + l.second != r.first + r.second) {
			return l.first + l.second > r.first + r.second;
		}
		return A[l.first][l.second] < A[r.first][r.second];
	});

	while (ps.size() && 
			(A[ps.back().first][ps.back().second] != A[ps[0].first][ps[0].second] || 
			 ps.back().first + ps.back().second != ps[0].first + ps[0].second)) {
		ps.pop_back();		
	}

	return ps;
}

void ending(vector<pii> ps, int n) {
	// for (auto p : ps) {
	// 	error(p.first, p.second);
	// }
	// cout << "\n";

	while (ps.size()) {
		vector<pii> new_ps;
		for (auto p : ps) {
			if (p.first + 1 < n && (p.second + 1 >= n || A[p.first + 1][p.second] <= A[p.first][p.second + 1])) {
				prevs[p.first + 1][p.second] = p;
				new_ps.push_back({p.first + 1, p.second});
			}
			if (p.second + 1 < n && (p.first + 1 >= n || A[p.first][p.second + 1] <= A[p.first + 1][p.second])) {
				prevs[p.first][p.second + 1] = p;
				new_ps.push_back({p.first, p.second + 1});
			}
		}

		SORT(new_ps);
		vector<pii> new_ps2;
		For (i, ps.size()) {
			if (i == 0 || ps[i - 1] != ps[i]) new_ps2.push_back(ps[i]);
		}
		ps = get_best(new_ps2);
		// for (auto p : new_ps) {
		// 	error(p.first, p.second);
		// }
		// cout << "\n";
	}
}

int main() {
    _upgrade;
	int n, k;
	cin >> n >> k;

	For (i, n) {
		cin >> A[i];
	}

	auto ps = go(k, n);

	if (ps.empty()) {
		For (i, 2 * n - 1) cout << "a";
		cout << "\n";
	} else {
		For (i, n) For (j, n) prevs[i][j] = {-1, -1};
		ending(get_best(ps), n);
		vector<char> suff;
		pii curr = {n - 1, n - 1};

		while (curr != make_pair(-1, -1)) {
			suff.push_back(A[curr.first][curr.second]);
			curr = prevs[curr.first][curr.second];
		}

		for (int i = 0; i < 2 * n - 1 - (int)suff.size(); i++) {
			cout << "a";
		}
		ForD (i, suff.size()) {
			cout << suff[i];
		}
		cout << "\n";
	}
}

