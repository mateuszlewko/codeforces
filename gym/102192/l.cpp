#include <bits/stdc++.h> 

using namespace std;

#define For(i, n) for (int i = 0; i < int(n); i++)
#define ForD(i, n) for (int i = int(n) - 1; i >= 0; i--)

#define _upgrade do { ios::sync_with_stdio(0); cin.tie(0); } while (0)

typedef long long ll;
typedef pair<ll, ll> pll;

const int N = 50 * 1000 + 10;
ll C[N], D[N], M[N], P[N];
ll e_cap[N], E[N], R[N];

ll mat_cost[N];
const ll INF = 1LL<<40;

void solve() {
	int k;
	cin >> k;

	For (i, k + 1) mat_cost[i] = 0;

	For (i, k) cin >> C[i] >> D[i] >> M[i] >> P[i];
	For (i, k - 1) cin >> e_cap[i] >> R[i] >> E[i];

	For (i, k) mat_cost[i] = min(C[i], i > 0 ? mat_cost[i - 1] + R[i - 1] : INF);
	
	// (cost, cnt)
	multiset<pll> S;
	ll add_s = 0;
	ll s_count = 0;
	
	ll total_cost = 0;

	For (i, k) {
		ll curr_cost = mat_cost[i] + M[i];
		s_count += P[i];
		S.insert({curr_cost - add_s, P[i]});

		ll taken = 0;
		while (S.size() && taken < D[i]) {
			auto cc = *S.begin();
			S.erase(S.begin());

			ll cost = cc.first + add_s;
			ll cnt = cc.second;

			ll take = min(D[i] - taken, cnt);
			taken += take;
			s_count -= take;
			
			cnt -= take;
			total_cost += take * cost;

			if (cnt > 0) S.insert({cc.first, cnt});
		}

		if (taken < D[i]) {
			cout << "-1\n";
			return;
		}

		if (i != k - 1) {
			add_s += E[i];

			while (s_count > e_cap[i]) {
				auto cc = *S.rbegin();
				S.erase(prev(S.end()));

				ll cnt = cc.second;
				ll rem = min(cnt, s_count - e_cap[i]);
				s_count -= rem;
				cnt -= rem;

				if (cnt > 0) S.insert({cc.first, cnt});
			}
		}
	}

	cout << total_cost << "\n";
}

int main() {
	_upgrade;

	int t;
	cin >> t;
	
	while (t--) solve();
}

