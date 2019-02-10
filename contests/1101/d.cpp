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
vector<int> G[N];

int A[N];

vector<int> primes() {
	vector<int> res;
	res.push_back(2);

	for (int i = 3; i * i <= N; i++) {
		bool any = false;
		for (int x : res) {
			if (i % x == 0) { any = true; break; }
		}

		if (!any) res.push_back(i);
	}

	return res;
}

int best_ans = 0;

int go_div(int x, int p, int div, int cnt_above) {
	vector<int> cnt_below;

	if (A[x] % div == 0) {
		cnt_above++;
	} else { 
		cnt_above = 0;
	}

	for (int y : G[x]){
		if (y == p) continue;
		// error(x, y, cnt_above);
		cnt_below.push_back(go_div(y, x, div, cnt_above));
		// error(y, cnt_above);
	}

	SORT(cnt_below);

	int be = cnt_below.size() ? cnt_below.back() : 0;
	best_ans = max(cnt_above + be, best_ans);
	// error(x, div, best_ans, cnt_above, be);
	if (cnt_below.size() >= 2 && A[x] % div == 0) {
		best_ans = max(best_ans, cnt_below[cnt_below.size() - 1] + cnt_below[cnt_below.size() - 2] + 1);
	}

	return A[x] % div == 0 ? be + 1 : 0;
}

int go_same(int x, int p, int val, int cnt_above) {
	vector<int> cnt_below;

	if (A[x] == val) {
		cnt_above++;
	} else cnt_above = 1;

	if (A[x] == 1) cnt_above = 0;
  else best_ans = max(best_ans, cnt_above);

	for (int y : G[x]){
		if (y == p) continue;
		int c = go_same(y, x, A[x], cnt_above);
		if (A[y] == val && val != 1) cnt_below.push_back(c);
	}

	SORT(cnt_below);

	int be = cnt_below.size() ? cnt_below.back() : 0;
	if (val != 1) best_ans = max(cnt_above + be, best_ans);

	if (cnt_below.size() >= 2 && val != 1) {
		best_ans = max(best_ans, cnt_below[cnt_below.size() - 1] + cnt_below[cnt_below.size() - 2] + 1);
	}

	return (A[x] == val && val != 1) ? be + 1 : 0;	
}

int main() {
    _upgrade;

	int n;
	cin >> n;
	For (i, n) {
		cin >> A[i + 1];
	}

	For (i, n - 1) {
		int x, y;
		cin >> x >> y;

		G[x].push_back(y);
		G[y].push_back(x);
	}

	auto ps = primes();
	for (int p : ps) {
		best_ans = max(best_ans, go_div(1, -1, p, 0));
	}

	error(best_ans);

	best_ans = max(best_ans, go_same(1, -1, -1, 0));
	
	cout << best_ans << "\n";
}

