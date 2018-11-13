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

const int N = 3 * 100 * 1000 + 10;
pii scores[N];
pii edges[N];
ll ans[N];

ll sum_pref_snd[N];

int main() {
    _upgrade;
	int n, m;
	cin >> n >> m;

	For (i, n) cin >> scores[i].first >> scores[i].second;
	For (i, m) cin >> edges[i].first >> edges[i].second;

	vector<pair<ll, int>> diffs;
	
	For (i, n) {
		diffs.push_back({scores[i].first - scores[i].second, i});
	}
	
	SORT(diffs);
	sum_pref_snd[n] = 0;

	ForD(i, n)  {
		sum_pref_snd[i] = sum_pref_snd[i + 1] + scores[diffs[i].second].second;
	}

	// For (i, n) 
	// 	cout << sum_pref_snd[i] << " ";
	// cout << endl;

	ll fst_sum = 0;
	For (i, n) {
		int x = diffs[i].second;
		ans[x] = fst_sum + (ll)scores[x].second * i + (ll)scores[x].first * (n - i - 1) + sum_pref_snd[i + 1];
		// error(x, ans[x]);
		fst_sum += scores[x].first;
	}

	For (i, m) {
		int x = edges[i].first;
		int y = edges[i].second;
		x--; y--;

		int a = scores[x].first;
		int b = scores[x].second;

		int p = scores[y].first;
		int q = scores[y].second;

		ll score = min((ll)a + q, (ll)b + p);

		// error(x, y, score);
		ans[x] -= score;
		ans[y] -= score;
	}

	For (i, n) cout << ans[i] << " "; 
}

