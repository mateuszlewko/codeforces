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

const int N = 2 * 100 * 1000;
int A[N];
bool wrong[N];

int main() {
    _upgrade;

	int n, m, k;
	cin >> n >> m >> k;

	vector<pii> small;
	ll sum = 0;
	For (i, n) {
		cin >> A[i];
		sum += A[i];
		small.push_back({A[i], i});
	}

	int left = n - m * k;
	SORT(small);

	For (i, left) {
		sum -= A[small[i].second];
		wrong[small[i].second] = true;
	}

	cout << sum << "\n";
	int cnt = 0;
	int res = 0;

	For (i, n) {
		if (!wrong[i]) cnt++;
		if (cnt == m && i != n - 1 && res != k - 1) {
			cout << i + 1 << " ";
			res++;
			cnt = 0;
		}
	}
}

