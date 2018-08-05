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
int nums[N];
bool vis_l[N];
bool vis_r[N];
int pref_l[N];
// int pref_r[N];

int main() {
    // _upgrade;
	int n;
	scanf("%d", &n); 

	For (i, n) scanf("%d", &nums[i]);
	
	For (i, n) {
		int add = vis_l[nums[i]] == false;
		vis_l[nums[i]] = true;
		pref_l[i + 1] = pref_l[i] + add;
	}

	ll res = 0;

	ForD (i, n) {
		int add = vis_r[nums[i]] == false;
		vis_r[nums[i]] = true;
		// pref_r[i] = pref_r[i + 1] + add;

		if (add) {
			res += pref_l[i];
		}
	}

	// For (i, n + 1) {
	// 	printf("%d ", pref_l[i]);
	// }
	// puts("");
	// For (i, n + 1) {
	// 	printf("%d ", pref_r[i]);
	// }

	printf("%lld\n", res);

	// ll res = 0;
	// For (i, n) {
	// 	res += (ll)pref_l[i + 1] * (ll)pref_r[i + 2];
	// }
}

