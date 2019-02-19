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

int A[110];
const int N = 100;

int main() {
    _upgrade;

	int n;
	ll sum = 0;
	cin >> n;

	For (i, n) {
		int x;
		cin >> x;
		A[x]++;
		sum += x;
	}

	ll best = sum;

	for (ll i = 1; i <= N; i++) {
		for (ll j = 1; j <= N; j++) {
			if (i == j || A[i] == 0 || A[j] == 0) continue;

			for (ll k = 2; k * k <= i; k++) {
				if (i % k != 0) continue;

				best = min(best, sum - (i - i/k) + (j * k - j));
			}
		}
	}

	cout << best << "\n";
}

