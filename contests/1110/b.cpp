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
int A[N];
// int last_true = 0;

// bool check(int len, int n, int k) {
// 	int used = 0;
// 	int next = 0;

// 	while (true) {
// 		int pos = lower_bound(A, A + n, next) - A;
// 		if (pos == n) break;	

// 		next = A[pos] + len;
// 		used++;
// 		// error(next);
// 	}

// 	return used <= k;
// }

int main() {
    _upgrade;

	int n, m, k;
	cin >> n >> m >> k;

	vector<int> dists;
	For (i, n) {
		cin >> A[i];
		if (i > 0) {
			dists.push_back(A[i] - A[i - 1]);
		}
	}

	SORT(dists);

	ll res = 0;
	For (i, max(0, n - k)) {
		res += dists[i] - 1;
	}

	res += n;
	cout << res << "\n";



	// int beg = 0; 
	// int end = m;

	// while (beg != end - 1) {
	// 	int mid = (beg + end) / 2;

	// 	if (check(mid, n, k)) {
	// 		end = mid;
	// 	} else {
	// 		beg = mid;
	// 	}
	// }

	// cout << end << "\n";
}

