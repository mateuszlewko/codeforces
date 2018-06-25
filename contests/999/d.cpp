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

const int M = 2 * 100 * 1000 + 10;
vector<int> mods[M];
int added[M];
ll nums[M];

int main() {
    // _upgrade;
	int n, m;
	scanf("%d %d", &n, &m);

	For (i, n) {
		int a;
		scanf("%d", &a);
		nums[i] = a;
		mods[a % m].push_back(i);
	}

	int expected = n / m;

	priority_queue<pair<int, int>> Q;
	
	For (i, m) {
		while ((int)mods[i].size() > expected) {
			Q.push({i, mods[i].back()});
			mods[i].pop_back();
		}
	}

	ll res = 0;

	For (i, m) {
		int cnt = expected - (int)mods[i].size();
		while (cnt--) {
			auto [mod_i, pos] = Q.top();
			Q.pop();
			int to_add = i < mod_i ? i + m - mod_i : i - mod_i;
			// error(i, m, mod_i, pos, to_add);
			// printf("adding: %d, to: %d\n", to_add, pos);

			res += to_add;
			added[pos] = to_add;
		}
	}

	printf("%lld\n", res);
	For (i, n)
		printf("%lld ", nums[i] + added[i]);
}

