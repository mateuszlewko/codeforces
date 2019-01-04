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

const int N = 5 * 100 * 1000 + 10;
ll A[N];

int main() {
    _upgrade;

	int n;
	cin >> n;

	ll sum_l = 0;
	For (i, n) {
		cin >> A[i];
		sum_l += A[i];
	}

	ll odd = sum_l % 2LL;

	sort(A, A + n, greater<ll>());

	// For (i, n) {
	// 	cout << A[i] << " ";
	// } cout << endl;

	ll k = n + 1;

	ll sum_r = 0;
	ll sum_r2 = 0;
	// cout << "possible sums:\n";

	ll minAA = n;
	ll minBB = 0;

	ForD (i, n + 1) {
		// cout << "A: " << sum_r + k * (k - 1) - sum_l << "\n";
		// cout << "B: " << sum_r2 + (k - 1) * (k - 2) - sum_l << "\n";
		ll aa = sum_r + k * (k - 1LL) - sum_l;
		ll bb = sum_r2 + (k - 1LL) * (k - 2) - sum_l;

		minAA = min(minAA, aa);
		minBB = min(minBB, bb);

		k--;
		ll a = i > 0 ? A[i - 1] : 0;
		// error(a, m, k*(k-1), sum_l, sum_r);
		sum_l -= a;
		// m = min(m, min(k, a));
		sum_r += min(k, a);
		sum_r2 += min(k - 1, a);
	}

	minBB *= -1LL;
	vector<int> res;
	for (int i = minBB; i <= minAA; i++) {
		if (i % 2 == odd) res.push_back(i);
	}

	if (res.empty()) {
		cout << "-1\n";
		return 0;
	}

	for (int x : res) {
		cout << x << " ";
	}
	
}

