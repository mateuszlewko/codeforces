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

pii edges[N];
int degree[N];
unordered_set<int> G[N];
int ans[N];

int main() {
    _upgrade;

	int n, m, k;
	cin >> n >> m >> k; 

	For (i, m) {
		cin >> edges[i].first >> edges[i].second;

		G[edges[i].first].insert(edges[i].second);
		G[edges[i].second].insert(edges[i].first);

		degree[edges[i].first]++;
		degree[edges[i].second]++;
	}

	set<pii> Q;

	For (i, n) {
		Q.insert({degree[i + 1], i + 1});
	}

	auto normalize = [&]() {
		while (Q.size() && (*Q.begin()).first < k) {
			auto beg = Q.begin();
			int x = (*beg).second;
			Q.erase(beg);

			error(x);

			for (int y : G[x]) {
				auto it = Q.find({degree[y], y});
				if (it == Q.end()) continue;

				Q.erase(it);
				Q.insert({--degree[y], y});
				error(degree[y], y);
			}
		}
	};

	normalize();

	ans[m - 1] = Q.size();

	for (int i = m - 1; i >= 1; i--) {
		auto a = Q.find({degree[edges[i].first], edges[i].first});
		auto b = Q.find({degree[edges[i].second], edges[i].second});

		if (a != Q.end() && b != Q.end()) {
			error(edges[i].first, degree[edges[i].first], edges[i].second,
			      degree[edges[i].second]);

			Q.erase(a);
			Q.erase(b);
			Q.insert({--degree[edges[i].first], edges[i].first});
			Q.insert({--degree[edges[i].second], edges[i].second});
			
			G[edges[i].first].erase(edges[i].second);
			G[edges[i].second].erase(edges[i].first);

			normalize();
		}

		ans[i - 1] = Q.size();
	}

	For (i, m) 
		cout << ans[i] << "\n";
}

