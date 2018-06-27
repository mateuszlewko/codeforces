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
ll real_ans[N];

int main() {
    // _upgrade;
	int n; 
	scanf("%d", &n);

	map<ll, ll> open, close, ans;

	For (i, n) {
		ll a, b; 
		scanf("%lld %lld", &a, &b);
		open[a]++;
		close[b + 1LL]--;
	}

	vector<pair<ll, ll>> vs;
	for (auto kv : open) {
		vs.push_back(kv);
	}
	
	for (auto kv : close) {
		vs.push_back(kv);
	}

	SORT(vs);

	ll curr = 0;
	For (i, vs.size()) {
		// error(vs[i].first);
		// error(vs[i].second);

		curr += vs[i].second;
		if (i < (int)vs.size() - 1 && vs[i].first == vs[i + 1].first) {
			i++;
			curr += vs[i].second;
		}

		// error(curr);
		ans[vs[i].first] = curr;
	}

	for (auto it = ans.begin(); it != end(ans); it++) {
		auto next_it = it; 
		next_it++;

		// error(it->second);

		if (next_it != end(ans)) {
			real_ans[it->second] += next_it->first - it->first;
		}
	}

	For (i, n)
		printf("%lld ", real_ans[i + 1]);	
	puts("");
}

