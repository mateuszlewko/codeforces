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

const int N = 110;
int A[N];

int main() {
    _upgrade;
	int n;
	cin >> n;

	int longest = 1;
	A[0] = 0;
	For (i, n) cin >> A[i + 1];
	A[n + 1] = 1001;
	n += 2;

	int curr = 1;
	for (int i = 1; i < n; i++) {
		if (A[i] == A[i - 1] + 1) {
			curr++;
		} else {
			longest = max(longest, curr);
			// error(longest, curr);
			curr = 1;
		}
	}

	longest = max(longest, curr);
	cout << max(0, longest - 2) << "\n";
}

