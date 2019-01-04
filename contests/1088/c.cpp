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

const int N = 2002;
ll A[N];

int main() {
    _upgrade;
	int n;	
	cin >> n;

	int M = 10000;

	For (i, n) {
		cin >> A[i];
		A[i] += M;
	}

	// cout << n + 1 << "\n";

	vector<pair<int, pii>> ops;

	ops.push_back({1, {n, M}});
	// cout << "1 " << n << " " << M << "\n";

	For (i, n) {
		// error(A[i], i+1);
		if (A[i] > i + 1) {
			ll mod = A[i] - (i + 1);
			// error(A[i], mod);

			// cout << "1 " << i + 1 << " " << mod << "\n";
			ops.push_back({2, {i + 1, mod}});
			For (j, i + 1) {
				A[j] %= mod;
			}

			// error(A[i], "mod");
		} else if (A[i] < i + 1) {
			ll add = i + 1 - A[i];
			ops.push_back({1, {i + 1, add}});
			For (j, i + 1) {
				A[j] += add;
			}
			
			// error(A[i], "add");
		} 

	}

	For (i, n - 1) {
		if (A[i + 1] <= A[i]) {
			// For (j, n) {
			// 	cout << A[j] << " ";
				
			// }
			return 11;
		}
	}

	cout << ops.size() << "\n";
	for (auto o : ops) {
		cout << o.first << " " << o.second.first << " " << o.second.second << "\n";
	}
}

