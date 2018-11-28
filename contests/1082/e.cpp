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

const int N = 5 * 100 * 1000 + 10;
vector<int> pos[N];
int sum_pref[N];

int best = 0;
int total_c = 0;

int get_cnt(int p, int q) {
	if (q < 0) return 0;
	return sum_pref[q] - (p > 0 ? sum_pref[p - 1] : 0);
}

int main() {
    // _upgrade;
	int n, c;
	cin >> n >> c;

	For (i, n) {
		int x; 
		cin >> x;
		pos[x].push_back(i);
		if (x == c) {
			sum_pref[i] += 1;
			total_c++;
		}
	}

	best = total_c;

	For (i, n) {
		if (i > 0) {
			sum_pref[i] += sum_pref[i - 1];
		}
	}

	For (i, N) {
		if (i == c) continue;
		int most_min = 0;

		For (j, (int)pos[i].size()) {
			most_min = min(most_min, j - get_cnt(0, pos[i][j] - 1));

			int curr = j + 1 - get_cnt(0, pos[i][j]);
			most_min = min(most_min, curr);

			// error(i, most_min, curr);

			best = max(best, total_c + curr - most_min);
		}
	}

	cout << best << "\n";
}

