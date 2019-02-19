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

const int N = 3 * 100 * 1000;
int A[N];

int main() {
    _upgrade;
	int n;

	cin >> n;

	For (i, n) {
		int x;
		cin >> x;
		A[i + 1] = A[i] ^ x;
	}

	unordered_map<int, int> even, odd;
	if (n % 2 == 0) even[A[n]]++;
	else odd[A[n]]++;

	ll res = 0;
	ForD (i, n) {
		if (i % 2 == 0) {
			res += even[A[i]];
		} else {
			res += odd[A[i]];
		}

		if (i % 2 == 0) even[A[i]]++;
		else odd[A[i]]++;
	}

	cout << res << "\n";
}

