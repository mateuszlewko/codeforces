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

int main() {
    _upgrade;

	int xs[2][4] = {};
	int xl[2][4] = {};
	int s[2] = {};
	int m[2] = {};
	int l[2] = {};

	int n;
	cin >> n; 

	For (j, 2)
		For (i, n) {
			string ss;
			cin >> ss;
			if (ss.size() == 1) {
				if (ss[0] == 'S') s[j]++;
				else if (ss[0] == 'M') m[j]++;
				else l[j]++;
			} 
			else {
				int cnt = (int)ss.size(); 

				if (ss.back() == 'L') xl[j][cnt - 1]++;
				else if (ss.back() == 'S') xs[j][cnt - 1]++;
			}
		}

	int res = 0;
	For (i, 4) 
		res += abs(xs[0][i] - xs[1][i]);

	// error(res);

	int cnt1 = 0; 
	cnt1 += abs(s[0] - s[1]);
	cnt1 += abs(m[0] - m[1]);
	cnt1 += abs(l[0] - l[1]);

	// error(res, cnt1);

	cout << res + (cnt1 / 2) << "\n";
}

