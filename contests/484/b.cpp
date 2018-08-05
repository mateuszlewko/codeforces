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
int v[N];

int main() {
    // _upgrade;

	int n;
	scanf("%d", &n); 

	// vector<int> v(n);

	For (i, n) scanf("%d", &v[i]);

	sort(v, v + n);

	int best = 0;

	ForD (index, n)	{
		int x = v[index];
		int last_pos = 0;
		if (best >= x - 1) break;

		for (int i = x; i <= v[n - 1] + x; i += x) {
			int pos = lower_bound(v + last_pos, v + n, i) - v;
			if (pos == 0) continue;
			last_pos = pos;

			if (best >= x - 1) break;

			// printf("i: %d, pos: %d, v[pos - 1]: %d, new_best: %d\n", i, pos, v[pos-1], x - (i - v[pos - 1]));
			if (v[pos - 1] < x) continue;
			best = max(best, x - (i - v[pos - 1]));

			i = max(i, v[pos] - (v[pos] % x) - x);
		}
	}

	printf("%d\n", best);
}