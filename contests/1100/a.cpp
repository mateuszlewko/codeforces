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

int A[120];

int main() {
    _upgrade;

	int n, k;
	cin >> n >> k;

	int tot_pos = 0;
	int tot_neg = 0;

	For (i, n) {
		cin >> A[i];

		if (A[i] > 0) tot_pos++;
		else tot_neg++;
	}

	int best = 0;
	For (i, n) {
		int pos = 0;
		int neg = 0;
		for (int j = i; j < n; j += k) {
			if (A[j] < 0) neg++;
			else pos++;
		}

		for (int j = i - k; j >= 0; j -= k) {
			if (A[j] < 0) neg++;
			else pos++;
		}

		pos = tot_pos - pos;
		neg = tot_neg - neg;

		best = max(best, abs(pos - neg));
	}

	cout << best << "\n";
}

