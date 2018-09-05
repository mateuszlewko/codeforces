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
	int n;
	string a, b;
	cin >> n >> a >> b;

	int res = 0;

	For (i, (int)a.size()) {
		if (a[i] != b[i]) {
			// error(i, a[i+1], a[i], b[i+1]);

			if (i < n - 1 && a[i + 1] != b[i+1] && a[i + 1] == b[i] && a[i] == b[i + 1]) {
				swap(a[i], a[i + 1]);
				// cout << "HERE1";
				res++;
			// } else if (i < n - 2 && a[i + 2] != b[i + 2] && a[i + 2] == b[i] && a[i] == b[i + 2]) {
			// 	swap(a[i], a[i + 2]);
			// 	// cout << "HERE2";
			// 	res += 2;
			} else {
				a[i] = b[i];
				res++;
			}

			// error(res, a);
		}
	}

	cout << res << "\n";
}

