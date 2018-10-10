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

vector<ll> tree_sum;
const int N = 100 * 1000 + 10;
vector<int> G[N];
ll W[N];
ll S;
int L;

int res;

pll go(int x) {
	tree_sum.push_back(tree_sum.back() + W[x]);

	ll bestSum = 1LL<<62;
	ll bestLen = 1LL<<30;
	ll bestIx = tree_sum.size();

	for (int y : G[x]) {
		auto p = go(y);
		
		ll left_sum = S - p.first;

		int ix = lower_bound(tree_sum.begin(), tree_sum.end(), tree_sum.back() - left_sum) - tree_sum.begin();
		ix = max(ix, (int)tree_sum.size() - (L - (int)p.second + 1));
		
		if (ix < bestIx) {
			bestIx = ix;
			bestSum = p.first + W[x];
			bestLen = p.second + 1;
		}
	}

	if (bestSum > S || bestLen > L) {
		res++;
		bestSum = W[x];
		bestLen = 1;

		if (bestSum > S) {
			cout << "-1\n";
			exit(0);
		}
	}

	tree_sum.pop_back();
	return {bestSum, bestLen};
}

int main() {
    _upgrade;

	int n;
	cin >> n >> L >> S;


	For (i, n) cin >> W[i + 1];

	for (int i = 2; i <= n; i++) {
		int x; 
		cin >> x;
		G[x].push_back(i);
	}

	tree_sum.push_back(0);
	go(1);

	cout << res;
}

