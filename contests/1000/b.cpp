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
// int even_end[N];
// int odd_end[N];
int even_beg[N];
int odd_beg[N];

int main() {
    // _upgrade;

	int n, m;
	scanf("%d %d", &n, &m);

	unordered_set<int> taken;
	vector<int> pos(n + 1); 


	For (i, n) {
		scanf("%d", &pos[i]);
		taken.insert(pos[i]);
	}

	pos[n] = m;

	vector<pair<int, int>> test_vals; 

	For (i, pos.size()) {
		int p = pos[i]; 

		if (p - 1 > 0 && taken.find(p - 1) == end(taken)) 
			test_vals.push_back({p - 1, i});
		if (p + 1 < m && taken.find(p + 1) == end(taken))
			test_vals.push_back({p + 1, i + 1});
	}

	vector<int> diffs;
	diffs.push_back(pos[0]);

	For (i, n) {
		diffs.push_back(pos[i + 1] - pos[i]);
	}

	diffs.push_back(0);

	// For (i, diffs.size()) 
	// 	cout << diffs[i] << ", ";
	// cout << "\n";

	int max_odd = 0, max_even = 0;

	For (i, diffs.size() / 2) {
		even_beg[i * 2 + 2] = even_beg[i * 2] + diffs[i * 2];
		max_even = max(max_even, even_beg[i * 2 + 2]);

		odd_beg[i * 2 + 3] = odd_beg[i * 2 + 1] + diffs[i * 2 + 1];
		max_odd = max(max_odd, odd_beg[i * 2 + 3]);
	}

	// For (i, diffs.size() + 1) 
	// 	cout << even_beg[i] << ", ";
	// cout << "\n";
	
	// For (i, diffs.size() + 3) 
	// 	cout << odd_beg[i] << ", ";
	// cout << "\n";

	int best = max_even;

	for (auto p_val : test_vals) {
		int val = p_val.first;
		int next_i = p_val.second;

		if (next_i % 2 == 0) {
			int res = even_beg[next_i + 2] - (pos[next_i] - val);
			res += max_odd - odd_beg[next_i + 1];
			best = max(best, res);
		}
		else {
			int res = even_beg[next_i + 1] + (pos[next_i] - val);
			res += max_odd - odd_beg[next_i + 2];
			best = max(best, res);
		}
	}

	printf("%d\n", best);
}

