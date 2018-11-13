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
ll A[N];
bool state[N];

int main() {
    _upgrade;
	int n, m;
	ll l;
	cin >> n >> m >> l;

	int res = 0;
	For (i, n) {
		cin >> A[i];
		if (A[i] > l) {
			if (i == 0 || !state[i - 1]) res++;
			state[i] = true;
		}
	}

	For (i, m) {
		bool t;
		cin >> t;

		if (!t) {
			cout << res << "\n";
		} else {
			int p, d;
			cin >> p >> d;
			p--;

			bool orig = state[p];
			A[p] += d;
			state[p] = A[p] > l;

			if (state[p] && !orig) {
				if (p > 0 && p < n - 1 && state[p - 1] && state[p + 1]) 
					res--;
				else if ((p > 0 && state[p - 1]) || (p < n - 1 && state[p + 1])) {
					// nic
				} else {
					res++;
				}
			}
		}
	}
}

