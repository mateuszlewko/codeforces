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

int best = 0;
int n;

string s;
void go(int ix, int s_cnt, int g_cnt, int last_g, int groups_cnt, int dir) {
	if (ix >= n || ix < 0) return;


	if (s[ix] == 'S') s_cnt++;
	else {
		g_cnt++;
		s_cnt = 0;
	}

	// error(ix, s_cnt, g_cnt, last_g, groups_cnt, best);

	if (s_cnt == 1) {
		go(ix + dir, s_cnt, 0, g_cnt, groups_cnt + (g_cnt > 0 ? 1 : 0), dir);
	} else if (s_cnt >= 2) {
		go(ix + dir, s_cnt, 0, 0, groups_cnt, dir);
	} else {
		if (groups_cnt > 1) {
			best = max(best, g_cnt + last_g + 1);
		} else best = max(best, g_cnt + last_g);

		go(ix + dir, 0, g_cnt, last_g, groups_cnt, dir);
	}
}

int main() {
    _upgrade;

	cin >> n;
	cin >> s;

	go(0, 0, 0, 0, 0, 1);
	// error(best);
	go(n - 1, 0, 0, 0, 0, -1);
	// error(best);
	
	cout << best << "\n";
}

